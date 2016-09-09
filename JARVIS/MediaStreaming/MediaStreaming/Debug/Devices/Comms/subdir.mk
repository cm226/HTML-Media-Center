################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Devices/Comms/Broadcaster.cpp \
../Devices/Comms/DevicePollConnection.cpp \
../Devices/Comms/DevicePollConnectionFactory.cpp \
../Devices/Comms/GetLanIPLinux.cpp \
../Devices/Comms/IPGetter.cpp 

OBJS += \
./Devices/Comms/Broadcaster.o \
./Devices/Comms/DevicePollConnection.o \
./Devices/Comms/DevicePollConnectionFactory.o \
./Devices/Comms/GetLanIPLinux.o \
./Devices/Comms/IPGetter.o 

CPP_DEPS += \
./Devices/Comms/Broadcaster.d \
./Devices/Comms/DevicePollConnection.d \
./Devices/Comms/DevicePollConnectionFactory.d \
./Devices/Comms/GetLanIPLinux.d \
./Devices/Comms/IPGetter.d 


# Each subdirectory must supply rules for building sources it contributes
Devices/Comms/%.o: ../Devices/Comms/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -Dlinux -I/home/craig/Documents/Projects/boost_1_60_0 -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -Wno-unknown-pragmas -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


