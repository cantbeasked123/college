#!/bin/bash
#Programmer name: Joshua Fernandes
#Program title: Generate the series: 1,3,2,4,3,5,4,6,.....

a=1
b=3
echo -n " $a $b "
for(( i=1 ; i<=3 ; i++ ))
do
a=`expr $a + 1`
b=`expr $b + 1`
echo -n "$a $b "
done
echo "
"
