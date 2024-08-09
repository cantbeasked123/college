#!/bin/bash
#Programmer name: Joshua Fernandes
#Program title: To sort given numbers in descending order.

echo "Enter number of elements: "
read n
echo "Enter the elements: "
for(( i=0; i<$n; i++))
do
read num[$i]
done

echo "Entered elements are: "
for(( i=0; i<$n; i++))
do
echo " ${num[$i]} "
done

for(( i=0; i<$n; i++))
do
for(( j=0; j<$n; j++))
do
if [ ${num[$i]} -gt ${num[$j]} ]
then
temp=${num[$i]}
num[$i]=${num[$j]}
num[$j]=$temp
fi
done
done

echo "Sorted array in descending order is: "
for(( i=0; i<$n; i++))
do
echo " ${num[$i]} "
done
