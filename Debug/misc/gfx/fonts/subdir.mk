################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../misc/gfx/fonts/dejavu_10.c \
../misc/gfx/fonts/dejavu_120.c \
../misc/gfx/fonts/dejavu_14.c \
../misc/gfx/fonts/dejavu_20.c \
../misc/gfx/fonts/dejavu_30.c \
../misc/gfx/fonts/dejavu_40.c \
../misc/gfx/fonts/dejavu_60.c \
../misc/gfx/fonts/dejavu_8.c \
../misc/gfx/fonts/dejavu_80.c \
../misc/gfx/fonts/symbol_30.c \
../misc/gfx/fonts/symbol_60.c 

OBJS += \
./misc/gfx/fonts/dejavu_10.o \
./misc/gfx/fonts/dejavu_120.o \
./misc/gfx/fonts/dejavu_14.o \
./misc/gfx/fonts/dejavu_20.o \
./misc/gfx/fonts/dejavu_30.o \
./misc/gfx/fonts/dejavu_40.o \
./misc/gfx/fonts/dejavu_60.o \
./misc/gfx/fonts/dejavu_8.o \
./misc/gfx/fonts/dejavu_80.o \
./misc/gfx/fonts/symbol_30.o \
./misc/gfx/fonts/symbol_60.o 

C_DEPS += \
./misc/gfx/fonts/dejavu_10.d \
./misc/gfx/fonts/dejavu_120.d \
./misc/gfx/fonts/dejavu_14.d \
./misc/gfx/fonts/dejavu_20.d \
./misc/gfx/fonts/dejavu_30.d \
./misc/gfx/fonts/dejavu_40.d \
./misc/gfx/fonts/dejavu_60.d \
./misc/gfx/fonts/dejavu_8.d \
./misc/gfx/fonts/dejavu_80.d \
./misc/gfx/fonts/symbol_30.d \
./misc/gfx/fonts/symbol_60.d 


# Each subdirectory must supply rules for building sources it contributes
misc/gfx/fonts/%.o: ../misc/gfx/fonts/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse_neon_workspace/lv_proj_pc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


