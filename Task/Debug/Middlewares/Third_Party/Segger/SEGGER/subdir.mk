################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/Segger/SEGGER/SEGGER_RTT.c \
../Middlewares/Third_Party/Segger/SEGGER/SEGGER_SYSVIEW.c 

OBJS += \
./Middlewares/Third_Party/Segger/SEGGER/SEGGER_RTT.o \
./Middlewares/Third_Party/Segger/SEGGER/SEGGER_SYSVIEW.o 

C_DEPS += \
./Middlewares/Third_Party/Segger/SEGGER/SEGGER_RTT.d \
./Middlewares/Third_Party/Segger/SEGGER/SEGGER_SYSVIEW.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/Segger/SEGGER/%.o Middlewares/Third_Party/Segger/SEGGER/%.su Middlewares/Third_Party/Segger/SEGGER/%.cyclo: ../Middlewares/Third_Party/Segger/SEGGER/%.c Middlewares/Third_Party/Segger/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"D:/FreeRTOS/Task/Middlewares/Third_Party/Segger/Config" -I"D:/FreeRTOS/Task/Middlewares/Third_Party/Segger/Sample" -I"D:/FreeRTOS/Task/Middlewares/Third_Party/Segger/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-Segger-2f-SEGGER

clean-Middlewares-2f-Third_Party-2f-Segger-2f-SEGGER:
	-$(RM) ./Middlewares/Third_Party/Segger/SEGGER/SEGGER_RTT.cyclo ./Middlewares/Third_Party/Segger/SEGGER/SEGGER_RTT.d ./Middlewares/Third_Party/Segger/SEGGER/SEGGER_RTT.o ./Middlewares/Third_Party/Segger/SEGGER/SEGGER_RTT.su ./Middlewares/Third_Party/Segger/SEGGER/SEGGER_SYSVIEW.cyclo ./Middlewares/Third_Party/Segger/SEGGER/SEGGER_SYSVIEW.d ./Middlewares/Third_Party/Segger/SEGGER/SEGGER_SYSVIEW.o ./Middlewares/Third_Party/Segger/SEGGER/SEGGER_SYSVIEW.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-Segger-2f-SEGGER

