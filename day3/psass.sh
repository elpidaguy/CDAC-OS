clear

echo
ps -r
echo "Count of Number of process Running in system is:" `ps -r --no-header | wc -l`

echo
echo
#echo "`ps -r & ps -r | echo \"`wc -l`-1\"|bc`"

echo "Processes which are running in foreground are: " 
echo "`ps -eo cmd,stat | grep '.*+$'`"

echo
echo

echo "Processes with PPID = 1 (init) are: "
echo "`ps --ppid 1`"
