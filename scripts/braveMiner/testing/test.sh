#!/bin/bash

#Variables 
RELOAD_KEYS="CTRL+R"
FILENAME="new.txt"
TIMER=3

# Navigates and executes brave
~/brave.exe
sleep $TIMER

# Gets the PID of the last opened brave browser by filtering everything from tasklist.exe 
task=$(tasklist.exe /FI "WINDOWTITLE eq New Tab - Brave" /fo list | grep PID)    
echo $task >> "$FILENAME"

# Takes the last word from PID line: "1234\r"
result=$(awk 'END {print $NF}' "$FILENAME")
rm "$FILENAME"
echo $result >> "$FILENAME"

# Removes the \r from the only word in the file
number=$(awk '{print $1; exit}' "$FILENAME")                                   
pid=`echo $number | sed 's/\\r//g'`
echo $pid
rm "$FILENAME"


content=$(wget brave://rewards/ -q -O -)
echo $content
