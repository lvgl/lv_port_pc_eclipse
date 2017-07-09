################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../misc/fs/fat32/option/ccsbcs.c \
../misc/fs/fat32/option/syscall.c 

OBJS += \
./misc/fs/fat32/option/ccsbcs.o \
./misc/fs/fat32/option/syscall.o 

C_DEPS += \
./misc/fs/fat32/option/ccsbcs.d \
./misc/fs/fat32/option/syscall.d 


# Each subdirectory must supply rules for building sources it contributes
misc/fs/fat32/option/%.o: ../misc/fs/fat32/option/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse_neon_cdt_workspace/proj_pc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


