################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../ExternalInterrupt.c \
../LCD.c \
../Program.c \
../TIMER.c 

OBJS += \
./ADC.o \
./ExternalInterrupt.o \
./LCD.o \
./Program.o \
./TIMER.o 

C_DEPS += \
./ADC.d \
./ExternalInterrupt.d \
./LCD.d \
./Program.d \
./TIMER.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


