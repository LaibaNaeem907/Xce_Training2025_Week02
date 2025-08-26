#!/bin/bash
log="task4.2.txt"
echo "Total entries:"
wc -l < "$log"
echo "Unique users:"
cut -d' ' -f2 "$log" | sort | uniq
echo "Actions per user:"
cut -d' ' -f2 "$log" | sort | uniq -c