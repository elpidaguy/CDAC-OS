clear

echo "Enter 3 Numbers"
read x
read y
read z


if [ $x -gt $y -a $x -gt $z ];then
	echo "$x is the biggest Number"
fi

if [ $y -gt $x -a $y -gt $z ];then
	echo "$y is the biggest Number"
fi

if [ $z -gt $y -a $z -gt $x ];then
	echo "$z is the biggest Number"
fi
