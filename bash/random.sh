#!/bin/bash
num=$RANDOM
while [ $num -ge 10 ] ; do
	num=$RANDOM
done

for ((i=1; i<=3; i++)) ; do
	echo -n "Enter an integer: "
	read x
	if [ $x -eq $num ] ; then
		echo "GOT IT"
		exit
	else
		if [ $i -eq 3 ] ; then
			echo "Sorry, you failed"
		else
			echo "Try again"
		fi
	fi
done
