################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/Flash/w25qxx.c 

OBJS += \
./Lib/Flash/w25qxx.o 

C_DEPS += \
./Lib/Flash/w25qxx.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/Flash/w25qxx.o: ../Lib/Flash/w25qxx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Lib/Flash/w25qxx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

