#!/bin/sh

ARG=0
TIME_PARAM=`uname`

#make re
make mallockiller;
if [ "$TIME_PARAM" = "Darwin" ]; then
	TIME_PARAM="-l"
else
	TIME_PARAM="-v"
fi;

while [ $ARG -le 5 ]
do
	echo "compiling test"$ARG".c - - - - - - - - - - - - - - - -"

	rm tester/test$ARG
	gcc -Wall -Wextra -Werror -I includes  -o tester/test$ARG tester/test$ARG.c
	echo "- - - - - - - - - - - - - - - - - - - - - - - - -"
	echo ---------------- the real test$ARG -----------------
	/usr/bin/time $TIME_PARAM ./tester/test$ARG 2>> .result;
	cat .result | grep "reclaim";
	#cat .result | grep "aximum resident set size";
	cat .result | grep "page fault";
	#cat .result | grep "context";
	rm .result;

	sleep 1
	echo ----------------- my own test$ARG ------------------
	rm tester/test$ARG
	gcc -Wall -Wextra -Werror -I includes -o tester/test$ARG tester/test$ARG.c -L . -lft_malloc

if [ "$TIME_PARAM" = "-l" ]; then
	export DYLD_LIBRARY_PATH=.;
	export DYLD_INSERT_LIBRARIES=libft_malloc_x86_64_Darwin.so;
else
	export LD_LIBRARY_PATH=.;
	export LD_PAYLOAD=libft_malloc_x86_64_Linux.so;
fi;

	/usr/bin/time $TIME_PARAM ./tester/test$ARG 2>> .result;
	cat .result | grep "reclaim";
	#cat .result | grep "aximum resident set size";
	cat .result | grep "page fault";
	#cat .result | grep "context";

	rm .result;
if [ "$TIME_PARAM" = "-l" ]; then
	unset DYLD_LIBRARY_PATH
	unset DYLD_INSERT_LIBRARIES
else
	unset LD_LIBRARY_PATH
	unset LD_PAYLOAD
fi;

	echo "- - - - - - - - - - - - - - - - - - - - - - - - -"
	echo "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n"
	sleep 1
	ARG=$((ARG+1))
done

if [ "$TIME_PARAM" = "-l" ]; then
	unset DYLD_LIBRARY_PATH;
	unset DYLD_INSERT_LIBRARIES;
else
	unset LD_LIBRARY_PATH;
	unset LD_PAYLOAD;
fi;
