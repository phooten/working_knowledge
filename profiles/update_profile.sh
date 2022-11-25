# !/bin/bash

# Purpose:
#   Allows user change profile settings inside working_knowledge directory
#   then update the file for the machine.
#
# Example Usage:
#   
#   



# General Setup
ME=$( whoami )
ME_PATH=$( pwd )

TARGET="/Users/${ME}/.bashrc"
echo "Starting:     $0"
echo "User running: ${ME}"
echo "From:         ${ME_PATH}"
echo
echo

# Checks arguments
if [[ "$#" -eq 0 ]]; then

    # Menu if no input from user
    echo "Select a file to update:"
    echo "    1: .bashrc"
    echo "    2: .bash_profile"
    echo
    read SELECTION

    case ${SELECTION} in
        1)
            INPUT=".bashrc"
            DEST_PATH="/Users/${ME}/"
            ;;

        2)
            INPUT=".bash_profile"
            DEST_PATH="/Users/${ME}/"
            ;;

        *)
            echo "$SELECTION is not a valid selection."
            ;;
    esac

elif [[ "$#" -eq 1 ]]; then
    # TODO: Check if input file exists
    read INPUT
    echo "User Input: $INPUT"

else
    echo "$# arguments not allowed"

fi


TARGET=${DEST_PATH}${INPUT}
#TODO: Find out why "~/" doesn't work here.
if [ ! -f $TARGET ]; then
    echo "$TARGET does not exist. Exiting script."
    exit 1
fi
FILE=${INPUT}

# Copies File over to proper location
echo
echo "Copying '${ME_PATH}$FILE' to '$TARGET'"
echo
cp $FILE $TARGET
#cp .bashrc Users/phoot/.bashrc

# TODO: Figure out how to source from this script
echo "Run 'source $TARGET' to update current session."
# source ~/${FILE}
# exec bash
