#!/bin/bash
#Programmer name: Joshua Fernandes
#Program title:Write a a menu driven shell script to (i)create a file (ii)To read a file (iii)To append the existing file (iv)rename the already existing file

while [ 1 ]
do
	echo "Enter choice:"
	read choice
	case $choice in
	1)	echo "Enter the filename:"
		read file1
		touch $file1;;	
	2) 	echo "Enter the filename:"
		read file1
		cat $file1;;		
	3) 	echo "Enter the filename:"
		read file1
		echo "Enter the contents:"
		read 
		cat $REPLY >> $file1;;
	4) 	echo "Enter the filename:"
		read file1
		rm file1;;
	5)	mv $file1 $file2;; 
esac
done
