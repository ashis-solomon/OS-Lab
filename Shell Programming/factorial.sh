#! /bin/bash

read -p "Enter the number : " num

num1=$num
fact=1

while [ $num1 -gt 1 ]
do
	fact=$((fact*num1))
	num1=$((num1-1))
done

echo "The Factorial of $num is = $fact"
