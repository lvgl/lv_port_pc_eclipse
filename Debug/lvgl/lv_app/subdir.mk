################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/lv_app/lv_app.c 

OBJS += \
./lvgl/lv_app/lv_app.o 

C_DEPS += \
./lvgl/lv_app/lv_app.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/lv_app/%.o: ../lvgl/lv_app/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse_neon_workspace/lv_pc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


