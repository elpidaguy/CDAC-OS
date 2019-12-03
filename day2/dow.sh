clear

echo "Enter the weekday number"
read a

echo "1.Using elif"
echo "2.Using case"
read b

case $b in
	1)

#using elif
if [ $a -eq 0 ];then
	echo "$a is Sunday"

elif [ $a -eq 1 ];then
	echo "$a is Monday" 

elif [ $a -eq 2 ];then
	echo "$a is Tuesday" 

elif [ $a -eq 3 ];then
	echo "$a is Wednesday"

elif [ $a -eq 4 ];then
	echo "$a is Thursday" 

elif [ $a -eq 5 ];then
	echo "$a is Friday"

elif [ $a -eq 6 ];then
	echo "$a is Saturday"
else
	echo "Out of Range"
fi
;;

2)

#using case

case $a in
	0)
		echo "$a is Sunday";;
	1)
		echo "$a is Monday";;
	2)
		echo "$a is Tuesday";;
	3)
		echo "$a is Wednesday";;
	4)
		echo "$a is Thursday";;
	5)
		echo "$a is Friday";;
	6)
		echo "$a is Saturday";;
	*)
		echo "$a is Out of range";;

esac

;;

*)
	echo "Invalid Input";;
esac
