################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Plugins/Plugin.cpp 

OBJS += \
./Plugins/Plugin.o 

CPP_DEPS += \
./Plugins/Plugin.d 


# Each subdirectory must supply rules for building sources it contributes
Plugins/%.o: ../Plugins/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__STDC_CONSTANT_MACROS -O0 -g3 -Wall -c -fmessage-length=0  `sdl-config --cflags --libs` -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


