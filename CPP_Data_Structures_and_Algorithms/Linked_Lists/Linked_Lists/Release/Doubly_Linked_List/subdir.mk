################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Doubly_Linked_List/Test_DoublyLinkedList.cpp 

OBJS += \
./Doubly_Linked_List/Test_DoublyLinkedList.o 

CPP_DEPS += \
./Doubly_Linked_List/Test_DoublyLinkedList.d 


# Each subdirectory must supply rules for building sources it contributes
Doubly_Linked_List/%.o: ../Doubly_Linked_List/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


