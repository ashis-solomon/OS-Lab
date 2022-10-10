#! /bin/bash

read -p "Enter the value of a : " a
read -p "Enter the value of b : " b

echo ""
echo " a = $a"
echo " b = $b"

temp=$a
a=$b
b=$temp

echo ""
echo "swapped"

echo ""
echo " a = $a"
echo " b = $b"


