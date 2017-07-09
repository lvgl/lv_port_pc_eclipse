################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../misc/gfx/anim.c \
../misc/gfx/area.c \
../misc/gfx/circ.c \
../misc/gfx/font.c \
../misc/gfx/text.c 

OBJS += \
./misc/gfx/anim.o \
./misc/gfx/area.o \
./misc/gfx/circ.o \
./misc/gfx/font.o \
./misc/gfx/text.o 

C_DEPS += \
./misc/gfx/anim.d \
./misc/gfx/area.d \
./misc/gfx/circ.d \
./misc/gfx/font.d \
./misc/gfx/text.d 


# Each subdirectory must supply rules for building sources it contributes
misc/gfx/%.o: ../misc/gfx/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse_neon_cdt_workspace/proj_pc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


