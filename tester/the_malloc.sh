OS_NAME=`uname`

if [ $OS_NAME = "Darwin"  ]; then
	ARG="-l"
else
	ARG="-v"
fi;


if [ $# = 0 ]; then
	echo "usage: ./tester/the_malloc.sh [arg]"
else
	rm mallockiller
	gcc -I includes/ -o mallockiller srcs/main.c -I libft/ -L libft/ -lft
	/usr/bin/time $ARG ./mallockiller $1
fi;
