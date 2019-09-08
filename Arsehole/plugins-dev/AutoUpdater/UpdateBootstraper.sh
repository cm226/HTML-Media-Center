#!/bin/bash

while  true
do

yes | cp /home/craig/Programming/Arsehole/HTML-Media-Center/Arsehole/bin/* /home/craig/bin/*

cd /home/craig/bin/

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/craig/bin
./Arsehole

done