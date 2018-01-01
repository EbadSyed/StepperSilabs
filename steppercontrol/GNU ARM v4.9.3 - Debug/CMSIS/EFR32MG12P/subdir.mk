################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../CMSIS/EFR32MG12P/startup_gcc_efr32mg12p.s 

C_SRCS += \
../CMSIS/EFR32MG12P/system_efr32mg12p.c 

OBJS += \
./CMSIS/EFR32MG12P/startup_gcc_efr32mg12p.o \
./CMSIS/EFR32MG12P/system_efr32mg12p.o 

C_DEPS += \
./CMSIS/EFR32MG12P/system_efr32mg12p.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/EFR32MG12P/%.o: ../CMSIS/EFR32MG12P/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Assembler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -c -x assembler-with-cpp -I"C:\Users\Ebad\SimplicityStudio\v4_workspace\letsprint\inc" -I"C:/Users/Ebad/SimplicityStudio/v4_workspace/letsprint/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/EFR32MG12_BRD4162A/config" -I"C:/Users/Ebad/SimplicityStudio/v4_workspace/letsprint/config" '-DEFR32MG12P332F1024GL125=1' -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

CMSIS/EFR32MG12P/system_efr32mg12p.o: ../CMSIS/EFR32MG12P/system_efr32mg12p.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFR32MG12P332F1024GL125=1' -I"C:\Users\Ebad\SimplicityStudio\v4_workspace\letsprint\inc" -I"C:/Users/Ebad/SimplicityStudio/v4_workspace/letsprint/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/EFR32MG12_BRD4162A/config" -I"C:/Users/Ebad/SimplicityStudio/v4_workspace/letsprint/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"CMSIS/EFR32MG12P/system_efr32mg12p.d" -MT"CMSIS/EFR32MG12P/system_efr32mg12p.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


