#! /bin/bash

read -p "Enter the number : " num

if [ `expr $num % 2` == 0 ]
then
	echo "$num is Even !!"
else
	echo "$num is Odd !!"
fi
