#!/bin/bash
#
# ROOTPATH="~/../../"
# BROWSER=/mnt/c/'Program Files'/BraveSoftware/Brave-Browser/Application/

#Variables 
RELOAD_KEYS="CTRL+R"
FILENAME="new.txt"
COUNT=20
TIMER=0.75


for i in $( seq 1 $COUNT)
do 
    # Navigates and executes brave
    # cd ~/../../mnt/c/'Program Files'/BraveSoftware/Brave-Browser/Application/
    # ./brave.exe
    # cd ~/General-Practice/scripts/
    ~/../../mnt/c/'Program Files'/BraveSoftware/Brave-Browser/Application/brave.exe
    sleep $TIMER

    # Gets the PID of the last opened brave browser and closes it. 
    # #       - tasklist.exe -> launches all tasks opened in windows from wsl
    # #       - Search: "taskkill.exe usage" for helps
    task=$(tasklist.exe /FI "WINDOWTITLE eq New Tab - Brave" /fo list | grep PID)   # Filters everything from tasklist.exe but new brave tabs, keeping just PID line: "PID:    1234\r" 
    echo $task >> "$FILENAME"

    result=$(awk 'END {print $NF}' "$FILENAME")                                     # Takes the last word from PID line: "1234\r"
    rm "$FILENAME"
    echo $result >> "$FILENAME"

    number=$(awk '{print $1; exit}' "$FILENAME")                                    # Removes the \r from the only word in the file
    pid=`echo $number | sed 's/\\r//g'`
    echo $pid
    rm "$FILENAME"
    taskkill.exe /PID "$pid"
done
