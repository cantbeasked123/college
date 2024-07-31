#!/bin/bash
#Programmer name: Joshua Fernandes
#Program title: Check Whether given year is leap year or not.


echo "enter a year "
read n
if [ ` expr $n % 4 ` == 0 ] || [ ` expr $n % 400 ` == 0 ]
then
echo "this is a leap year "
else

echo "this is not a leap year"
fi
