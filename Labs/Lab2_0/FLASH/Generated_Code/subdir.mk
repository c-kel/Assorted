################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/AD1.c" \
"../Generated_Code/AdcLdd1.c" \
"../Generated_Code/Cpu.c" \
"../Generated_Code/PE_LDD.c" \
"../Generated_Code/PWMBlue.c" \
"../Generated_Code/PWMGreen.c" \
"../Generated_Code/PWMRed.c" \
"../Generated_Code/PwmLdd1.c" \
"../Generated_Code/PwmLdd2.c" \
"../Generated_Code/PwmLdd3.c" \
"../Generated_Code/TU1.c" \
"../Generated_Code/Vectors.c" \

C_SRCS += \
../Generated_Code/AD1.c \
../Generated_Code/AdcLdd1.c \
../Generated_Code/Cpu.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/PWMBlue.c \
../Generated_Code/PWMGreen.c \
../Generated_Code/PWMRed.c \
../Generated_Code/PwmLdd1.c \
../Generated_Code/PwmLdd2.c \
../Generated_Code/PwmLdd3.c \
../Generated_Code/TU1.c \
../Generated_Code/Vectors.c \

OBJS += \
./Generated_Code/AD1.o \
./Generated_Code/AdcLdd1.o \
./Generated_Code/Cpu.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/PWMBlue.o \
./Generated_Code/PWMGreen.o \
./Generated_Code/PWMRed.o \
./Generated_Code/PwmLdd1.o \
./Generated_Code/PwmLdd2.o \
./Generated_Code/PwmLdd3.o \
./Generated_Code/TU1.o \
./Generated_Code/Vectors.o \

C_DEPS += \
./Generated_Code/AD1.d \
./Generated_Code/AdcLdd1.d \
./Generated_Code/Cpu.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/PWMBlue.d \
./Generated_Code/PWMGreen.d \
./Generated_Code/PWMRed.d \
./Generated_Code/PwmLdd1.d \
./Generated_Code/PwmLdd2.d \
./Generated_Code/PwmLdd3.d \
./Generated_Code/TU1.d \
./Generated_Code/Vectors.d \

OBJS_QUOTED += \
"./Generated_Code/AD1.o" \
"./Generated_Code/AdcLdd1.o" \
"./Generated_Code/Cpu.o" \
"./Generated_Code/PE_LDD.o" \
"./Generated_Code/PWMBlue.o" \
"./Generated_Code/PWMGreen.o" \
"./Generated_Code/PWMRed.o" \
"./Generated_Code/PwmLdd1.o" \
"./Generated_Code/PwmLdd2.o" \
"./Generated_Code/PwmLdd3.o" \
"./Generated_Code/TU1.o" \
"./Generated_Code/Vectors.o" \

C_DEPS_QUOTED += \
"./Generated_Code/AD1.d" \
"./Generated_Code/AdcLdd1.d" \
"./Generated_Code/Cpu.d" \
"./Generated_Code/PE_LDD.d" \
"./Generated_Code/PWMBlue.d" \
"./Generated_Code/PWMGreen.d" \
"./Generated_Code/PWMRed.d" \
"./Generated_Code/PwmLdd1.d" \
"./Generated_Code/PwmLdd2.d" \
"./Generated_Code/PwmLdd3.d" \
"./Generated_Code/TU1.d" \
"./Generated_Code/Vectors.d" \

OBJS_OS_FORMAT += \
./Generated_Code/AD1.o \
./Generated_Code/AdcLdd1.o \
./Generated_Code/Cpu.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/PWMBlue.o \
./Generated_Code/PWMGreen.o \
./Generated_Code/PWMRed.o \
./Generated_Code/PwmLdd1.o \
./Generated_Code/PwmLdd2.o \
./Generated_Code/PwmLdd3.o \
./Generated_Code/TU1.o \
./Generated_Code/Vectors.o \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/AD1.o: ../Generated_Code/AD1.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/AD1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/AD1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/AdcLdd1.o: ../Generated_Code/AdcLdd1.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/AdcLdd1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/AdcLdd1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Cpu.o: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Cpu.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Cpu.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PE_LDD.o: ../Generated_Code/PE_LDD.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PE_LDD.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PE_LDD.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PWMBlue.o: ../Generated_Code/PWMBlue.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PWMBlue.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PWMBlue.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PWMGreen.o: ../Generated_Code/PWMGreen.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PWMGreen.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PWMGreen.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PWMRed.o: ../Generated_Code/PWMRed.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PWMRed.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PWMRed.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PwmLdd1.o: ../Generated_Code/PwmLdd1.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PwmLdd1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PwmLdd1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PwmLdd2.o: ../Generated_Code/PwmLdd2.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PwmLdd2.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PwmLdd2.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PwmLdd3.o: ../Generated_Code/PwmLdd3.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PwmLdd3.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PwmLdd3.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/TU1.o: ../Generated_Code/TU1.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/TU1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/TU1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors.o: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Vectors.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Vectors.o"
	@echo 'Finished building: $<'
	@echo ' '


