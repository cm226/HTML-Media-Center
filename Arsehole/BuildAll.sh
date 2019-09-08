#!/bin/bash

cd /home/craig/Programming/arsehole/HTML-Media-Center/arsehole/arseholeCoreModules/ \
&& ./build $1 \
&& cd /home/craig/Programming/arsehole/HTML-Media-Center/arsehole/arsehole \
&& ./build $1 \
&& cd /home/craig/Programming/arsehole/HTML-Media-Center/arsehole/plugins-dev/Shopping \
&& ./build $1 \
&& cd /home/craig/Programming/arsehole/HTML-Media-Center/arsehole/plugins-dev/AutoUpdater \
&& ./build $1 \
&& cd /home/craig/Programming/arsehole/HTML-Media-Center/arsehole/plugins-dev/ClientLoger \
&& ./build $1 \
&& cd /home/craig/Programming/arsehole/HTML-Media-Center/arsehole/plugins-dev/LogViewer \
&& ./build $1 \
&& cd /home/craig/Programming/arsehole/HTML-Media-Center/arsehole/plugins-dev/LightingController \
&& ./build $1 \

exit