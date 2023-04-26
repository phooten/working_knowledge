#!/bin/bash
usage() { echo "
###############################################################################
#   FILE:       
#
#   PURPOSE:    
#
#   PARAMETERS: None
#
#   MODIFICATION HISTORY:
#       2023-04-26  <user>  <brief>
#
###############################################################################
">&2; exit; }; [ "$1" = "help" ] && usage

read -p "Input file name: " FILE_NAME
ME=$(whoami)
NOW=$(printf '%(%y-%m-%d)T\n' -1)


# Inputs variables into header
ShowTemplate() { echo "
###############################################################################
#
#   FILE:       ${FILE_NAME}
#
#   PURPOSE:    None.
#
#   PARAMETERS: None.
#
#   MODIFICATION HISTORY:
#       ${NOW}  ${ME}  Original creation.
#
###############################################################################
\">&2; exit; }; [ \"\$1\" = \"help\" ] && usage
"


# C++ - cpp / hpp



# Python
# Google coding standard: https://google.github.io/styleguide/pyguide.html
# File Header:
#"""A one-line summary of the module or program, terminated by a period.
#
#Leave one blank line.  The rest of this docstring should contain an
#overall description of the module or program.  Optionally, it may also
#contain a brief description of exported classes and functions and/or usage
#examples.
#
#Typical usage example:
#
#  foo = ClassFoo()
#  bar = foo.FunctionBar()
#"""


echo
echo
echo '------------------------------------------------------------------------'
echo "End of script."
echo
echo









