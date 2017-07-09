################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../misc/templ/templ.c 

OBJS += \
./misc/templ/templ.o 

C_DEPS += \
./misc/templ/templ.d 


# Each subdirectory must supply rules for building sources it contributes
misc/templ/%.o: ../misc/templ/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse_neon_cdt_workspace/proj_pc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


