echo "Starting: $0"
# If first argument isn't true, print warning

FILE=".bashrc"

# Update .bashrc
rm ~/${FILE}
cp ${FILE} ~/${FILE}

# ./source.sh
source ~/${FILE}
exec bash
