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

# Checks operating system
OS=$(uname -s)
if [ "${OS}" == "" ]; then
    # Windows, WSL2
    PREFACE="UPDATE THE OS VERSION OF MAC"

elif [ ${OS} == "Darwin" ]; then
    # Mac
    PREFACE="Users"

else
    echo "OS isn't valid: $(uname -s) = \"${OS}\""
    exit 1
fi

TARGET="/${PREFACE}/${ME}/.bashrc"
echo "Starting:     $0"
echo "User running: ${ME}"
echo "From:         ${ME_PATH}"
echo
echo

# Checks arguments
BRC=".bashrc"
BPR=".bash_profile"
VRC=".vimrc"

if [[ "$#" -eq 0 ]]; then
    # Menu if no input from user
    echo "Select a file to update:"
    echo "    1: ${BRC}"
    echo "    2: ${BPR}"
    echo "    3: ${VRC}"
    echo
    read SELECTION


elif [[ "$#" -eq 1 ]]; then
    SELECTION=$1
    #echo "User Input: $SELECTION"

else
    echo "$# arguments not allowed"

fi


case ${SELECTION} in
    1)
        INPUT=${BRC}
        DEST_PATH="/${PREFACE}/${ME}/"
        ;;

    2)
        INPUT=${BPR}
        DEST_PATH="/${PREFACE}/${ME}/"
        ;;

    3)
        INPUT=${VRC}
        DEST_PATH="/${PREFACE}/${ME}/"
        ;;

    *)
        echo "$SELECTION is not a valid selection."
        ;;
esac


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


# TODO: Figure out how to source from this script
echo "Run 'source $TARGET' OR 'sbashrc' to update current session."
echo
echo

