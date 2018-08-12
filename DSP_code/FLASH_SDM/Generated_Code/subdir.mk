################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/Cpu.c" \
"../Generated_Code/MEM1.c" \
"../Generated_Code/SS1.c" \
"../Generated_Code/Vectors.c" \
"../Generated_Code/mem.c" \
"../Generated_Code/memtarget.c" \

ASM_SRCS += \
../Generated_Code/archGetLimitBit.asm \
../Generated_Code/archgetsetsaturationmode.asm \
../Generated_Code/memcopyptop.asm \
../Generated_Code/memcopyptox.asm \
../Generated_Code/memcopyxtop.asm \
../Generated_Code/memcpy.asm \
../Generated_Code/memreadp16.asm \
../Generated_Code/memreadp32.asm \
../Generated_Code/memset.asm \
../Generated_Code/memsetp.asm \
../Generated_Code/memwritep16.asm \
../Generated_Code/memwritep32.asm \

C_SRCS += \
../Generated_Code/Cpu.c \
../Generated_Code/MEM1.c \
../Generated_Code/SS1.c \
../Generated_Code/Vectors.c \
../Generated_Code/mem.c \
../Generated_Code/memtarget.c \

ASM_SRCS_QUOTED += \
"../Generated_Code/archGetLimitBit.asm" \
"../Generated_Code/archgetsetsaturationmode.asm" \
"../Generated_Code/memcopyptop.asm" \
"../Generated_Code/memcopyptox.asm" \
"../Generated_Code/memcopyxtop.asm" \
"../Generated_Code/memcpy.asm" \
"../Generated_Code/memreadp16.asm" \
"../Generated_Code/memreadp32.asm" \
"../Generated_Code/memset.asm" \
"../Generated_Code/memsetp.asm" \
"../Generated_Code/memwritep16.asm" \
"../Generated_Code/memwritep32.asm" \

OBJS += \
./Generated_Code/Cpu_c.obj \
./Generated_Code/MEM1_c.obj \
./Generated_Code/SS1_c.obj \
./Generated_Code/Vectors_c.obj \
./Generated_Code/archGetLimitBit_asm.obj \
./Generated_Code/archgetsetsaturationmode_asm.obj \
./Generated_Code/mem_c.obj \
./Generated_Code/memcopyptop_asm.obj \
./Generated_Code/memcopyptox_asm.obj \
./Generated_Code/memcopyxtop_asm.obj \
./Generated_Code/memcpy_asm.obj \
./Generated_Code/memreadp16_asm.obj \
./Generated_Code/memreadp32_asm.obj \
./Generated_Code/memset_asm.obj \
./Generated_Code/memsetp_asm.obj \
./Generated_Code/memtarget_c.obj \
./Generated_Code/memwritep16_asm.obj \
./Generated_Code/memwritep32_asm.obj \

ASM_DEPS += \
./Generated_Code/archGetLimitBit_asm.d \
./Generated_Code/archgetsetsaturationmode_asm.d \
./Generated_Code/memcopyptop_asm.d \
./Generated_Code/memcopyptox_asm.d \
./Generated_Code/memcopyxtop_asm.d \
./Generated_Code/memcpy_asm.d \
./Generated_Code/memreadp16_asm.d \
./Generated_Code/memreadp32_asm.d \
./Generated_Code/memset_asm.d \
./Generated_Code/memsetp_asm.d \
./Generated_Code/memwritep16_asm.d \
./Generated_Code/memwritep32_asm.d \

OBJS_QUOTED += \
"./Generated_Code/Cpu_c.obj" \
"./Generated_Code/MEM1_c.obj" \
"./Generated_Code/SS1_c.obj" \
"./Generated_Code/Vectors_c.obj" \
"./Generated_Code/archGetLimitBit_asm.obj" \
"./Generated_Code/archgetsetsaturationmode_asm.obj" \
"./Generated_Code/mem_c.obj" \
"./Generated_Code/memcopyptop_asm.obj" \
"./Generated_Code/memcopyptox_asm.obj" \
"./Generated_Code/memcopyxtop_asm.obj" \
"./Generated_Code/memcpy_asm.obj" \
"./Generated_Code/memreadp16_asm.obj" \
"./Generated_Code/memreadp32_asm.obj" \
"./Generated_Code/memset_asm.obj" \
"./Generated_Code/memsetp_asm.obj" \
"./Generated_Code/memtarget_c.obj" \
"./Generated_Code/memwritep16_asm.obj" \
"./Generated_Code/memwritep32_asm.obj" \

C_DEPS += \
./Generated_Code/Cpu_c.d \
./Generated_Code/MEM1_c.d \
./Generated_Code/SS1_c.d \
./Generated_Code/Vectors_c.d \
./Generated_Code/mem_c.d \
./Generated_Code/memtarget_c.d \

ASM_DEPS_QUOTED += \
"./Generated_Code/archGetLimitBit_asm.d" \
"./Generated_Code/archgetsetsaturationmode_asm.d" \
"./Generated_Code/memcopyptop_asm.d" \
"./Generated_Code/memcopyptox_asm.d" \
"./Generated_Code/memcopyxtop_asm.d" \
"./Generated_Code/memcpy_asm.d" \
"./Generated_Code/memreadp16_asm.d" \
"./Generated_Code/memreadp32_asm.d" \
"./Generated_Code/memset_asm.d" \
"./Generated_Code/memsetp_asm.d" \
"./Generated_Code/memwritep16_asm.d" \
"./Generated_Code/memwritep32_asm.d" \

C_DEPS_QUOTED += \
"./Generated_Code/Cpu_c.d" \
"./Generated_Code/MEM1_c.d" \
"./Generated_Code/SS1_c.d" \
"./Generated_Code/Vectors_c.d" \
"./Generated_Code/mem_c.d" \
"./Generated_Code/memtarget_c.d" \

OBJS_OS_FORMAT += \
./Generated_Code/Cpu_c.obj \
./Generated_Code/MEM1_c.obj \
./Generated_Code/SS1_c.obj \
./Generated_Code/Vectors_c.obj \
./Generated_Code/archGetLimitBit_asm.obj \
./Generated_Code/archgetsetsaturationmode_asm.obj \
./Generated_Code/mem_c.obj \
./Generated_Code/memcopyptop_asm.obj \
./Generated_Code/memcopyptox_asm.obj \
./Generated_Code/memcopyxtop_asm.obj \
./Generated_Code/memcpy_asm.obj \
./Generated_Code/memreadp16_asm.obj \
./Generated_Code/memreadp32_asm.obj \
./Generated_Code/memset_asm.obj \
./Generated_Code/memsetp_asm.obj \
./Generated_Code/memtarget_c.obj \
./Generated_Code/memwritep16_asm.obj \
./Generated_Code/memwritep32_asm.obj \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/Cpu_c.obj: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: DSC Compiler'
	"$(DSC_ToolsDirEnv)/mwcc56800e" -c @@"Generated_Code/Cpu.args" -o "Generated_Code/Cpu_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/%.d: ../Generated_Code/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Generated_Code/MEM1_c.obj: ../Generated_Code/MEM1.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: DSC Compiler'
	"$(DSC_ToolsDirEnv)/mwcc56800e" -c @@"Generated_Code/MEM1.args" -o "Generated_Code/MEM1_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/SS1_c.obj: ../Generated_Code/SS1.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: DSC Compiler'
	"$(DSC_ToolsDirEnv)/mwcc56800e" -c @@"Generated_Code/SS1.args" -o "Generated_Code/SS1_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors_c.obj: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: DSC Compiler'
	"$(DSC_ToolsDirEnv)/mwcc56800e" -c @@"Generated_Code/Vectors.args" -o "Generated_Code/Vectors_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/archGetLimitBit_asm.obj: ../Generated_Code/archGetLimitBit.asm
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: DSC Assembler'
	"$(DSC_ToolsDirEnv)/mwasm56800e" @@"Generated_Code/archGetLimitBit.args" -o "Generated_Code/archGetLimitBit_asm.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/%.d: ../Generated_Code/%.asm
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Generated_Code/archgetsetsaturationmode_asm.obj: ../Generated_Code/archgetsetsaturationmode.asm
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: DSC Assembler'
	"$(DSC_ToolsDirEnv)/mwasm56800e" @@"Generated_Code/archgetsetsaturationmode.args" -o "Generated_Code/archgetsetsaturationmode_asm.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/mem_c.obj: ../Generated_Code/mem.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: DSC Compiler'
	"$(DSC_ToolsDirEnv)/mwcc56800e" -c @@"Generated_Code/mem.args" -o "Generated_Code/mem_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/memcopyptop_asm.obj: ../Generated_Code/memcopyptop.asm
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: DSC Assembler'
	"$(DSC_ToolsDirEnv)/mwasm56800e" @@"Generated_Code/memcopyptop.args" -o "Generated_Code/memcopyptop_asm.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/memcopyptox_asm.obj: ../Generated_Code/memcopyptox.asm
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: DSC Assembler'
	"$(DSC_ToolsDirEnv)/mwasm56800e" @@"Generated_Code/memcopyptox.args" -o "Generated_Code/memcopyptox_asm.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/memcopyxtop_asm.obj: ../Generated_Code/memcopyxtop.asm
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: DSC Assembler'
	"$(DSC_ToolsDirEnv)/mwasm56800e" @@"Generated_Code/memcopyxtop.args" -o "Generated_Code/memcopyxtop_asm.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/memcpy_asm.obj: ../Generated_Code/memcpy.asm
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: DSC Assembler'
	"$(DSC_ToolsDirEnv)/mwasm56800e" @@"Generated_Code/memcpy.args" -o "Generated_Code/memcpy_asm.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/memreadp16_asm.obj: ../Generated_Code/memreadp16.asm
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: DSC Assembler'
	"$(DSC_ToolsDirEnv)/mwasm56800e" @@"Generated_Code/memreadp16.args" -o "Generated_Code/memreadp16_asm.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/memreadp32_asm.obj: ../Generated_Code/memreadp32.asm
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: DSC Assembler'
	"$(DSC_ToolsDirEnv)/mwasm56800e" @@"Generated_Code/memreadp32.args" -o "Generated_Code/memreadp32_asm.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/memset_asm.obj: ../Generated_Code/memset.asm
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: DSC Assembler'
	"$(DSC_ToolsDirEnv)/mwasm56800e" @@"Generated_Code/memset.args" -o "Generated_Code/memset_asm.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/memsetp_asm.obj: ../Generated_Code/memsetp.asm
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: DSC Assembler'
	"$(DSC_ToolsDirEnv)/mwasm56800e" @@"Generated_Code/memsetp.args" -o "Generated_Code/memsetp_asm.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/memtarget_c.obj: ../Generated_Code/memtarget.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: DSC Compiler'
	"$(DSC_ToolsDirEnv)/mwcc56800e" -c @@"Generated_Code/memtarget.args" -o "Generated_Code/memtarget_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/memwritep16_asm.obj: ../Generated_Code/memwritep16.asm
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: DSC Assembler'
	"$(DSC_ToolsDirEnv)/mwasm56800e" @@"Generated_Code/memwritep16.args" -o "Generated_Code/memwritep16_asm.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/memwritep32_asm.obj: ../Generated_Code/memwritep32.asm
	@echo 'Building file: $<'
	@echo 'Executing target #21 $<'
	@echo 'Invoking: DSC Assembler'
	"$(DSC_ToolsDirEnv)/mwasm56800e" @@"Generated_Code/memwritep32.args" -o "Generated_Code/memwritep32_asm.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


