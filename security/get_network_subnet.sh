



SUBNET_MASK=$(ifconfig wlan0 | awk '/netmask/{ print $4;} ')
ME_IPV4=$(ifconfig wlan0 | awk '/inet /{ print $2;} ')
NETWORK_IPV4=""

echo "My IPv4:     ${ME_IPV4}"
echo "Subnet Mask:  ${SUBNET_MASK}"


exit 1

# Scan Network
nmap -sn 
