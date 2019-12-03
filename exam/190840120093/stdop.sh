#!/bin/bash

clear

echo -n "Enter File Name: "; read a

#check if file exists
if [ -e $a ];then
#check if user has entered file name
	if [ -f $a ];then

		#check for total commas in file
		fileop=`cat $a | grep -o , | wc -l`
		i=0
		#for i in sequence of number of commas +1
		for i in `seq $(($fileop+1))`
		#for i in `seq 5`
		do
			#print the output on console on new  line without commas
			echo "`cat $a | cut -d "," -f$i`"
		done
	else
		echo "Invalid File"
	fi
else
	echo "File not found!"
fi

#output
#Enter File Name: details
#Kaustubh Joshi
#DAC
#190840120093
#Operating System
#exabytes@gmail.com
#pune
#dac@dac-Veriton-M200-H310:~/Desktop/190840120093$

