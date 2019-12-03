clear

echo "Enter the Number:"
read a

echo "Enter the second Number:"
read b

echo -n "Div of $a and $b is: " `echo "scale=2;$a/$b" | bc`
