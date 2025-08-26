#!/bin/bash
num=$((($RANDOM%10)+1))
read -p "Enter number:" NUMBER
echo "Number = $NUMBER"
while (($NUMBER != $num ))
do
if (($NUMBER < $num ))
then
 echo "Too low"
else
 echo "Too high"
fi
 echo "Try again"
 read NUMBER
done
echo "Correct"
