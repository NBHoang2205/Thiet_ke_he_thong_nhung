################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/HAL_lib/Src/stm32f1xx_hal.c \
../Drivers/HAL_lib/Src/stm32f1xx_hal_cortex.c \
../Drivers/HAL_lib/Src/stm32f1xx_hal_gpio.c \
../Drivers/HAL_lib/Src/stm32f1xx_hal_gpio_ex.c \
../Drivers/HAL_lib/Src/stm32f1xx_hal_rcc.c \
../Drivers/HAL_lib/Src/stm32f1xx_hal_rcc_ex.c 

OBJS += \
./Drivers/HAL_lib/Src/stm32f1xx_hal.o \
./Drivers/HAL_lib/Src/stm32f1xx_hal_cortex.o \
./Drivers/HAL_lib/Src/stm32f1xx_hal_gpio.o \
./Drivers/HAL_lib/Src/stm32f1xx_hal_gpio_ex.o \
./Drivers/HAL_lib/Src/stm32f1xx_hal_rcc.o \
./Drivers/HAL_lib/Src/stm32f1xx_hal_rcc_ex.o 

C_DEPS += \
./Drivers/HAL_lib/Src/stm32f1xx_hal.d \
./Drivers/HAL_lib/Src/stm32f1xx_hal_cortex.d \
./Drivers/HAL_lib/Src/stm32f1xx_hal_gpio.d \
./Drivers/HAL_lib/Src/stm32f1xx_hal_gpio_ex.d \
./Drivers/HAL_lib/Src/stm32f1xx_hal_rcc.d \
./Drivers/HAL_lib/Src/stm32f1xx_hal_rcc_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/HAL_lib/Src/%.o: ../Drivers/HAL_lib/Src/%.c Drivers/HAL_lib/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/acer/OneDrive - Hanoi University of Science and Technology/NAM_4/KY_1/Design_embedded_system/workspace/creat_prj_no_cube/Drivers/CMSIS" -I"C:/Users/acer/OneDrive - Hanoi University of Science and Technology/NAM_4/KY_1/Design_embedded_system/workspace/creat_prj_no_cube/Drivers/Device" -I"C:/Users/acer/OneDrive - Hanoi University of Science and Technology/NAM_4/KY_1/Design_embedded_system/workspace/creat_prj_no_cube/Drivers/HAL_lib/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

