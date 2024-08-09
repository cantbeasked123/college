#!/bin/bash
#Programmer name: Joshua Fernandes
#Program title: 23. Display the following patterns :
#* * * * *
#* * * *
#* * *
#* *
#*

for ((i=5;i>0;i--))
do
for ((j=0;j<i;j++))
do
echo -n " * "
done
echo
done

for ((i=1;i<=4;i++))
do
for ((j=i;j<=4;j++))
do
echo -n " $j "
done
echo
done

for ((i=1;i<=4;i++))
do
for ((j=1;j<=i;j++))
do
echo -n " $i "
done
echo
done
