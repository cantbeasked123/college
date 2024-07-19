#!/bin/bash
#Programmer name: Joshua Fernandes
#Program title: To print the largest of 3 numbers entered by the user.

echo "Enter 3 numbers:"
read num1
read num2
read num3

if [ $num1 -gt $num2 -a $num1 -gt $num3 ]
then
	echo "The largest number is:$num1"
elif [ $num2 -gt $num1 -a $num2 -gt $num3 ]
then
	echo "The largest number is: $num2"
else
	echo "The largest number is: $num3"
fi
