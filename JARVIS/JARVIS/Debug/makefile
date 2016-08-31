################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Framework/Plugin/Loader/subdir.mk
-include Framework/Plugin/subdir.mk
-include Framework/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: JARVIS

# Tool invocations
JARVIS: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++ -L"/var/www/html/HTML-Media-Center/JARVIS/Comms/Debug" -L"/var/www/html/HTML-Media-Center/JARVIS/MediaStreaming/MediaStreaming/Debug" -L"/var/www/html/HTML-Media-Center/JARVIS/ErrorLogger/Debug" -L/usr/lib -L/home/craig/curl-7.28.1/lib/.libs -L/home/craig/Documents/Projects/boost_1_60_0/stage/lib -L"/var/www/html/HTML-Media-Center/JARVIS/JARVISCoreModules/Debug" -L/home/media/Documents/Projects/mysql-connector-c++-1.1.7/driver -Xlinker --export-dynamic -o "JARVIS" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(C_UPPER_DEPS)$(CXX_DEPS)$(OBJS)$(CPP_DEPS)$(C_DEPS) JARVIS
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
