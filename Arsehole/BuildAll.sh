#!/bin/bash

cd /home/craig/Programming/Arsehole/HTML-Media-Center/Arsehole/ArseholeCoreModules/ \
&& ./build $1 \
&& cd /home/craig/Programming/Arsehole/HTML-Media-Center/Arsehole/Arsehole \
&& ./build $1 \
&& cd /home/craig/Programming/Arsehole/HTML-Media-Center/Arsehole/plugins-dev/Shopping \
&& ./build $1 \
&& cd /home/craig/Programming/Arsehole/HTML-Media-Center/Arsehole/plugins-dev/AutoUpdater \
&& ./build $1 \
&& cd /home/craig/Programming/Arsehole/HTML-Media-Center/Arsehole/plugins-dev/ClientLoger \
&& ./build $1 \
&& cd /home/craig/Programming/Arsehole/HTML-Media-Center/Arsehole/plugins-dev/LogViewer \
&& ./build $1 \
&& cd /home/craig/Programming/Arsehole/HTML-Media-Center/Arsehole/plugins-dev/LightingController \
&& ./build $1 \

if [ $? -eq 0 ]
then
    version=$(git rev-parse HEAD)
    sed -i "s/Version=*\n/Version=$version/g" /home/craig/Programming/Arsehole/HTML-Media-Center/Arsehole/bin/config.ini
fi


exit