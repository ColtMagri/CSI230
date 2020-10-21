#!/bin/bash

if [ $(id -u) -ne 0 ]
then
  echo "Must be root to user Colt's Shell Script!!"
  exit 1
fi

unset INPUT_FILE

group="CSI230"
if grep -q $group /etc/group
then
  echo "CSI230 group already created. Continuing..."
else
  echo "Creating CSI230 group..."
  groupadd CSI230
  echo "Done..."
fi

echo "Please enter email address:"
read EMAIL_ADDRESS
echo "Please enter email password:"
read -s EMAIL_PASSWORD

usage()
{
  echo "$0 usage: [-f input file]"
  exit 1
}

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

