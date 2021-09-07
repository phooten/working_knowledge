# Opens tasklist and filters out brave.exe. 
# /V shows verbose information
# tasklist.exe /FI "IMAGENAME eq brave.exe" /FI "STATUS eq RUNNING" /V
# tasklist.exe /FI "WINDOWTITLE eq New Tab - Brave" /V /fo csv
# tasklist.exe /FI "WINDOWTITLE eq New Tab - Brave" /fo list | grep PID
echo "hello world" >> example.txt


# opens up a new terminal and runs brave
gnome-terminal -- ./dummyTerminal.sh

pid=$(pgrep -f gnome-terminal)

count=30
time=0.2
for i in $( seq 0 $count)
do 
    echo $i
    sleep $time
    xdotool key CTRL+R    
done

kill "$pid"

# ./~/General-Practice/scripts/batMiner_wsl.sh