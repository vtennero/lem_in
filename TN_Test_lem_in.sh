#!/bin/bash

COLOR='\x1b[38;5;220m'
# COLOR=
# END=
END='\x1b[0m'
# counter=1
n=125
p=14
# passed=0
# failed=0

source general_tests.sh
source valgrind_lem_in.sh

clear
echo "$COLOR\0TN_TEST // LEM_IN\n$END"
sleep 1

mv "lem-in" lem_in

# while [ $counter -le $n ]
# 	do
# 		./lem_in < tests/test$counter > tests/logs/test$counter
# 		# if ! grep -r "ERROR" tests/logs/test$counter > /dev/null;
# 		if grep -r "ERROR" tests/logs/test$counter > /dev/null;
# 		# if ! diff -u tests/error tests/logs/test$counter > /dev/null;
# 			then
# 				rm tests/logs/test$counter

# 			else
# 				printf "$COLOR\0test$counter:   \tBOOM 🔥\n$END"
# 				failed=$((failed+1))
# 		fi
# 	counter=$((counter+1))
# 	done
# 	# passed=$[n-failed]
# printf "$COLOR$(expr $n - $failed)/$n tests passed\n$END"
# printf "Tip for debugging : diff -u valid testXXX\n"
# # printf "$COLOR$passed/$n tests passed\n$END"

# read -p "Press enter to continue..."
# clear
# echo "$COLOR\0TN_TEST // LEM_IN$END"

invalid_input_tests $n

valid_input_tests $p

check_valgrind $n $p

mv lem_in "lem-in"

echo "$COLOR\0[ALL DONE]$END"
