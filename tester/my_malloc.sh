OS=`uname`

if [ "$OS" = "Darwin"  ]; then
	ARG="-l"
	ENV_EXP_VAR="DYLD_LIBRARY_PATH=."
	ENV_VAR="DYLD_INSERT_LIBRARIES"
else
	ARG="-v"
	ENV_EXP_VAR="LD_LIBRARY_PATH=."
	ENV_VAR="LD_PAYLOAD"
fi;

if [ $# = 0 ]; then
	echo "usage: ./tester/my_malloc.sh [arg]"
else
	gcc -I includes/ -o mallockiller srcs/main.c -L. -lft_malloc -I libft/ -L libft/ -lft
	export $ENV_EXP_VAR
	export $ENV_VAR=libft_malloc.so ; /usr/bin/time $ARG ./mallockiller $1
	unset DYLD_LIBRARY_PATH
	unset LD_LIBRARY_PATH
fi;
