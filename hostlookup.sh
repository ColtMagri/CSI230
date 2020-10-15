#!/bin/bash
#comments go here

usage()
{
 echo "$0 usage: [-f input file]"
 exit 1
}

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
