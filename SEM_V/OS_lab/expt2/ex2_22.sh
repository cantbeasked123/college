#!/bin/bash
#Programmer name: Joshua Fernandes
#Program title: give command...

echo "
a)view memory status in kilobytes
b)to view PID of a specific process
c)to view of all loged in uses
d)to forcefully delete directory having sub directories as well as files
e)exit to view pid of a specific process in shell
"
while true;do
echo "Enter your choice: "
read choice
case $choice in
a)
grep MemTotal /proc/meminfo
echo " "
;;
b)
pidof bash
echo " "
;;
c)
who
echo " "
;;
d)
echo "Enter the directory: "
read file
rm -rf $file
echo " "
;;
e)
echo "Exiting program"
exit 0
;;

esac
done
