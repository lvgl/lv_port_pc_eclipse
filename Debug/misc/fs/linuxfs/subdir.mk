################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../misc/fs/linuxfs/linuxfs.c 

OBJS += \
./misc/fs/linuxfs/linuxfs.o 

C_DEPS += \
./misc/fs/linuxfs/linuxfs.d 


# Each subdirectory must supply rules for building sources it contributes
misc/fs/linuxfs/%.o: ../misc/fs/linuxfs/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse_neon_workspace/lv_proj_pc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


