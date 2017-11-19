################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../misc/comm/gsmmng.c \
../misc/comm/wifimng.c 

OBJS += \
./misc/comm/gsmmng.o \
./misc/comm/wifimng.o 

C_DEPS += \
./misc/comm/gsmmng.d \
./misc/comm/wifimng.d 


# Each subdirectory must supply rules for building sources it contributes
misc/comm/%.o: ../misc/comm/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse-workspace/lv_dev_5" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


