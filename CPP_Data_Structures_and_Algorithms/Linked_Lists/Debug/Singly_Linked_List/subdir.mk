################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Singly_Linked_List/Test_IntSLList.cpp \
../Singly_Linked_List/intSLList.cpp 

OBJS += \
./Singly_Linked_List/Test_IntSLList.o \
./Singly_Linked_List/intSLList.o 

CPP_DEPS += \
./Singly_Linked_List/Test_IntSLList.d \
./Singly_Linked_List/intSLList.d 


# Each subdirectory must supply rules for building sources it contributes
Singly_Linked_List/%.o: ../Singly_Linked_List/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


