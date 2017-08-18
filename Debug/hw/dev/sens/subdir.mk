################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hw/dev/sens/icm20602.c 

OBJS += \
./hw/dev/sens/icm20602.o 

C_DEPS += \
./hw/dev/sens/icm20602.d 


# Each subdirectory must supply rules for building sources it contributes
hw/dev/sens/%.o: ../hw/dev/sens/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse_neon_workspace/lv_proj_pc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


