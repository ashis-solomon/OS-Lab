#! /bin/bash

read -p "Enter the year : " year

if [ `expr $year % 4` == 0 ]
then 
	echo "$year is a leap year !!"
else
	echo "$year is not a leap year !!"
fi
