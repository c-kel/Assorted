################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/ASerialLdd1.c" \
"../Generated_Code/Accel.c" \
"../Generated_Code/Cpu.c" \
"../Generated_Code/Inhr1.c" \
"../Generated_Code/IntI2cLdd1.c" \
"../Generated_Code/MQX1.c" \
"../Generated_Code/PE_LDD.c" \
"../Generated_Code/SystemTimer1.c" \
"../Generated_Code/Term1.c" \
"../Generated_Code/Vectors.c" \

C_SRCS += \
../Generated_Code/ASerialLdd1.c \
../Generated_Code/Accel.c \
../Generated_Code/Cpu.c \
../Generated_Code/Inhr1.c \
../Generated_Code/IntI2cLdd1.c \
../Generated_Code/MQX1.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/SystemTimer1.c \
../Generated_Code/Term1.c \
../Generated_Code/Vectors.c \

OBJS += \
./Generated_Code/ASerialLdd1.o \
./Generated_Code/Accel.o \
./Generated_Code/Cpu.o \
./Generated_Code/Inhr1.o \
./Generated_Code/IntI2cLdd1.o \
./Generated_Code/MQX1.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/SystemTimer1.o \
./Generated_Code/Term1.o \
./Generated_Code/Vectors.o \

C_DEPS += \
./Generated_Code/ASerialLdd1.d \
./Generated_Code/Accel.d \
./Generated_Code/Cpu.d \
./Generated_Code/Inhr1.d \
./Generated_Code/IntI2cLdd1.d \
./Generated_Code/MQX1.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/SystemTimer1.d \
./Generated_Code/Term1.d \
./Generated_Code/Vectors.d \

OBJS_QUOTED += \
"./Generated_Code/ASerialLdd1.o" \
"./Generated_Code/Accel.o" \
"./Generated_Code/Cpu.o" \
"./Generated_Code/Inhr1.o" \
"./Generated_Code/IntI2cLdd1.o" \
"./Generated_Code/MQX1.o" \
"./Generated_Code/PE_LDD.o" \
"./Generated_Code/SystemTimer1.o" \
"./Generated_Code/Term1.o" \
"./Generated_Code/Vectors.o" \

C_DEPS_QUOTED += \
"./Generated_Code/ASerialLdd1.d" \
"./Generated_Code/Accel.d" \
"./Generated_Code/Cpu.d" \
"./Generated_Code/Inhr1.d" \
"./Generated_Code/IntI2cLdd1.d" \
"./Generated_Code/MQX1.d" \
"./Generated_Code/PE_LDD.d" \
"./Generated_Code/SystemTimer1.d" \
"./Generated_Code/Term1.d" \
"./Generated_Code/Vectors.d" \

OBJS_OS_FORMAT += \
./Generated_Code/ASerialLdd1.o \
./Generated_Code/Accel.o \
./Generated_Code/Cpu.o \
./Generated_Code/Inhr1.o \
./Generated_Code/IntI2cLdd1.o \
./Generated_Code/MQX1.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/SystemTimer1.o \
./Generated_Code/Term1.o \
./Generated_Code/Vectors.o \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/ASerialLdd1.o: ../Generated_Code/ASerialLdd1.c
	@echo 'Building file: $<'
	@echo 'Executing target #44 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/ASerialLdd1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/ASerialLdd1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Accel.o: ../Generated_Code/Accel.c
	@echo 'Building file: $<'
	@echo 'Executing target #45 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Accel.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Accel.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Cpu.o: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #46 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Cpu.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Cpu.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Inhr1.o: ../Generated_Code/Inhr1.c
	@echo 'Building file: $<'
	@echo 'Executing target #47 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Inhr1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Inhr1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/IntI2cLdd1.o: ../Generated_Code/IntI2cLdd1.c
	@echo 'Building file: $<'
	@echo 'Executing target #48 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/IntI2cLdd1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/IntI2cLdd1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/MQX1.o: ../Generated_Code/MQX1.c
	@echo 'Building file: $<'
	@echo 'Executing target #49 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/MQX1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/MQX1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PE_LDD.o: ../Generated_Code/PE_LDD.c
	@echo 'Building file: $<'
	@echo 'Executing target #50 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PE_LDD.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PE_LDD.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/SystemTimer1.o: ../Generated_Code/SystemTimer1.c
	@echo 'Building file: $<'
	@echo 'Executing target #51 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/SystemTimer1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/SystemTimer1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Term1.o: ../Generated_Code/Term1.c
	@echo 'Building file: $<'
	@echo 'Executing target #52 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Term1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Term1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors.o: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #53 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Vectors.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Vectors.o"
	@echo 'Finished building: $<'
	@echo ' '


