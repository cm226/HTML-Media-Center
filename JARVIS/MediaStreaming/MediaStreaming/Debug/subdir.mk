################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../MediaStreamer.cpp \
../MusicPlaylist.cpp \
../Song.cpp \
../VLCTelnetInterface.cpp \
../telnet.cpp 

OBJS += \
./MediaStreamer.o \
./MusicPlaylist.o \
./Song.o \
./VLCTelnetInterface.o \
./telnet.o 

CPP_DEPS += \
./MediaStreamer.d \
./MusicPlaylist.d \
./Song.d \
./VLCTelnetInterface.d \
./telnet.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -Dlinux -I/home/craig/Documents/Projects/boost_1_60_0 -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -Wno-unknown-pragmas -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


