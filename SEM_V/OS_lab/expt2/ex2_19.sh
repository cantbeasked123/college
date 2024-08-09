#!/bin/bash
#Programmer name: Joshua Fernandes
#Program title: Write a shell script for the following menu:a)list of files(b)number of users of the system(c)todays date(d)quit to UNIX

echo "
a)list of files
b)number of users of the system
c)todays date
d)quit to UNIX
"
echo "Enter your choice:"
read choice
while [ $choice != d ]
do
if [ $choice == a ]
then
ls
break
elif [ $choice == b ]
then
who
break
elif [ $choice == c ]
then
date +"%D"
break
else
echo "invalid option "
break
fi
done
