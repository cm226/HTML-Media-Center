#!/bin/sh
cd /home/craig/Programming/boost_1_58_0 
./bootstrap.sh --with-toolset=clang

if [ $1 = "Debug" ]; then
echo "Building Debug"
./b2 --prefix=/usr -j 4 link=shared runtime-link=shared runtime-debugging=on toolset=clang cxxflags="-std=c++14 -stdlib=libstdc++ -Wno-register" linkflags="-lstdc++" threading=multi --layout=tagged --without-python --variant=debug install
else
echo "Building release" 
./b2 --prefix=/usr -j 4 link=shared runtime-link=shared toolset=clang cxxflags="-std=c++14 -stdlib=libstdc++ -Wno-register" linkflags="-lstdc++" threading=multi --layout=tagged --without-python install
fi
