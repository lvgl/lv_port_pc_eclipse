################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hw/dev/gsm/sim5320.c 

OBJS += \
./hw/dev/gsm/sim5320.o 

C_DEPS += \
./hw/dev/gsm/sim5320.d 


# Each subdirectory must supply rules for building sources it contributes
hw/dev/gsm/%.o: ../hw/dev/gsm/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse_neon_workspace/lv_pc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


