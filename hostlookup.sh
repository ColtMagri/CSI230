#!/bin/bash
# file hostlookup.sh
# brief  Modified version of hostlookup.sh to now take a file as input and iterate through the file to check each hostname
# author ColtMagri
# date 10/15/2020

#usage function, essentially an error to be called if input is incorrect
usage()
{
 echo "$0 usage: [-f input file]"
 exit 1
}

#Takes the inputs in. If the file does not exist, it exits by calling usage. If it does, the program continues
while getopts ":f:" options;
do
 case "${options}" in
  f)
   f=${OPTARG}
   if test -f $f; then
    echo "File Exists. Running Command"
   else
    usage
   fi
   ;;
  *)
   usage
   ;;
 esac
done

#This iterates through the passed file to test the hostname of each line in the file
while read line
do
 out=$(host -W1 -t A $line)
 if [ $? -eq 0 ];then
  ip=$(echo $out | cut -d " " -f 4)
  echo $line,$ip
 else
  echo "$line,not found"
 fi
done < $f

exit 0
