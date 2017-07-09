################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/lv_appx/lv_app_benchmark.c \
../lvgl/lv_appx/lv_app_example.c \
../lvgl/lv_appx/lv_app_files.c \
../lvgl/lv_appx/lv_app_gsm.c \
../lvgl/lv_appx/lv_app_phantom.c \
../lvgl/lv_appx/lv_app_sysmon.c \
../lvgl/lv_appx/lv_app_terminal.c \
../lvgl/lv_appx/lv_app_wifi.c 

OBJS += \
./lvgl/lv_appx/lv_app_benchmark.o \
./lvgl/lv_appx/lv_app_example.o \
./lvgl/lv_appx/lv_app_files.o \
./lvgl/lv_appx/lv_app_gsm.o \
./lvgl/lv_appx/lv_app_phantom.o \
./lvgl/lv_appx/lv_app_sysmon.o \
./lvgl/lv_appx/lv_app_terminal.o \
./lvgl/lv_appx/lv_app_wifi.o 

C_DEPS += \
./lvgl/lv_appx/lv_app_benchmark.d \
./lvgl/lv_appx/lv_app_example.d \
./lvgl/lv_appx/lv_app_files.d \
./lvgl/lv_appx/lv_app_gsm.d \
./lvgl/lv_appx/lv_app_phantom.d \
./lvgl/lv_appx/lv_app_sysmon.d \
./lvgl/lv_appx/lv_app_terminal.d \
./lvgl/lv_appx/lv_app_wifi.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/lv_appx/%.o: ../lvgl/lv_appx/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse_neon_cdt_workspace/proj_pc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


