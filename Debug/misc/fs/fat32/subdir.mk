################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../misc/fs/fat32/fat32.c \
../misc/fs/fat32/ff.c 

OBJS += \
./misc/fs/fat32/fat32.o \
./misc/fs/fat32/ff.o 

C_DEPS += \
./misc/fs/fat32/fat32.d \
./misc/fs/fat32/ff.d 


# Each subdirectory must supply rules for building sources it contributes
misc/fs/fat32/%.o: ../misc/fs/fat32/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse_neon_workspace/lv_pc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


