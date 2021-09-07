#!/bin/bash
#
# ROOTPATH="~/../../"
# BROWSER=/mnt/c/'Program Files'/BraveSoftware/Brave-Browser/Application/

#Variables 
RELOAD_KEYS="CTRL+R"
MIN=0
MAX=5

# Navigates and executes brave
# cd ~/../../mnt/c/'Program Files'/BraveSoftware/Brave-Browser/Application/
# ./brave.exe
# cd ~/General-Practice/scripts/
~/../../mnt/c/'Program Files'/BraveSoftware/Brave-Browser/Application/brave.exe

# Pauses the Program
for i in $( seq $MIN $MAX)
do 
    echo $i
    sleep 1
    xdotool key CTRL+R    
done


# Gets the PID of the last opened brave browser and closes it. 
# #       - tasklist.exe -> launches all tasks opened in windows from wsl
# #       - Search: "taskkill.exe usage" for helps
filename="new.txt"
task=$(tasklist.exe /FI "WINDOWTITLE eq New Tab - Brave" /fo list | grep PID)   # Filters everything from tasklist.exe but new brave tabs, keeping just PID line: "PID:    1234\r" 
echo $task >> "$filename"

result=$(awk 'END {print $NF}' "$filename")                                     # Takes the last word from PID line: "1234\r"
rm "$filename"
echo $result >> "$filename"

number=$(awk '{print $1; exit}' "$filename")                                    # Removes the \r from the only word in the file
pid=`echo $number | sed 's/\\r//g'`
echo $pid
rm "$filename"

taskkill.exe /PID "$pid"

