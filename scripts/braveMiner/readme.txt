Purpose: 
	Easily earn BAT from reloading brave homepage every hour ~20 times to get 0.020 BAT.
	The WSL script runs brave through xserv and linux. The windows script navigates to the 
	windows partition and performs a similar task, but executed differently.

Prereq Libraries:
	- puppeteer: https://github.com/puppeteer/puppeteer
	- nvm, Node.js, npm: https://docs.microsoft.com/en-us/windows/dev-environment/javascript/nodejs-on-wsl
	- yarn



Organize Notes:

	chrontab:
		- Helpful links:
			- Installation for WSL 2: https://www.howtogeek.com/746532/how-to-launch-cron-automatically-in-wsl-on-windows-10-and-11/ 
			- Utility: https://www.youtube.com/watch?v=llUw3RtD-Yw
		- crontab -e 				: adds a new task to run
		- sudo service cron start 	: starts running cron
		- sudo service cron start 	: starts running cron
		- service cron status 		: shows cron status 

	xserver:
		- Helpful Links:
			- Installation for WSL 2: https://techcommunity.microsoft.com/t5/windows-dev-appconsult/running-wsl-gui-apps-on-windows-10/ba-p/1493242
			- Installation for WSL 2: https://www.youtube.com/watch?v=4SZXbl9KVsw
		- IP ADDRESS FOR WINDOWS MACHINE: cat /etc/resolv.conf
			1: nameserver
			2: nameserver
			3: nameserver
		- export DISPLAY="`grep nameserver /etc/resolv.conf | sed 's/nameserver //'`:0"

	Other 
		- chmod +x testminer.sh 	: gives access to the bash file to be ran
		- ls -lsa			
	


