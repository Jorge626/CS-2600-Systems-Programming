# Author: Jorge Aranda
# Class: CS2600
# Description: This script takes two arguments in terminal month and year
# The script then prints out the calander of the given input 
#!/bin/bash

# Sets variables and checks if input was given
PASS=0
MONTH=${1?Error: No year given}
YEAR=${2?Error: No month given}

# Checks if month is less than 1
if [ $MONTH -lt 1 ]; then
 echo "Error: Month cannot be less than 1 "
 PASS=1

# Checks if month is greater than 12
elif [ $MONTH -gt 12 ]; then
 echo "Error: Month cannot be greater than 12"
 PASS=1

# Checks if years is a two digit number and adds 2000
elif [ $YEAR -le 99 ]; then
 YEAR=$((YEAR+2000))
fi

# If no errors, prints calendar
if [ $PASS -eq 0 ]; then
 cal $MONTH $YEAR
else
 echo "Error: Could not print calander"
fi
