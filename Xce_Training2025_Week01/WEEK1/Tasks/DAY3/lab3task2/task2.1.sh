#!/bin/bash
echo "Enter 0th argument: $0"
echo "Enter 1st argument: $1"
if (( $1 % 2 == 0 )); then
   echo  "number is even"
else 
   echo "number is odd"
fi
