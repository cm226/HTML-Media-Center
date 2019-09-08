#!/bin/bash

while  true
do

yes | cp /home/craig/Programming/arsehole/HTML-Media-Center/arsehole/bin/* /home/craig/bin/*

cd /home/craig/bin/

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/craig/bin
./arsehole

done