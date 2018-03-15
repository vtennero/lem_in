#!/bin/bash

VALGRIND_LOGS_DIR="valgrind_logs"
VALGRIND_LOGS_FILENAME="vlg_"

check_one_valgrind()
{
	local STORAGE_PATH=$VALGRIND_LOGS_DIR"/"$VALGRIND_LOGS_FILENAME"_test"$1
	local TESTS_PATH=$TESTS_ABSOLUTE_PATH/test$1

	$HOME/.brew/Cellar/valgrind/3.13.0/bin/valgrind --leak-check=full --log-file="$STORAGE_PATH" ./lem_in < tests/test$1 > /dev/null
	local definitely_lb=$(cat $STORAGE_PATH | grep "definitely lost: " | cut -d " " -f7)
	local indirectly_lb=$(cat $STORAGE_PATH | grep "indirectly lost: " | cut -d " " -f7)
	if [ "$definitely_lb" != "0" ] || [ "$indirectly_lb" != "0" ]
	then
		printf "\ntest$1:   \t$definitely_lb bytes definitely lost, $indirectly_lb bytes indirectly lost"
		# say boom
	else
		printf "$COLOR.$END"
	fi
}

check_valgrind()
{
	local VERSION=$(ls $HOME/.brew/Cellar | grep valgrind)
	local c=1

	echo "$COLOR\0Valgrind - '$3' output$END"
	if [ $VERSION ]
	then
		rm -rf $VALGRIND_LOGS_DIR
		mkdir -p $VALGRIND_LOGS_DIR
		while [ $c -le $1 ]
		do
			check_one_valgrind $c
			let "c++"
		done
	fi
	rm -rf lem_in.dSYM
	echo "$COLOR\n[LEAKS DONE]$END"
}