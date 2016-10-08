################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Devices/Comms/Transever/AbstractTransever.cpp \
../Devices/Comms/Transever/ITranseverConnection.cpp \
../Devices/Comms/Transever/ITranseverConnectionFactory.cpp \
../Devices/Comms/Transever/MessageChunker.cpp \
../Devices/Comms/Transever/TCPAsyncTransever.cpp 

OBJS += \
./Devices/Comms/Transever/AbstractTransever.o \
./Devices/Comms/Transever/ITranseverConnection.o \
./Devices/Comms/Transever/ITranseverConnectionFactory.o \
./Devices/Comms/Transever/MessageChunker.o \
./Devices/Comms/Transever/TCPAsyncTransever.o 

CPP_DEPS += \
./Devices/Comms/Transever/AbstractTransever.d \
./Devices/Comms/Transever/ITranseverConnection.d \
./Devices/Comms/Transever/ITranseverConnectionFactory.d \
./Devices/Comms/Transever/MessageChunker.d \
./Devices/Comms/Transever/TCPAsyncTransever.d 


# Each subdirectory must supply rules for building sources it contributes
Devices/Comms/Transever/%.o: ../Devices/Comms/Transever/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -Dlinux -I/home/craig/Documents/Projects/boost_1_60_0 -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -Wno-unknown-pragmas -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


