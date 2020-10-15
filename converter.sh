#!/bin/bash
# file converter.sh
# brief  Modified version of converter.sh to now test if the inputted file exists or not
# author ColtMagri
# date 10/15/2020

#usage function, essentially an error to be called if input is incorrect
usage()
{
 echo "$0 usage: [-f input file] [-c U(pper) or L(lower)"
 exit 1
}

#intakes the inputs, that being file name and case setting (upper or lower case). Also checks if file exists or not
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
#Takes each line passed through and uses tr to convert from lower to upper or upper to lower
while read line
do
 if [ ${c} == "U" ]; then
  echo $line | tr [:lower:] [:upper:]
 else
  echo $line | tr [:upper:] [:lower:]
 fi
done < $f

exit 0
