################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../database.cpp \
../main.cpp \
../personal.cpp \
../student.cpp \
../test.cpp 

OBJS += \
./database.o \
./main.o \
./personal.o \
./student.o \
./test.o 

CPP_DEPS += \
./database.d \
./main.d \
./personal.d \
./student.d \
./test.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


