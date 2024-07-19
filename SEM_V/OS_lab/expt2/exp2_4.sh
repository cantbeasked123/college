#!/bin/bash
#Programmer name: Joshua Fernandes
#Program title: To print the number table.

echo "Enter a number:"
read num

echo "The number table of $num is:"
for ((i=1;i<=10;i++))
do
	prod=` expr $a \* $i `
	echo "$num * $i = $prod"
done
