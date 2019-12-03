: '2.Write a menu based script to perform following string operations
a) To find length of a string
c) Copying string
d) Concatenation of strings
e) Comparison of two strings
f) Reversing a string
'
#!/bin/bash/
clear

: 'getStr()
{
	echo "Enter Your String: ";read str
	return str;
}'

ch=0
while [ $ch -ne 6 ]
do

echo
echo
echo
echo "---------MENU-----------"
echo "1.Find Length of string"
echo "2.Copying string"
echo "3.Concatenation of string"
echo "4.Comparision of string"
echo "5.Reverse a string"
echo "6.Exit"
echo
read ch

#echo "Enter your string: ";read str

case $ch in
	1)
		echo "Enter your string: ";read str
#		getStr()
		echo "Length of given string is: "${#str}
		;;
	2)

		echo "Enter your string: ";read str
		newstr=""
		newstr="$str"
		echo "Copied new string is: "$newstr
		;;
	3)

		echo "Enter your string: ";read str
		echo "Enter 2nd String:";read str2
		echo "Concat of 2 str is: "$str$str2
		;;
	4)

		echo "Enter your string: ";read str
		echo "Enter 2nd String: ";read str2
		if [ $str = $str2 ];then
			echo "$str and $str2 are same"
		else
			echo "$str and $str2 are not same"
		fi
		;;
	5)

		echo "Enter your string: ";read str
		echo "Reverse of given string is: "
		for((i=${#str}; i>=0; i--))
		do
			echo -n "${str:$i:1}"
		done
		;;
	6)
		echo "Thank You!";;
	*)
		echo "Invalid Choice"
		;;
esac
done
