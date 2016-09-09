################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Devices/Comms/MessageTranslaters/StringMessageSerializer.cpp 

OBJS += \
./Devices/Comms/MessageTranslaters/StringMessageSerializer.o 

CPP_DEPS += \
./Devices/Comms/MessageTranslaters/StringMessageSerializer.d 


# Each subdirectory must supply rules for building sources it contributes
Devices/Comms/MessageTranslaters/%.o: ../Devices/Comms/MessageTranslaters/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -Dlinux -I/home/craig/Documents/Projects/boost_1_60_0 -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -Wno-unknown-pragmas -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


