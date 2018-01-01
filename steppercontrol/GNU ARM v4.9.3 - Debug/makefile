################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include emlib/subdir.mk
-include CMSIS/EFR32MG12P/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: letsprint.axf

# Tool invocations
letsprint.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -T "letsprint.ld" -Xlinker --gc-sections -Xlinker -Map="letsprint.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o letsprint.axf "./CMSIS/EFR32MG12P/startup_gcc_efr32mg12p.o" "./CMSIS/EFR32MG12P/system_efr32mg12p.o" "./emlib/em_assert.o" "./emlib/em_cmu.o" "./emlib/em_core.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_system.o" "./emlib/em_usart.o" "./src/InitDevice.o" "./src/bsp_bcc.o" "./src/bsp_stk.o" "./src/em_timer.o" "./src/main.o" "./src/retargetio.o" "./src/retargetserial.o" "./src/ustimer.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: letsprint.hex'
	arm-none-eabi-objcopy -O ihex "letsprint.axf" "letsprint.hex"
	@echo ' '

	@echo 'Building bin file: letsprint.bin'
	arm-none-eabi-objcopy -O binary "letsprint.axf" "letsprint.bin"
	@echo ' '

	@echo 'Building s37 file: letsprint.s37'
	arm-none-eabi-objcopy -O srec "letsprint.axf" "letsprint.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "letsprint.axf"
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) letsprint.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
