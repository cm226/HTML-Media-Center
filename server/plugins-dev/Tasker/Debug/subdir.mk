################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../AddTaskPage.cpp \
../Tasker.cpp \
../TaskerPlugin.cpp \
../someRandClass.cpp 

OBJS += \
./AddTaskPage.o \
./Tasker.o \
./TaskerPlugin.o \
./someRandClass.o 

CPP_DEPS += \
./AddTaskPage.d \
./Tasker.d \
./TaskerPlugin.d \
./someRandClass.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/craig/Documents/Projects/boost_1_60_0 -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


