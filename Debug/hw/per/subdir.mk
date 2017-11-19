################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hw/per/i2c.c \
../hw/per/io.c \
../hw/per/par.c \
../hw/per/serial.c \
../hw/per/spi.c \
../hw/per/tft.c \
../hw/per/tick.c \
../hw/per/tmr.c 

OBJS += \
./hw/per/i2c.o \
./hw/per/io.o \
./hw/per/par.o \
./hw/per/serial.o \
./hw/per/spi.o \
./hw/per/tft.o \
./hw/per/tick.o \
./hw/per/tmr.o 

C_DEPS += \
./hw/per/i2c.d \
./hw/per/io.d \
./hw/per/par.d \
./hw/per/serial.d \
./hw/per/spi.d \
./hw/per/tft.d \
./hw/per/tick.d \
./hw/per/tmr.d 


# Each subdirectory must supply rules for building sources it contributes
hw/per/%.o: ../hw/per/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse-workspace/lv_dev_5" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


