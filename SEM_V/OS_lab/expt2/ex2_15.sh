#!/bin/bash
#Programmer name: Joshua Fernandes
#Program title: Append content to a file provided file name exists and it has write permission.

echo "Enter a file name:"
read file1
if [ -f "$file1" ]
then
if [ -w "$file1" ]
then
echo "Enter the content to add:"
cat >> $file1
else
echo "File is not writtable"
fi
else
echo "File does not exist"
fi

