################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Transever/AbstractTransever.cpp \
../Transever/ITranseverConnection.cpp \
../Transever/ITranseverConnectionFactory.cpp \
../Transever/MessageChunker.cpp \
../Transever/TCPAsyncTransever.cpp 

OBJS += \
./Transever/AbstractTransever.o \
./Transever/ITranseverConnection.o \
./Transever/ITranseverConnectionFactory.o \
./Transever/MessageChunker.o \
./Transever/TCPAsyncTransever.o 

CPP_DEPS += \
./Transever/AbstractTransever.d \
./Transever/ITranseverConnection.d \
./Transever/ITranseverConnectionFactory.d \
./Transever/MessageChunker.d \
./Transever/TCPAsyncTransever.d 


# Each subdirectory must supply rules for building sources it contributes
Transever/%.o: ../Transever/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/media/Documents/Projects/boost_1_60_0 -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


