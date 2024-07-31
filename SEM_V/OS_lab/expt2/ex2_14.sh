#!/bin/bash
#Programmer name: Joshua Fernandes
#Program title: Write shell script to generate following series: 20, 22, 18, 20, 16, 18, 14, 16.

a=20

b=22
echo -n " $a $b"
for(( i=1 ; i<=3 ; i++ ))
do
a=` expr $a - 2 `
b=` expr $b - 2 `
echo -n " $a $b "
done
echo " 
"
