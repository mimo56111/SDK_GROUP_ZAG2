################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../ADC_MCAL.c \
../GPIO.c \
../Internal_EEPROM_MCAL.c \
../Keypad_ECU.c \
../LCD_ECU.c \
../LED_ECU_deiver.c \
../SDK_Zag_Group2.c \
../Seven_segment_ECU.c \
../Switch_ECU_driver.c \
../Timer_MCAL.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
ADC_MCAL.o \
GPIO.o \
Internal_EEPROM_MCAL.o \
Keypad_ECU.o \
LCD_ECU.o \
LED_ECU_deiver.o \
SDK_Zag_Group2.o \
Seven_segment_ECU.o \
Switch_ECU_driver.o \
Timer_MCAL.o


OBJS_AS_ARGS +=  \
ADC_MCAL.o \
GPIO.o \
Internal_EEPROM_MCAL.o \
Keypad_ECU.o \
LCD_ECU.o \
LED_ECU_deiver.o \
SDK_Zag_Group2.o \
Seven_segment_ECU.o \
Switch_ECU_driver.o \
Timer_MCAL.o


C_DEPS +=  \
ADC_MCAL.d \
GPIO.d \
Internal_EEPROM_MCAL.d \
Keypad_ECU.d \
LCD_ECU.d \
LED_ECU_deiver.d \
SDK_Zag_Group2.d \
Seven_segment_ECU.d \
Switch_ECU_driver.d \
Timer_MCAL.d


C_DEPS_AS_ARGS +=  \
ADC_MCAL.d \
GPIO.d \
Internal_EEPROM_MCAL.d \
Keypad_ECU.d \
LCD_ECU.d \
LED_ECU_deiver.d \
SDK_Zag_Group2.d \
Seven_segment_ECU.d \
Switch_ECU_driver.d \
Timer_MCAL.d


OUTPUT_FILE_PATH +=SDK_Zag_Group2.elf

OUTPUT_FILE_PATH_AS_ARGS +=SDK_Zag_Group2.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

# AVR32/GNU C Compiler





















./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : (AVR_8_bit_GNU_Toolchain_3.4.1_830) 4.6.2
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-gcc.exe$(QUOTE) -funsigned-char -funsigned-bitfields -O1 -fpack-struct -fshort-enums -g2 -Wall -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -mmcu=atmega32   -o"$@" "$<" 
	@echo Finished building: $<



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : (AVR_8_bit_GNU_Toolchain_3.4.1_830) 4.6.2
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="SDK_Zag_Group2.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group  -mmcu=atmega32  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "SDK_Zag_Group2.elf" "SDK_Zag_Group2.hex"
	"C:\Program Files (x86)\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "SDK_Zag_Group2.elf" "SDK_Zag_Group2.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-objdump.exe" -h -S "SDK_Zag_Group2.elf" > "SDK_Zag_Group2.lss"
	"C:\Program Files (x86)\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature  "SDK_Zag_Group2.elf" "SDK_Zag_Group2.srec"
	"C:\Program Files (x86)\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-size.exe" "SDK_Zag_Group2.elf"
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS)$(C_DEPS_AS_ARGS) $(EXECUTABLES) 
	rm -rf "SDK_Zag_Group2.elf" "SDK_Zag_Group2.a" "SDK_Zag_Group2.hex" "SDK_Zag_Group2.lss" "SDK_Zag_Group2.eep" "SDK_Zag_Group2.map" "SDK_Zag_Group2.srec"
	