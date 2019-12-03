clear

echo "Enter the Number:"
read a

#if (( $a % 2 == 0)) 
if [ `echo "$a % 2" | bc` -eq 0 ]
then
	echo "$a is Even Number"
else
	echo "$a is Odd Number"
fi

echo

