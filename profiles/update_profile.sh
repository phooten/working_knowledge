echo "Starting: $0"
# If first argument isn't true, print warning

FILE=".bashrc"
# FILE=".bash_profile"

# Update .file
# rm ~/${FILE}
cp ${FILE} ~/${FILE}

# ./source.sh
source ~/${FILE}
exec bash
