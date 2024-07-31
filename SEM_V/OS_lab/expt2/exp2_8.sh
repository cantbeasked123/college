#!/bin/bash
#Programmer name: Joshua Fernandes
#Program title: To reverse a string.

echo "enter a string "
read str
len=`echo $str | wc -c`
while [ $len -gt 0 ]
do
rev=$rev` echo $str | cut -c $len `
len=`expr $len - 1`
done
echo "the reversed string is : $rev"

