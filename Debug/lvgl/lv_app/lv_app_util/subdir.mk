################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/lv_app/lv_app_util/lv_app_fsel.c \
../lvgl/lv_app/lv_app_util/lv_app_kb.c \
../lvgl/lv_app/lv_app_util/lv_app_notice.c 

OBJS += \
./lvgl/lv_app/lv_app_util/lv_app_fsel.o \
./lvgl/lv_app/lv_app_util/lv_app_kb.o \
./lvgl/lv_app/lv_app_util/lv_app_notice.o 

C_DEPS += \
./lvgl/lv_app/lv_app_util/lv_app_fsel.d \
./lvgl/lv_app/lv_app_util/lv_app_kb.d \
./lvgl/lv_app/lv_app_util/lv_app_notice.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/lv_app/lv_app_util/%.o: ../lvgl/lv_app/lv_app_util/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse_neon_cdt_workspace/proj_pc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


