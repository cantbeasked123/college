#!/bin/bash
#Programmer name: Joshua Fernandes
#Program title: To print all the prime numbers less than 20.

a=2
while [ $a -lt 20 ]
do
i=2
flag=0
while [ $i -le `expr $a / 2` ]
do
if [ `expr $a % $i` -eq 0 ]
then
flag=1
break
fi
i=`expr $i + 1`
done

if [ $flag -eq 0 ]
then
echo $a
fi
a=`expr $a + 1`
done
