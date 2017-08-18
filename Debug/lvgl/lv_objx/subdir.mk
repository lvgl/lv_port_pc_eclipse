################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/lv_objx/lv_bar.c \
../lvgl/lv_objx/lv_btn.c \
../lvgl/lv_objx/lv_btnm.c \
../lvgl/lv_objx/lv_cb.c \
../lvgl/lv_objx/lv_chart.c \
../lvgl/lv_objx/lv_cont.c \
../lvgl/lv_objx/lv_ddlist.c \
../lvgl/lv_objx/lv_gauge.c \
../lvgl/lv_objx/lv_img.c \
../lvgl/lv_objx/lv_label.c \
../lvgl/lv_objx/lv_led.c \
../lvgl/lv_objx/lv_line.c \
../lvgl/lv_objx/lv_list.c \
../lvgl/lv_objx/lv_lmeter.c \
../lvgl/lv_objx/lv_mbox.c \
../lvgl/lv_objx/lv_objx_templ.c \
../lvgl/lv_objx/lv_page.c \
../lvgl/lv_objx/lv_slider.c \
../lvgl/lv_objx/lv_ta.c \
../lvgl/lv_objx/lv_win.c 

OBJS += \
./lvgl/lv_objx/lv_bar.o \
./lvgl/lv_objx/lv_btn.o \
./lvgl/lv_objx/lv_btnm.o \
./lvgl/lv_objx/lv_cb.o \
./lvgl/lv_objx/lv_chart.o \
./lvgl/lv_objx/lv_cont.o \
./lvgl/lv_objx/lv_ddlist.o \
./lvgl/lv_objx/lv_gauge.o \
./lvgl/lv_objx/lv_img.o \
./lvgl/lv_objx/lv_label.o \
./lvgl/lv_objx/lv_led.o \
./lvgl/lv_objx/lv_line.o \
./lvgl/lv_objx/lv_list.o \
./lvgl/lv_objx/lv_lmeter.o \
./lvgl/lv_objx/lv_mbox.o \
./lvgl/lv_objx/lv_objx_templ.o \
./lvgl/lv_objx/lv_page.o \
./lvgl/lv_objx/lv_slider.o \
./lvgl/lv_objx/lv_ta.o \
./lvgl/lv_objx/lv_win.o 

C_DEPS += \
./lvgl/lv_objx/lv_bar.d \
./lvgl/lv_objx/lv_btn.d \
./lvgl/lv_objx/lv_btnm.d \
./lvgl/lv_objx/lv_cb.d \
./lvgl/lv_objx/lv_chart.d \
./lvgl/lv_objx/lv_cont.d \
./lvgl/lv_objx/lv_ddlist.d \
./lvgl/lv_objx/lv_gauge.d \
./lvgl/lv_objx/lv_img.d \
./lvgl/lv_objx/lv_label.d \
./lvgl/lv_objx/lv_led.d \
./lvgl/lv_objx/lv_line.d \
./lvgl/lv_objx/lv_list.d \
./lvgl/lv_objx/lv_lmeter.d \
./lvgl/lv_objx/lv_mbox.d \
./lvgl/lv_objx/lv_objx_templ.d \
./lvgl/lv_objx/lv_page.d \
./lvgl/lv_objx/lv_slider.d \
./lvgl/lv_objx/lv_ta.d \
./lvgl/lv_objx/lv_win.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/lv_objx/%.o: ../lvgl/lv_objx/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse_neon_workspace/lv_proj_pc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


