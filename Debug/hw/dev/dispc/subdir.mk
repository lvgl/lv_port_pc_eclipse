################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hw/dev/dispc/R61581.c \
../hw/dev/dispc/SSD1963.c \
../hw/dev/dispc/ST7565.c \
../hw/dev/dispc/rdisp.c 

OBJS += \
./hw/dev/dispc/R61581.o \
./hw/dev/dispc/SSD1963.o \
./hw/dev/dispc/ST7565.o \
./hw/dev/dispc/rdisp.o 

C_DEPS += \
./hw/dev/dispc/R61581.d \
./hw/dev/dispc/SSD1963.d \
./hw/dev/dispc/ST7565.d \
./hw/dev/dispc/rdisp.d 


# Each subdirectory must supply rules for building sources it contributes
hw/dev/dispc/%.o: ../hw/dev/dispc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse-workspace/lv_dev_5" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


