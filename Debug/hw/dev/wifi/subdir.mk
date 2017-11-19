################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hw/dev/wifi/esp8266.c 

OBJS += \
./hw/dev/wifi/esp8266.o 

C_DEPS += \
./hw/dev/wifi/esp8266.d 


# Each subdirectory must supply rules for building sources it contributes
hw/dev/wifi/%.o: ../hw/dev/wifi/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse-workspace/lv_dev_5" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


