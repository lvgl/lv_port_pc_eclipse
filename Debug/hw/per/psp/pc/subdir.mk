################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hw/per/psp/pc/psp_tft.c \
../hw/per/psp/pc/psp_tmr.c 

OBJS += \
./hw/per/psp/pc/psp_tft.o \
./hw/per/psp/pc/psp_tmr.o 

C_DEPS += \
./hw/per/psp/pc/psp_tft.d \
./hw/per/psp/pc/psp_tmr.d 


# Each subdirectory must supply rules for building sources it contributes
hw/per/psp/pc/%.o: ../hw/per/psp/pc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse-workspace/lv_dev_5" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


