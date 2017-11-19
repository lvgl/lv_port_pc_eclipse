################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../misc/os/idle.c \
../misc/os/ptask.c 

OBJS += \
./misc/os/idle.o \
./misc/os/ptask.o 

C_DEPS += \
./misc/os/idle.d \
./misc/os/ptask.d 


# Each subdirectory must supply rules for building sources it contributes
misc/os/%.o: ../misc/os/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse-workspace/lv_dev_5" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


