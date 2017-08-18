################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hw/dev/ui/buzzer.c \
../hw/dev/ui/led.c \
../hw/dev/ui/log.c 

OBJS += \
./hw/dev/ui/buzzer.o \
./hw/dev/ui/led.o \
./hw/dev/ui/log.o 

C_DEPS += \
./hw/dev/ui/buzzer.d \
./hw/dev/ui/led.d \
./hw/dev/ui/log.d 


# Each subdirectory must supply rules for building sources it contributes
hw/dev/ui/%.o: ../hw/dev/ui/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse_neon_workspace/lv_proj_pc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


