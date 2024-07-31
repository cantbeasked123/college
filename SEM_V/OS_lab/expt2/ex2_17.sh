#!/bin/bash
#Programmer name: Joshua Fernandes
#Program title: Write a shell script to prompt user to enter 2 numbers and perform various arithmetic operations using switch statement.

echo "enter 2 numbers "
read a b
echo "Select an arithmetic operation to perform:
a--addition
b--subtraction
c--division
d--multiplication

Enter your choice: "
read choice
echo "Result:"
case $choice in
a)res=`expr $a + $b`;;
b)res=`expr $a - $b`;;
c)res=`expr $a / $b`;;
d)res=`expr $a \* $b`;;
*)echo "Invalid option";;
esac
echo "$res"
