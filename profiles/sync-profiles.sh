#!/bin/bash
# Syncs all profiles listed. For single profile, see "update-single-profile.sh"



# TODO: Figure out how to pass this as a variable
# FLAG=""
# if [ $# == 1 ] && [ $1 == "sh" ]; then
#	FLAG=">/dev/null 2>&1"
# fi

# argument checking
if [ $# -ne 1 ] && [ $# -ne 0 ]; then
	echo "Zero or one argument can be used."
	exit 1
fi
FLAG=$1

# Start statement
echo
echo "------------------------------------------------"
echo "This script will sync all profiles listed below."
echo "To un-supress the messages, rerun the script with"
echo "'v' as the argument. Note that no files will be"
echo "sourced. This must be done manually."
echo
echo "usage:"
echo "	1:	'./sync-profile.sh v'"
echo "	2:	'./sync-profile.sh'"
echo
echo "- - - - - - - - - - - - - - - - - - - - - - - - -"
echo "List to synced:"
echo "		.bashrc"
echo
echo "------------------------------------------------"
echo
echo

for OPT in 1; do
	if [ "$FLAG" = "v" ]; then
		./update-single-profile.sh ${OPT} 
	else
		./update-single-profile.sh ${OPT} >/dev/null 2>&1
	fi
done
