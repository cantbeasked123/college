#!/bin/bash
#Programmer name: Joshua Fernandes
#Program title: Display greet message using the system time

d=`date +%H`

if [ $d -ge 0 -a $d -lt 12 ]
then
	echo "good morning"
elif [ $d -ge 12 -a $d -lt 16 ]
then
	echo "good afternoon "
elif [ $d -ge 16 -a $d -lt 20 ]
then
	echo "good evening"
else
	echo "good night"
fi
