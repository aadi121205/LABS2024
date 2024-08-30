#!/bin/bash

while true; do
  current_time=$(date +"%H")
  
  if [ "$current_time" -eq "08" ]; then
    echo "It's 8 AM! Current date and time: $(date)"
    sleep 3600  # Sleep for an hour to prevent multiple prints within the same hour
  else
    sleep 60  # Check every minute
  fi
done
