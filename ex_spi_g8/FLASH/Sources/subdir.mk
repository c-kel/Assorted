################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Events.c" \
"../Sources/RNet_App.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/Events.c \
../Sources/RNet_App.c \
../Sources/main.c \

OBJS += \
./Sources/Events.o \
./Sources/RNet_App.o \
./Sources/main.o \

C_DEPS += \
./Sources/Events.d \
./Sources/RNet_App.d \
./Sources/main.d \

OBJS_QUOTED += \
"./Sources/Events.o" \
"./Sources/RNet_App.o" \
"./Sources/main.o" \

C_DEPS_QUOTED += \
"./Sources/Events.d" \
"./Sources/RNet_App.d" \
"./Sources/main.d" \

OBJS_OS_FORMAT += \
./Sources/Events.o \
./Sources/RNet_App.o \
./Sources/main.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/Events.o: ../Sources/Events.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Events.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Events.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/RNet_App.o: ../Sources/RNet_App.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/RNet_App.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/RNet_App.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '


