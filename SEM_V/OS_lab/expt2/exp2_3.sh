#!/bin/bash
#Programmer name: Joshua Fernandes
#Program title: Generate the fibonacci series for the number of terms entered by the user.

echo "Enter a number:"
read num
a=0
b=1

echo "The fibonacci series for $num is:"
for ((i=0;i<num;i++))
do
	echo -n "$a " 
	c=` expr "$a" + "$b" `
	a=$b
	b=$c
done

