clear

echo "Enter the year"
read a

if [ `echo "$a % 4" | bc` -eq 0 ];then
	if [ `echo "$a % 100" | bc` -ne 0 ];then
		echo "$a is a leap year"
	elif [ `echo "$a % 400" | bc` -eq 0 ];then
		echo "$a is a leap year"
	else
		echo "$a is not a leap year"
	fi
else
	echo "$a is not a leap year"
fi
