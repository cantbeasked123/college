#!/bin/bash
#Programmer name: Joshua Fernandes
#Program title: To reverse a number.

echo "Enter a number:"
read num
n=0

while [ $num -gt 0 ]
do
	n=` expr $n \* 10 `
	x=` expr $num % 10 `
	n=` expr $n + $x `
	num=` expr $num / 10` 
done
echo "the number is $n"
