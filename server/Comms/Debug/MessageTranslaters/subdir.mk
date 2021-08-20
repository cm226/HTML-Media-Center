################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../MessageTranslaters/StringMessageSerializer.cpp 

OBJS += \
./MessageTranslaters/StringMessageSerializer.o 

CPP_DEPS += \
./MessageTranslaters/StringMessageSerializer.d 


# Each subdirectory must supply rules for building sources it contributes
MessageTranslaters/%.o: ../MessageTranslaters/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/media/Documents/Projects/boost_1_60_0 -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


