#!/bin/bash
#Programmer name: Joshua Fernandes
#Program title: To display square of first 20 numbers.

echo "The square of first 20 numbers is:"
for ((i=1;i<=20;i++))
do
	sq=` expr $i \* $i `
	echo "$i^2=$sq"
done
