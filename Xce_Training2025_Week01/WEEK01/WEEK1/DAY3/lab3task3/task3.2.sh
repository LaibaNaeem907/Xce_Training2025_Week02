#!/bin/bash

function fruits() {
      local fruit=("$@")    
      for i in "${fruit[@]}"
      do
          echo "$i"
      done
}

arr=("Apple" "banana" "mango" "strawberry" "peach")
result=$(fruits "${arr[@]}")
echo "fruits are $result"
echo "After adding new fruit"
arr+=("watermelon")
result=$(fruits "${arr[@]}")
echo "fruits are $result"
