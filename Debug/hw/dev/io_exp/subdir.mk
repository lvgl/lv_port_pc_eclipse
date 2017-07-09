################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hw/dev/io_exp/mcp23008.c \
../hw/dev/io_exp/pcf8574.c 

OBJS += \
./hw/dev/io_exp/mcp23008.o \
./hw/dev/io_exp/pcf8574.o 

C_DEPS += \
./hw/dev/io_exp/mcp23008.d \
./hw/dev/io_exp/pcf8574.d 


# Each subdirectory must supply rules for building sources it contributes
hw/dev/io_exp/%.o: ../hw/dev/io_exp/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse_neon_cdt_workspace/proj_pc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


