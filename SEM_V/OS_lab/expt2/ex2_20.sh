#!/bin/bash
#Programmer name: Joshua Fernandes
#Program title:Write a shell script to display the following information(consider last option to exit from the program)a)display processor information(b)display real time memory status(c)display real time process status (d)exit "


echo "
a)display processor information
b)display real time memory status
c)display real time process status
d)exit "
echo "Enter your choice:"
read choice
while [ $choice != d ]
do
if [ $choice == a ]
then
lscpu
break
elif [ $choice == b ]
then
cat /proc/meminfo
break
elif [ $choice == c ]
then
ps
break
else
echo "invalid option "
break
fi
done
