#!/bin/bash
#Programmer name: Joshua Fernandes
#Program title: To check if the entered string is palindrome or not.

echo "Enter a string:"
read str
rev=`expr $str|rev`
if [ $rev=$str ];
then
echo "The entered string ‘$str’ is a palindrome."
else
echo "The entered string ‘$str’ is not a palindrome."
fi
