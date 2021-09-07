# Opens tasklist and filters out brave.exe. 
# /V shows verbose information
# tasklist.exe /FI "IMAGENAME eq brave.exe" /FI "STATUS eq RUNNING" /V
# tasklist.exe /FI "WINDOWTITLE eq New Tab - Brave" /V /fo csv
# tasklist.exe /FI "WINDOWTITLE eq New Tab - Brave" /fo list | grep PID


# opens up a new terminal and runs brave
gnome-terminal -- ./closeTerminal.sh

# variables
MIN=0
MAX=5

# Pauses the Program
for i in $( seq $MIN $MAX)
do 
    echo $i
    xdotool getactivewindow key ctrl+r
    sleep 1
done