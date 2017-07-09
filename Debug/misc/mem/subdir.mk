################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../misc/mem/dyn_mem.c \
../misc/mem/dyn_mem_defr.c \
../misc/mem/fifo.c \
../misc/mem/linked_list.c 

OBJS += \
./misc/mem/dyn_mem.o \
./misc/mem/dyn_mem_defr.o \
./misc/mem/fifo.o \
./misc/mem/linked_list.o 

C_DEPS += \
./misc/mem/dyn_mem.d \
./misc/mem/dyn_mem_defr.d \
./misc/mem/fifo.d \
./misc/mem/linked_list.d 


# Each subdirectory must supply rules for building sources it contributes
misc/mem/%.o: ../misc/mem/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/kisvegabor/eclipse_neon_cdt_workspace/proj_pc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


