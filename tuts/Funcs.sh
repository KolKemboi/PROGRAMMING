#!/usr/bin/env bash

myfunc() {
	echo "hello World"
}

myfunc 

function myfunc_1 {
	echo "My name is Jeff"
}

myfunc_1

function otherfunc {
	echo "Hello $1 $2"
}

otherfunc "Heff" "Kool"

retres() {
	local my_res='some value'
	echo "$my_res"
}

res=$(retres)
echo "res stored $res"

errorneous() {
	return 1
}

if errorneous; then
	echo "Function ran well"
else
	echo "Function Exit code 1"
fi

#things to note
# $# number of args
# $* all positional arguments (as a single word)
# $@ All positional arguments (as separate strings)
# $1 First argument
# $_ Last arguement

args() {
	echo "$#" # => tells me what nuber of values are entered
	echo "$*" # => echos all the arguements into one line
	echo "$@" # => all args as separate
	echo "$1"
	echo "$_" # => echos the arguement of the previous command
}

args "x y" z
