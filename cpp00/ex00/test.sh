#! /bin/bash

ESC='\e['
RED=31
GREEN=32
YELLOW=33
BLUE=34

PRINT_COLOR() {
	if [ $1 -eq $RED ] ; then
		COLOR=$RED
	elif [ $1 -eq $GREEN ] ; then
		COLOR=$GREEN
	elif [ $1 -eq $BLUE ] ; then
		COLOR=$BLUE
	elif [ $1 -eq $YELLOW ] ; then
		COLOR=$YELLOW
	fi
	i=0
	for str in "$@"
	do
		if [ $i -ne 0 ] ; then
			printf "${ESC}${COLOR}m%s${ESC}m" "$str"
		fi
		((i++))
	done
}

_EXEC() {
	if [ $# -eq 0 ] ; then
		PRINT_COLOR $BLUE "args is None"
	else
		PRINT_COLOR $GREEN "args = "
		for arg in "$@"
		do
			PRINT_COLOR $GREEN "\"$arg\" "
		done
	fi
	echo ''
	./megaphone "$@"
}

TEST() {
	_EXEC 
	_EXEC "shhhhh... I think the students are asleep..."
	_EXEC  Damnit " ! " "Sorry students, I thought this thing was off."
	_EXEC "a b c D e F g" "h i J K L m n o P q R s t u v w x Y Z" "1 2 3 45 6 7890" ",.-_=+"
	_EXEC ""
	_EXEC " "
	_EXEC "" ""  "" "" ""
}

TEST
