clear

echo "Enter file name"
read fname

if [ -e $fname -a -f $fname ];then
	echo "$fname is a File"
elif [ -e $fname -a -d $fname ];then
	echo "$fname is a directory"
fi
