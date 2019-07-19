################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Lib/ugui/subdir.mk
-include Lib/ILI9341/subdir.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Gif-Player-Badge.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Gif-Player-Badge.list \


# All Target
all: Gif-Player-Badge.elf secondary-outputs

# Tool invocations
Gif-Player-Badge.elf: $(OBJS) $(USER_OBJS) F:\Documents\GitHub\Gif-Player-Badge\Code\Gif-Player-Badge\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -o "Gif-Player-Badge.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"F:\Documents\GitHub\Gif-Player-Badge\Code\Gif-Player-Badge\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Gif-Player-Badge.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Gif-Player-Badge.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Gif-Player-Badge.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
