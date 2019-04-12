#!/bin/bash

cd /home/craig/Programming/JARVIS/HTML-Media-Center/JARVIS/JARVISCoreModules/ \
&& ./build $1 \
&& cd /home/craig/Programming/JARVIS/HTML-Media-Center/JARVIS/JARVIS \
&& ./build $1 \
&& cd /home/craig/Programming/JARVIS/HTML-Media-Center/JARVIS/plugins-dev/Shopping \
&& ./build $1 \
&& cd /home/craig/Programming/JARVIS/HTML-Media-Center/JARVIS/plugins-dev/AutoUpdater \
&& ./build $1 \
&& cd /home/craig/Programming/JARVIS/HTML-Media-Center/JARVIS/plugins-dev/ClientLoger \
&& ./build $1 \
&& cd /home/craig/Programming/JARVIS/HTML-Media-Center/JARVIS/plugins-dev/LogViewer \
&& ./build $1 \

exit