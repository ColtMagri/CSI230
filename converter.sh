#!/bin/bash

usage()
{
 echo "$0 usage: [-f input file] [-c U(pper) or L(lower)"
 exit 1
}

while getopts ":f:c:" options;
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
  c)
   c=${OPTARG}
   if [[ ${c} == "U" || ${c} == "L" ]]; then
    echo "${f} - ${c}"
   else
    usage
   fi
  ;;
  *)
  usage
  ;;
 esac
done
#conversion logic here

while read line
do
 if [ ${c} == "U" ]; then
  echo $line | tr [:lower:] [:upper:]
 else
  echo $line | tr [:upper:] [:lower:]
 fi
done < $f

exit 0
