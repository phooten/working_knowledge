Purpose: 
	Have a program run that will open Brave Browser and refresh the page 20 
	times. Every 4th refresh, an ad will show up on the home page which will 
	give the user 0.010 BAT, IF there is a linked wallet.  


WSL2:
	Pre-Requirements:
		1. WSL2 is installed (WSL might work, but hasn't been tested)
		2. gnome is installed
		3. Xlaunch is installed and running
		4. xdotools is installed

	Issues:
		1.  if brave-browser is running in any other terminal, the new window 
			created from dummyTerminal.sh won't close.
		2.  brave-browser will open to what ever the last window was, so if it's
			not on the home page, there will be no rewards and youll just keep 
			reloading the same page 

	
Windows:
	Pre-Requirements:
		1. The file path to brave.exe needs to be changed 

	Issues:
		1.  


		