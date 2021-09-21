#!/bin/bash

cd /home/craig/Programming/Server/HTML-Media-Center/Server/ServerCoreModules/ \
&& ./build $1 \
&& cd /home/craig/Programming/Server/HTML-Media-Center/Server/Server \
&& ./build $1 \
&& cd /home/craig/Programming/Server/HTML-Media-Center/Server/plugins-dev/Shopping \
&& ./build $1 \
&& cd /home/craig/Programming/Server/HTML-Media-Center/Server/plugins-dev/AutoUpdater \
&& ./build $1 \
&& cd /home/craig/Programming/Server/HTML-Media-Center/Server/plugins-dev/ClientLoger \
&& ./build $1 \
&& cd /home/craig/Programming/Server/HTML-Media-Center/Server/plugins-dev/LogViewer \
&& ./build $1 \
&& cd /home/craig/Programming/Server/HTML-Media-Center/Server/plugins-dev/LightingController \
&& ./build $1 \
&& cd /home/craig/Programming/Server/HTML-Media-Center/Server/plugins-dev/Weather \
&& ./build $1 \
&& cd /home/craig/Programming/Server/HTML-Media-Center/Server/plugins-dev/ConfigEditor \
&& ./build $1 \
&& cd /home/craig/Programming/Server/HTML-Media-Center/Server/Server/Framework/Static_content/app \
&& npm run build \

if [ $? -eq 0 ]
then
    version=$(git rev-parse HEAD)
    echo "Build Successful updating version to $version"
    sed -i "s/Version=.*/Version=$version/g" /home/craig/Programming/Server/HTML-Media-Center/Server/bin/config.ini
fi


exit