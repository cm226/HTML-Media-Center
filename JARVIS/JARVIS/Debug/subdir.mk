################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../JARVIS.cpp 

OBJS += \
./JARVIS.o 

CPP_DEPS += \
./JARVIS.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__STDC_CONSTANT_MACROS -I/home/craig/curl-7.28.1/include/curl -I/usr/include/ -I/home/craig/Documents/Projects/mysql-connector-c++-1.1.7 -I/home/craig/Documents/Projects/boost_1_60_0 -O0 -g3 -Wall -c -fmessage-length=0  `sdl-config --cflags --libs` -rdynamic -std=c++0x -Wno-unknown-pragmas -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


