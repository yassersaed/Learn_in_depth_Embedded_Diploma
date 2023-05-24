################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f103_drivers/stm32F103_RCC_driver.c \
../stm32f103_drivers/stm32f103_EXTI_driver.c \
../stm32f103_drivers/stm32f103_GPIO_driver.c \
../stm32f103_drivers/stm32f103_I2C_driver.c \
../stm32f103_drivers/stm32f103_SPI_driver.c \
../stm32f103_drivers/stm32f103_UART_driver.c 

OBJS += \
./stm32f103_drivers/stm32F103_RCC_driver.o \
./stm32f103_drivers/stm32f103_EXTI_driver.o \
./stm32f103_drivers/stm32f103_GPIO_driver.o \
./stm32f103_drivers/stm32f103_I2C_driver.o \
./stm32f103_drivers/stm32f103_SPI_driver.o \
./stm32f103_drivers/stm32f103_UART_driver.o 

C_DEPS += \
./stm32f103_drivers/stm32F103_RCC_driver.d \
./stm32f103_drivers/stm32f103_EXTI_driver.d \
./stm32f103_drivers/stm32f103_GPIO_driver.d \
./stm32f103_drivers/stm32f103_I2C_driver.d \
./stm32f103_drivers/stm32f103_SPI_driver.d \
./stm32f103_drivers/stm32f103_UART_driver.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f103_drivers/stm32F103_RCC_driver.o: ../stm32f103_drivers/stm32F103_RCC_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/CMSIS_V5" -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/My_RTOS/inc" -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/stm32f103_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103_drivers/stm32F103_RCC_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103_drivers/stm32f103_EXTI_driver.o: ../stm32f103_drivers/stm32f103_EXTI_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/CMSIS_V5" -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/My_RTOS/inc" -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/stm32f103_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103_drivers/stm32f103_EXTI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103_drivers/stm32f103_GPIO_driver.o: ../stm32f103_drivers/stm32f103_GPIO_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/CMSIS_V5" -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/My_RTOS/inc" -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/stm32f103_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103_drivers/stm32f103_GPIO_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103_drivers/stm32f103_I2C_driver.o: ../stm32f103_drivers/stm32f103_I2C_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/CMSIS_V5" -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/My_RTOS/inc" -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/stm32f103_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103_drivers/stm32f103_I2C_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103_drivers/stm32f103_SPI_driver.o: ../stm32f103_drivers/stm32f103_SPI_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/CMSIS_V5" -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/My_RTOS/inc" -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/stm32f103_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103_drivers/stm32f103_SPI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103_drivers/stm32f103_UART_driver.o: ../stm32f103_drivers/stm32f103_UART_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/CMSIS_V5" -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/My_RTOS/inc" -I"E:/Learn in depth/Lectures/STMCUBE/my_drivers/stm32f103_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103_drivers/stm32f103_UART_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

