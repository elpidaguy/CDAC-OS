#6.Write a script to check each entry of a directory is a file or directory.

lsout=`ls -l | tr -s " " | cut -d " " -f9`

#echo "$lsout"

for i in $lsout; do
  if [ -d $i ];then
	  echo "$i is a directory"
  elif [ -f $i ];then
	  echo "$i is a file"
  else
	  echo "$i is not either directory or file"
  fi
done

