#!/bin/bash

# Function to calculate factorial recursively
factorial() {
  if [ $1 -le 1 ]; then
    echo 1
  else
    prev=$(factorial $(($1 - 1)))
    echo $(($1 * prev))
  fi
}

# Get user input
read -p "Enter a number: " num

# Check if input is a valid number
if ! [[ "$num" =~ ^[0-9]+$ ]]; then
  echo "Please enter a valid non-negative integer."
  exit 1
fi

# Calculate and display the factorial
result=$(factorial $num)
echo "Factorial of $num is $result"
