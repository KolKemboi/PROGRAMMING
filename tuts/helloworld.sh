#!/usr/bin/env bash

echo "Hello World"

# mkdir my_dir
# cd my_dir
# touch myfile.txt
# ls
# "Hello ooo" >> myfile.txt
# cat myfile.txt

#variables
name="John"
echo "Hello $name!"
echo "${name}"

get_name(){
	echo "Hello Woooorld Funch"
}

get_name # functions are called without the braces

if [[ -z "$name" ]]; then # -z checks if the string is empty
	echo "String is empty"
elif [[ -n "$name" ]]; then # -n checks if the string is not empty
	echo "Sting not empty"
fi

# brace expansion
echo {A,B} # returns A  B
echo {A,B}.cpp #returns A.cpp, B.cpp
echo {1..5} #returns 1 2 3 4 5
echo {{1..3},{1..10}}
