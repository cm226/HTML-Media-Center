#!/bin/bash

echo 'Fetching Certs from NAS'

HOST=192.168.1.72
USER=craig
echo 'Enter password for NAS:'
read PASSWORD

ftp -inv $HOST <<EOF
user $USER $PASSWORD
cd /homes/SSL
mget test.*
bye
EOF