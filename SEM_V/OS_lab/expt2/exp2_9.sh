#!/bin/bash
#Programmer name: Joshua Fernandes
#Program title: Check whether the entered number is odd or even.

echo "Enter a number: "
read n

if [ ` expr $n % 2 ` == 0 ]
then
echo "The number is even."
else
echo "The number is odd."
fi
