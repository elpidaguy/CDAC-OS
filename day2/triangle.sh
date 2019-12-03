#!/bin/bash

clear

echo "Enter the sides of triangle"
read a
read b
read c


if [ $a -eq $b ];then
	if [ $a -eq $c ];then
		echo "Traingle is Equilateral Triangle"
	elif [ $b -eq $c ];then
		echo "Triangle is Isosceles Triangle"
	elif [ $a -ne $c ];then
		echo "Triangle is Isosceles Triangle"
	fi
elif [ $b -eq $c ];then
	echo "Triangle is Isosceles Triangle"
elif [ $a -eq $c ];then
	echo "Triangle is Iscosceles Triangle"
fi
