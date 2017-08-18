################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hw/per/psp/pic32mx/psp_io.c \
../hw/per/psp/pic32mx/psp_par.c \
../hw/per/psp/pic32mx/psp_serial.c \
../hw/per/psp/pic32mx/psp_spi.c \
../hw/per/psp/pic32mx/psp_tmr.c 

OBJS += \
./hw/per/psp/pic32mx/psp_io.o \
./hw/per/psp/pic32mx/psp_par.o \
./hw/per/psp/pic32mx/psp_serial.o \
./hw/per/psp/pic32mx/psp_spi.o \
./hw/per/psp/pic32mx/psp_tmr.o 

C_DEPS += \
./hw/per/psp/pic32mx/psp_io.d \
./hw/per/psp/pic32mx/psp_par.d \
./hw/per/psp/pic32mx/psp_serial.d \
./hw/per/psp/pic32mx/psp_spi.d \
./hw/per/psp/pic32mx/psp_tmr.d 


# Each subdirectory must supply rules for building sources it contributes
hw/per/psp/pic32mx/%.o: ../hw/per/psp/pic32mx/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse_neon_workspace/lv_proj_pc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


