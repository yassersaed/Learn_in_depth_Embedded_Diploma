################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../My_RTOS/CortexMX_OS_porting.c \
../My_RTOS/MYRTOS_FIFO.c \
../My_RTOS/Scheduler.c 

OBJS += \
./My_RTOS/CortexMX_OS_porting.o \
./My_RTOS/MYRTOS_FIFO.o \
./My_RTOS/Scheduler.o 

C_DEPS += \
./My_RTOS/CortexMX_OS_porting.d \
./My_RTOS/MYRTOS_FIFO.d \
./My_RTOS/Scheduler.d 


# Each subdirectory must supply rules for building sources it contributes
My_RTOS/CortexMX_OS_porting.o: ../My_RTOS/CortexMX_OS_porting.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/CMSIS_V5" -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/My_RTOS/inc" -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/stm32f103_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"My_RTOS/CortexMX_OS_porting.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
My_RTOS/MYRTOS_FIFO.o: ../My_RTOS/MYRTOS_FIFO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/CMSIS_V5" -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/My_RTOS/inc" -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/stm32f103_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"My_RTOS/MYRTOS_FIFO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
My_RTOS/Scheduler.o: ../My_RTOS/Scheduler.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/CMSIS_V5" -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/My_RTOS/inc" -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/stm32f103_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"My_RTOS/Scheduler.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

