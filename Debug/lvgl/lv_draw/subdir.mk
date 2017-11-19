################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/lv_draw/lv_draw.c \
../lvgl/lv_draw/lv_draw_rbasic.c \
../lvgl/lv_draw/lv_draw_vbasic.c 

OBJS += \
./lvgl/lv_draw/lv_draw.o \
./lvgl/lv_draw/lv_draw_rbasic.o \
./lvgl/lv_draw/lv_draw_vbasic.o 

C_DEPS += \
./lvgl/lv_draw/lv_draw.d \
./lvgl/lv_draw/lv_draw_rbasic.d \
./lvgl/lv_draw/lv_draw_vbasic.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/lv_draw/%.o: ../lvgl/lv_draw/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse-workspace/lv_dev_5" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


