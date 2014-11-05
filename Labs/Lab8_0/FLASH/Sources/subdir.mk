################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Events.c" \
"../Sources/main.c" \
"../Sources/mqx_tasks.c" \

C_SRCS += \
../Sources/Events.c \
../Sources/main.c \
../Sources/mqx_tasks.c \

OBJS += \
./Sources/Events.o \
./Sources/main.o \
./Sources/mqx_tasks.o \

C_DEPS += \
./Sources/Events.d \
./Sources/main.d \
./Sources/mqx_tasks.d \

OBJS_QUOTED += \
"./Sources/Events.o" \
"./Sources/main.o" \
"./Sources/mqx_tasks.o" \

C_DEPS_QUOTED += \
"./Sources/Events.d" \
"./Sources/main.d" \
"./Sources/mqx_tasks.d" \

OBJS_OS_FORMAT += \
./Sources/Events.o \
./Sources/main.o \
./Sources/mqx_tasks.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/Events.o: ../Sources/Events.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Events.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Events.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mqx_tasks.o: ../Sources/mqx_tasks.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mqx_tasks.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mqx_tasks.o"
	@echo 'Finished building: $<'
	@echo ' '


