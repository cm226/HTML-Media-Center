################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Plugins/AudioGenraClasifier/source/AudioClasifier.cpp \
../Plugins/AudioGenraClasifier/source/Mp3Decoder.cpp 

OBJS += \
./Plugins/AudioGenraClasifier/source/AudioClasifier.o \
./Plugins/AudioGenraClasifier/source/Mp3Decoder.o 

CPP_DEPS += \
./Plugins/AudioGenraClasifier/source/AudioClasifier.d \
./Plugins/AudioGenraClasifier/source/Mp3Decoder.d 


# Each subdirectory must supply rules for building sources it contributes
Plugins/AudioGenraClasifier/source/%.o: ../Plugins/AudioGenraClasifier/source/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__STDC_CONSTANT_MACROS -O0 -g3 -Wall -c -fmessage-length=0  `sdl-config --cflags --libs` -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


