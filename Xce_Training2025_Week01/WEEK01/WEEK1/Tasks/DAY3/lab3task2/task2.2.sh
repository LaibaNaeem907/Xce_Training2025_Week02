#!/bin/bash
echo "Enter 0th argument: $0"
echo "Enter 1st argument: $1"
 echo "first 10 multiples are:"
for ((i=1; i<11; i++))
do
 echo  $(($1*i))
done
