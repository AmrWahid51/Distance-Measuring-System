################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ultra_sonic.c \
../gpio.c \
../icu.c \
../lcd.c \
../main_Project4.c 

OBJS += \
./Ultra_sonic.o \
./gpio.o \
./icu.o \
./lcd.o \
./main_Project4.o 

C_DEPS += \
./Ultra_sonic.d \
./gpio.d \
./icu.d \
./lcd.d \
./main_Project4.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


