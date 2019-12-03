clear

echo "Enter 3 Numbers"
read x
read y
read z

nums=(x y z)

sum=0
for i in "${nums[@]}"
do
	sum=$(($sum+$i))

done

echo "Avg is: "`echo $(($sum/3)) | bc`
