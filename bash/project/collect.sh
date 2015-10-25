#!/bin/bash

###########################
# File Collection Program
# Author: Michael Palmer
# Class: CSCI 3232 A
# Date: February 25, 2015
###########################

# Set defaults
DEFAULT_LIB="$HOME/lib"
DEFAULT_SRC="$HOME/src"
DEFAULT_INC="$HOME/inc"
DEFAULT_BIN="$HOME/bin"
DEFAULT_LOG="$HOME/organize.log"
WAITTIME=10

# Save current directory path
STARTDIR=`pwd`

# Save command line parameters
COLLECTDIRS="${@}"

# Validate directories
while true ; do
	# No directories entered, request list of directories
	if [[ -z $COLLECTDIRS ]] ; then
		read -p "Enter directories to collect files from (space-separated): " COLLECTDIRS
	else
		# Verify all directories entered actually exist
		dirs_exist=1
		for x in $COLLECTDIRS ; do
			if [[ ! -d "$x" ]] ; then
				# Directory does not exist, printing an error message
				dirs_exist=0
				echo "ERROR: Directory '$x' does not exist. Please enter a valid directory."
			fi
		done
		
		# If directories exist, exit the loop, otherwise, start over
		if [[ $dirs_exist -eq 1 ]] ; then
			break
		else
			COLLECTDIRS=""
		fi
	fi
done

# Prompt user to input library directory
read -t $WAITTIME -p "Directory to collect library files into [$DEFAULT_LIB] " LIBDIR

# Line break if it times out
if [[ $? -ne 0 ]] ; then
	echo ""
fi

# Set default library directory
if [[ -z $LIBDIR ]] ; then
	LIBDIR=$DEFAULT_LIB
elif [[ $LIBDIR != *"/"* ]] ; then
	# Library directory is in the same directory as this
	# script, so we will save its full path
	LIBDIR="$STARTDIR/$LIBDIR"
fi

# Prompt user to input source directory
read -t $WAITTIME -p "Directory to collect source files into [$DEFAULT_SRC] " SRCDIR

# Line break if it times out
if [[ $? -ne 0 ]] ; then
	echo ""
fi

# Set default source file directory
if [[ -z $SRCDIR ]] ; then
	SRCDIR=$DEFAULT_SRC
elif [[ $SRCDIR != *"/"* ]] ; then
	# Source directory is in the same directory as this
	# script, so we will save its full path
	SRCDIR="$STARTDIR/$SRCDIR"
fi

# Prompt user to input include directory
read -t $WAITTIME -p "Directory to collect include files into [$DEFAULT_INC] " INCDIR

# Line break if it times out
if [[ $? -ne 0 ]] ; then
	echo ""
fi

# Set default include directory
if [[ -z $INCDIR ]] ; then
	INCDIR=$DEFAULT_INC
elif [[ $INCDIR != *"/"* ]] ; then
	# Include directory is in the same directory as this
	# script, so we will save its full path
	INCDIR="$STARTDIR/$INCDIR"
fi

# Prompt user to input binary directory
read -t $WAITTIME -p "Directory to collect binary files into [$DEFAULT_BIN] " BINDIR

# Line break if it times out
if [[ $? -ne 0 ]] ; then
	echo ""
fi

# Set default binary directory
if [[ -z $BINDIR ]] ; then
	BINDIR=$DEFAULT_BIN
elif [[ $BINDIR != *"/"* ]] ; then
	# Binary directory is in the same directory as this
	# script, so we will save its full path
	BINDIR="$STARTDIR/$BINDIR"
fi

# Prompt user to input log file
read -t $WAITTIME -p "Full path to save log file to [$DEFAULT_LOG] " LOGFILE

# Line break if it times out
if [[ $? -ne 0 ]] ; then
	echo ""
fi

# Set default log file
if [[ -z $LOGFILE ]] ; then
	LOGFILE=$DEFAULT_LOG
elif [[ $LOGFILE != *"/"* ]] ; then
	# Log file is in the same directory as this
	# script, so we will save its full path
	LOGFILE="$STARTDIR/$LOGFILE"
fi

function log {
	echo "${@}" >> "$LOGFILE"
}

function log_print {
	log "${@}"
	echo "${@}"
}

# Create new log file
dt=`date "+%D %T"`
echo "Starting file collection on $dt" > "$LOGFILE"

# Create library file directory if it doesn't exist
if [[ ! -d "$LIBDIR" ]] ; then
	echo "Creating library directory ($LIBDIR)"
	mkdir -p "$LIBDIR"
fi

# Create source file directory if it doesn't exist
if [[ ! -d "$SRCDIR" ]] ; then
	echo "Creating source file directory ($SRCDIR)"
	mkdir -p "$SRCDIR"
fi

# Create include file directory if it doesn't exist
if [[ ! -d "$INCDIR" ]] ; then
	echo "Creating include file directory ($INCDIR)"
	mkdir -p "$INCDIR"
fi

# Create binary file directory if it doesn't exist
if [[ ! -d "$BINDIR" ]] ; then
	echo "Creating binary file directory ($BINDIR)"
	mkdir -p "$BINDIR"
fi

# Start logging
log "LIB Directory: $LIBDIR"
log "SRC Directory: $SRCDIR"
log "INC Directory: $INCDIR"
log "BIN Directory: $BINDIR"

# Statistics variables
libfiles=0
srcfiles=0
incfiles=0
binfiles=0
numdirs=0

# Save start time
starttime=`date +%s%3N`

# Go through directories
for dir in $COLLECTDIRS ; do
	# Go to the directory
	cd $dir
	
	# Get the full path to the directory
	dirpath=`pwd`
	log "--------------"
	log "Directory: $dirpath"

	# Libraries (lib*.*) [lib]
	libs=$(ls | egrep '^lib.*\..*$')
	for libfile in $libs ; do
		log "Moved $dirpath/$libfile to $LIBDIR/$libfile"
		mv "$libfile" "$LIBDIR/$libfile"
		let "libfiles += 1"
	done

	# Source Files (*.c, *.cc, *.cpp, *.cxx) [src]
	srcs=$(ls | egrep '^.*\.c(c|pp|xx)?$')
	for srcfile in $srcs ; do
		log "Moved $dirpath/$srcfile to $SRCDIR/$srcfile"
		mv "$srcfile" "$SRCDIR/$srcfile"
		let "srcfiles += 1"
	done

	# Includes (*.h, *.hxx) [inc]
	incs=$(ls | egrep '^.*\.h(xx)?$')
	for incfile in $incs ; do
		log "Moved $dirpath/$incfile to $INCDIR/$incfile"
		mv "$incfile" "$INCDIR/$incfile"
		let "incfiles += 1"
	done

	# Binaries (*.sh, c programs) [bin]
	bins=$(find . -maxdepth 1 -type f -executable)
	for binfile in $bins ; do
		log "Moved $dirpath/${binfile:2} to $BINDIR/${binfile:2}"
		mv "${binfile:2}" "$BINDIR/${binfile:2}"
		let "binfiles += 1"
	done
	
	# Increment number of directories processed
	let "numdirs += 1"
	
	# Go back to the start directory
	cd $STARTDIR
done

# Save end time
endtime=`date +%s%3N`

# Print statistics
log "~~~~~~~~~~~~~~~~"
log_print "Directories Processed: $numdirs"
log_print "Library Files Moved: $libfiles"
log_print "Source Files Moved: $srcfiles"
log_print "Include Files Moved: $incfiles"
log_print "Binary Files Moved: $binfiles"
log_print "Execution Time: $((endtime-starttime)) ms"