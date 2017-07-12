################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hw/dev/tp/FT5406EE8.c \
../hw/dev/tp/XPT2046.c \
../hw/dev/tp/mouse.c 

OBJS += \
./hw/dev/tp/FT5406EE8.o \
./hw/dev/tp/XPT2046.o \
./hw/dev/tp/mouse.o 

C_DEPS += \
./hw/dev/tp/FT5406EE8.d \
./hw/dev/tp/XPT2046.d \
./hw/dev/tp/mouse.d 


# Each subdirectory must supply rules for building sources it contributes
hw/dev/tp/%.o: ../hw/dev/tp/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse_neon_workspace/lv_pc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


