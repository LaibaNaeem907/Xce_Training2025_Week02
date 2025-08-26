#!/bin/bash
n=1
while read lines
do
  echo "Line no:$n $lines"
  ((n++))
done < task4.1.txt

