clear
#!/bin/bash

: '5.Write a script to create 10 directories, say exam1,exam2,...,exam10 Report
error if a directory/file exists with same name.
'

echo "Enter dir name:"
read dname

for i in `seq 10`; do
	if [ -e $dname$i ];then
		echo "Dir already Exists"
	else
		mkdir $dname$i
	fi
done
