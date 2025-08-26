#!/bin/bash
declare -A capital=(
    [pakistan]="Islamabad"
    [India]="Delhi"
    [China]="Beijing"
    [UK]="London")

function capitals() {
  local -n copy=$1
  local name=$2

  for country in "${!copy[@]}"; do
    if [[ "$name" == "$country" ]]; then
      echo "$country = ${copy[$country]}"
      return
    fi
  done
  echo "not available"

}

read -p "Enter country: " Name
capitals capital "$Name"

 



