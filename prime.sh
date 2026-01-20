#!/bin/bash
# Script: prime.sh
# Purpose: Generate first b prime numbers

# Input number of prime numbers to generate
read -p "Enter how many prime numbers to generate: " b

count=0   # Count of prime numbers found
num=2     # Number to check for prime

echo "First $b prime numbers:"

while [ $count -lt $b ]
do
    is_prime=1  # Assume number is prime
    # Check divisibility from 2 to num-1
    for (( i=2; i*i<=num; i++ ))
    do
        if [ $((num % i)) -eq 0 ]; then
            is_prime=0
            break
        fi
    done

    # If prime, print it and increment count
    if [ $is_prime -eq 1 ]; then
        echo -n "$num "
        ((count++))
    fi

    ((num++))  # Check next number
done

echo ""  # New line at the end
