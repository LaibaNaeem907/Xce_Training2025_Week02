#!/bin/bash
function factorial() {
       num=$1;
       ans=1
      for (( i=num; i>=1; i--))
       do
         ans=$((ans*i))
      done
      echo $ans
}
answer=$(factorial 3)
echo "answer = $answer"
answer=$(factorial 4)
echo "answer = $answer"
