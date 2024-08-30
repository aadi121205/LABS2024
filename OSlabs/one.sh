#!/bin/bash

# Function to calculate factorial
factorial() {
  if [ $1 -le 1 ]; then
    echo 1
  else
    prev=$(factorial $(( $1 - 1 )))
    echo $(( $1 * prev ))
  fi
}

# Read input from the user
read -p "Enter a number: " number

# Check if the input is a valid number
if ! [[ $number =~ ^[0-9]+$ ]]; then
  echo "Invalid input. Please enter a positive integer."
  exit 1
fi

# Calculate and display the factorial
result=$(factorial $number)
echo "Factorial of $number is: $result"
