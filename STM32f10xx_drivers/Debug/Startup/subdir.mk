################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f103c6tx.s 

OBJS += \
./Startup/startup_stm32f103c6tx.o 

S_DEPS += \
./Startup/startup_stm32f103c6tx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/startup_stm32f103c6tx.o: ../Startup/startup_stm32f103c6tx.s
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -c -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/My_RTOS/inc" -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/stm32f103_drivers/inc" -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/CMSIS_V5" -x assembler-with-cpp -MMD -MP -MF"Startup/startup_stm32f103c6tx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

