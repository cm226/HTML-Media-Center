#!/bin/bash

mkdir -p /home/craig/bin/

while  true
do

yes | cp -r /home/craig/Programming/arsehole/HTML-Media-Center/arsehole/bin/* /home/craig/bin/

cd /home/craig/bin/

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/craig/bin
./arsehole

echo "Waiting for interupt before restarting server"
sleep 10s

done