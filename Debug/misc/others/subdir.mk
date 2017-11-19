################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../misc/others/fsm.c \
../misc/others/slip.c \
../misc/others/strcmd.c 

OBJS += \
./misc/others/fsm.o \
./misc/others/slip.o \
./misc/others/strcmd.o 

C_DEPS += \
./misc/others/fsm.d \
./misc/others/slip.d \
./misc/others/strcmd.d 


# Each subdirectory must supply rules for building sources it contributes
misc/others/%.o: ../misc/others/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse-workspace/lv_dev_5" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


