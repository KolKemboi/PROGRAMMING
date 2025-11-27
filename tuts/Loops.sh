#!/usr/bin/env bash

# basic for loops
for i in /etc/*; do
	echo "$i"
done

# Ranges
for i in {1..4}; do
	echo "Welcome $i"
done

# Ranges with a step size

for i in {5..50..5}; do
	echo "Welcome to Derry $i"
done

#Reading lines
while read -r line; do
	echo "$line"
done <helloworld.sh

# C-like for loops
for ((i = 0 ; i < 10; i++ )); do
	echo "$i"
done
