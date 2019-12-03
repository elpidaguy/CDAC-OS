clear

echo "Enter the Number:"
read a

echo "Enter the second Number:"
read b

#using expr
res=0

res=`expr $a + $b`

echo -n "1.Sum of $a and $b is: "$res

echo
res=`expr $a \* $b`

echo -n "1.Mul of $a and $b is: "$res

echo

echo
echo

#using let

let newres=0

let "newres=$a + $b"

echo -n "2.Sum of $a and $b is:"$newres

echo
let "newres=$a * $b"

echo -n "2.Mul of $a and $b is:"$newres

echo

#using bc

bcres=0

echo -n "3.Sum of $a and $b is: " `echo $a+$b|bc`

echo
echo -n "3.Mul of $a and $b is: " `echo $a*$b|bc`
