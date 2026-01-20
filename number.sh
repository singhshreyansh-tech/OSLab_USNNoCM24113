#!/bin/bash
# Script: fibonacci.sh
# Purpose: Generate first n Fibonacci numbers

# Input how many numbers to generate
read -p "Enter how many Fibonacci numbers to generate: " n

# First two Fibonacci numbers
a=0
b=1

echo "First $n Fibonacci numbers:"

# Loop to generate Fibonacci numbers
for (( i=1; i<=n; i++ ))
do
    echo -n "$b "
    # Calculate next number
    fn=$((a + b))
    a=$b
    b=$fn
done

echo ""  # New line at the end
