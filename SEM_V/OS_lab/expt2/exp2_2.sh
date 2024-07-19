#!/bin/bash
#Programmer name: Joshua Fernandes
#Program title: Find the factorial of a given number.
echo "Enter a number:"
read num
fact=1

if [ $num -lt 0 ]
then
	echo "Factorial of a negative number doesnt exist"
elif [ $num -ge 0 ]
then
	for ((i=2;i<=num;i++))
	do
		fact=` expr $num \* $i `
	done
fi
echo "The factorial of $num is: $fact"

