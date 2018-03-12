#!/bin/bash

# COLOR='\x1b[38;5;220m'
COLOR=
END=
# END='\x1b[0m'
counter=1
n=110
passed=0
failed=0

clear
echo "$COLOR\0TN_TEST // LEM_IN$END"
sleep 1

mv "lem-in" lem_in

while [ $counter -le $n ]
	do
		# printf "test$counter\n"
		# ./lem_in tests/test$counter
		./lem_in < tests/test$counter > tests/logs/test$counter
		# grep -r "ERROR" tests/logs/test$counter
		if ! grep -r "ERROR" tests/logs/test$counter > /dev/null;
			then
				printf "$COLOR\0test$counter:\t\tBOOM 🔥\n$END"
				# cat tests/logs/test$counter
				# say BOOM
				failed=$((failed+1))
			else
				rm tests/logs/test$counter
		fi
	counter=$((counter+1))
	done
	# passed=$[n-failed]
printf "$(expr $n - $failed)/$n tests passed\n$END"
# printf "$COLOR$passed/$n tests passed\n$END"

mv lem_in "lem-in"

echo "$COLOR\0[DONE]$END"
