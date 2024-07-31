#!/bin/bash
#Programmer name: Joshua Fernandes
#Program title: Using switch case print the capitals given the state name.

echo "Select a state:
a--Goa
b--Rajasthan
c--Karnataka
d--Maharashtra
e--Kerala"

echo "
Enter your choice:"
read choice
echo "Capital:"
case $choice in
a)echo "Panjim";;
b)echo "Jaipur";;
c)echo "Bangalore";;
d)echo "Mumbai";;
e)echo "Thiruvananthapuram";;
*)echo "Invalid choice!"
esac
