################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/lv_obj/lv_dispi.c \
../lvgl/lv_obj/lv_group.c \
../lvgl/lv_obj/lv_obj.c \
../lvgl/lv_obj/lv_refr.c \
../lvgl/lv_obj/lv_style.c \
../lvgl/lv_obj/lv_vdb.c 

OBJS += \
./lvgl/lv_obj/lv_dispi.o \
./lvgl/lv_obj/lv_group.o \
./lvgl/lv_obj/lv_obj.o \
./lvgl/lv_obj/lv_refr.o \
./lvgl/lv_obj/lv_style.o \
./lvgl/lv_obj/lv_vdb.o 

C_DEPS += \
./lvgl/lv_obj/lv_dispi.d \
./lvgl/lv_obj/lv_group.d \
./lvgl/lv_obj/lv_obj.d \
./lvgl/lv_obj/lv_refr.d \
./lvgl/lv_obj/lv_style.d \
./lvgl/lv_obj/lv_vdb.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/lv_obj/%.o: ../lvgl/lv_obj/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse_neon_workspace/lv_proj_pc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


