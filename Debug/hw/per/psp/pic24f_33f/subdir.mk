################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hw/per/psp/pic24f_33f/psp_i2c.c \
../hw/per/psp/pic24f_33f/psp_io.c \
../hw/per/psp/pic24f_33f/psp_serial.c \
../hw/per/psp/pic24f_33f/psp_spi.c \
../hw/per/psp/pic24f_33f/psp_tft.c \
../hw/per/psp/pic24f_33f/psp_tmr.c 

OBJS += \
./hw/per/psp/pic24f_33f/psp_i2c.o \
./hw/per/psp/pic24f_33f/psp_io.o \
./hw/per/psp/pic24f_33f/psp_serial.o \
./hw/per/psp/pic24f_33f/psp_spi.o \
./hw/per/psp/pic24f_33f/psp_tft.o \
./hw/per/psp/pic24f_33f/psp_tmr.o 

C_DEPS += \
./hw/per/psp/pic24f_33f/psp_i2c.d \
./hw/per/psp/pic24f_33f/psp_io.d \
./hw/per/psp/pic24f_33f/psp_serial.d \
./hw/per/psp/pic24f_33f/psp_spi.d \
./hw/per/psp/pic24f_33f/psp_tft.d \
./hw/per/psp/pic24f_33f/psp_tmr.d 


# Each subdirectory must supply rules for building sources it contributes
hw/per/psp/pic24f_33f/%.o: ../hw/per/psp/pic24f_33f/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse_neon_workspace/lv_pc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


