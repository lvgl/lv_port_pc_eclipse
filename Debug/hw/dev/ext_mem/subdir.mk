################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hw/dev/ext_mem/sdcard.c 

OBJS += \
./hw/dev/ext_mem/sdcard.o 

C_DEPS += \
./hw/dev/ext_mem/sdcard.d 


# Each subdirectory must supply rules for building sources it contributes
hw/dev/ext_mem/%.o: ../hw/dev/ext_mem/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse_neon_cdt_workspace/proj_pc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


