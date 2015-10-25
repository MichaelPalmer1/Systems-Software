#!/bin/bash

###########################
# File Un-Collection Program
# Author: Michael Palmer
# Class: CSCI 3232 A
# Date: February 25, 2015
###########################

# Set defaults
DEFAULT_LOG="$HOME/organize.log"
WAITTIME=10

# Get log file from user
read -t $WAITTIME -p "Enter path to log file created by collection program [$DEFAULT_LOG] " INFILE

# Check that the log file exists
if [[ ! -f $INFILE ]] ; then
	echo "ERROR: File '$INFILE' does not exist"
	exit
fi

# Parse log file
while read line ; do
	if [[ $line == "Moved "* ]] ; then
		# Find original and new locations
		orig_loc=`echo $line | cut -d ' ' -f 2`
		new_loc=`echo $line | cut -d ' ' -f 4`
		
		# Move the file
		echo "Moved $new_loc to $orig_loc"
		mv $new_loc $orig_loc
	fi
done < $INFILE