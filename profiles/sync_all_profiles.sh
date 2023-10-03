#!/bin/bash
# Syncs all profiles listed. For single profile, see "update-single-profile.sh"



# TODO: Figure out how to pass this as a variable
# FLAG=""
# if [ $# == 1 ] && [ $1 == "sh" ]; then
#    FLAG=">/dev/null 2>&1"
# fi

# argument checking
if [ $# -ne 1 ] && [ $# -ne 0 ]; then
    echo "Zero or one argument can be used."
    exit 1
fi
FLAG=$1


SSP_NAME="sync_single_profile.sh"
CURR_PATH="$(pwd)"
SSP_PATH="${CURR_PATH}/${SSP_NAME}"

# Start statement
echo
echo "------------------------------------------------"
echo "This script will sync all profiles listed below."
echo "To un-supress the messages, rerun the script with"
echo "'v' as the argument. Note that no files will be"
echo "sourced. This must be done manually."
echo
echo "usage:"
echo "    1:    './${SSP_NAME} v'"
echo "    2:    './${SSP_NAME}'"
echo
echo "- - - - - - - - - - - - - - - - - - - - - - - - -"
echo "List to synced:"
echo "        .bashrc"
echo "        .vimrc"
echo 
echo "------------------------------------------------"
echo
echo

# Check to make sure single hasn't been changed
if [[ ! -f ${SSP_PATH} ]]; then
    echo "The script '${SSP_NAME}' name might have changed."
    echo "See '$(pwd)' and ensure '${SSP_NAME}' exists."
    echo "Exiting script."
    exit 1
fi

for OPT in 1 3; do
    if [ "$FLAG" = "v" ]; then
        CMD="${SSP_PATH} ${OPT}"
    else
        CMD="${SSP_PATH} ${OPT} >/dev/null 2>&1"
    fi
    echo "Running this command: '${CMD}'"
    # TODO : keep getting this message './sync_all_profiles.sh: line 60: This: command not found'
    $(${CMD})
done
