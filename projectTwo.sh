#!/bin/bash
#Project 2 Script, creates users based off a text file that contains emails. Sends email to the new users with passwords and account info

#checks if user is root
if [ $(id -u) -ne 0 ]
then
  echo "Must be root to user Colt's Shell Script!!"
  exit 1
fi

#a constant
unset INPUT_FILE

#Checks if the group CSI230 exists, if not create it
group="CSI230"
if grep -q $group /etc/group
then
  echo "CSI230 group already created. Continuing..."
else
  echo "Creating CSI230 group..."
  groupadd CSI230
  echo "Done..."
fi

#User input for email information to send the new passwords to the users
echo "Please enter email address:"
read EMAIL_ADDRESS
echo "Please enter email password:"
read -s EMAIL_PASSWORD

#usage error function
usage()
{
  echo "$0 usage: [-f input file]"
  exit 1
}

#Takes in the file during the commands call
while getopts 'f:' options
do
  case $options in
    f)
      INPUT_FILE=$OPTARG
      if test -f $INPUT_FILE; then
        echo "File Exists. Running Command"
      else
        usage
      fi
      ;;
  esac
done

#Iterate through the file, take usernames from email adresses based off data before "@".
#Searches if user exists
#If user exists, rest password and send email
#If not create new user, asign them to the group, give random password and send email
while read -r line
do
  ADDRESS=$(echo $line)
  USERNAME=$(echo $line | awk -F'@' '{print $1}')
  PASSWORD=$(openssl rand -base64 12)
  #PASSWORD="password"

  if id -u $USERNAME >/dev/null 2>&1; then
    echo "User already exists, sending password reset email"
    echo -e "$PASSWORD\n$PASSWORD" < /dev/null |passwd "$USERNAME"
    passwd -e ${USERNAME}

    EMAIL_BODY=$(echo "Hello " $USERNAME ", your password is " $PASSWORD)

    echo -e "${EMAIL_BODY}" < /dev/null | s-nail -S smtp-use-starttls -S ssl-verify=ignore -S smtp-auth=login -S smtp="smtp.gmail.com:587" -S smtp-auth-user="${EMAIL_ADDRESS}" -S smtp-auth-password="${EMAIL_PASSWORD}" -r "${EMAIL_ADDRESS}" -s "Account Details" -. "${ADDRESS}"
  else
    echo "User does not exist, creating user"
    adduser $USERNAME
    echo -e "$PASSWORD\n$PASSWORD" < /dev/null |passwd "$USERNAME"
    passwd -e ${USERNAME}
    usermod -a -G CSI230 $USERNAME
    chage -d 0 $USERNAME

    EMAIL_BODY=$(echo "Hello " $USERNAME ", your password is " $PASSWORD)

    echo -e "${EMAIL_BODY}" < /dev/null | s-nail -S smtp-use-starttls -S ssl-verify=ignore -S smtp-auth=login -S smtp="smtp.gmail.com:587" -S smtp-auth-user="${EMAIL_ADDRESS}" -S smtp-auth-password="${EMAIL_PASSWORD}" -r "${EMAIL_ADDRESS}" -s "Account Details" -. "${ADDRESS}"
  fi

done < $INPUT_FILE

