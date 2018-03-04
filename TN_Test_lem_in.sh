#!/bin/bash

COLOR='\x1b[38;5;220m'
END='\x1b[0m'
c=1
n=110
passed=0
failed=0

clear
echo "$COLOR\0TN_TEST // LEM_IN$END"
sleep 1

mv "lem-in" lem_in

while [ $c -le $n ]
	do
		# printf "test$c\n"
		# ./lem_in tests/test$c
		./lem_in < tests/test$c > tests/logs/test$c
		# grep -r "ERROR" tests/logs/test$c
		if ! grep -r "ERROR" tests/logs/test$c > /dev/null;
			then
				printf "$COLOR\0test$c:\t\tBOOM 🔥\n$END"
				# cat tests/logs/test$c
				# say BOOM
				let "failed++"
			else
				rm tests/logs/test$c
		fi
	let "c++"
	done
	passed=$[n-failed]
printf "$COLOR$passed/$n tests passed\n$END"

mv lem_in "lem-in"

echo "$COLOR\0[DONE]$END"
