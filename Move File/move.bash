# Author: Jorge Aranda
# Class: CS2600
# Description: This script takes two arguments in terminal src file and dst file
# The script then moves the file and renames the file
#!/bin/bash

# Sets variables and checks if input was given
SRC=${1?Error: No Source file given}
DST=${2?Error: No Destination file given}
PASS=1

# Checks to see if the file exists
if [ ! -e $SRC ]; then
 echo "Error: That file does not exist"
 PASS=0
fi

# New variable to test if the file already exists
DST_TEST=$DST
i=1

# Looping function to add .{i} if file exists
while [ -e $DST_TEST ]; do
 DST_TEST="$DST.$i"
 i=$((i+1))
done

# Moves file
if [ $PASS -eq 1 ]; then
 mv $SRC $DST_TEST
fi
