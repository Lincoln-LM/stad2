BASEROM = baserom.z64
TARGET = pokemonstadium2
NON_MATCHING = 0

# Fail early if baserom does not exist
ifeq ($(wildcard $(BASEROM)),)
$(error Baserom `$(BASEROM)' not found.)
endif

BUILD_DIR := build
EXPECTED_DIR := expected/build
ROM := $(TARGET).z64
ELF := $(BUILD_DIR)/$(TARGET).elf
LD_SCRIPT := $(TARGET).ld
LD_MAP := $(BUILD_DIR)/$(TARGET).map
ASM_DIRS := asm asm/os asm/data asm/data/libultra/gu asm/libultra/gu
DATA_DIRS := bin assets
SRC_DIRS := $(shell find src -type d)

C_FILES := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
S_FILES := $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
DATA_FILES := $(foreach dir,$(DATA_DIRS),$(wildcard $(dir)/*.bin))

# Object files
O_FILES := $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file:.c=.o)) \
           $(foreach file,$(S_FILES),$(BUILD_DIR)/$(file:.s=.o)) \
           $(foreach file,$(DATA_FILES),$(BUILD_DIR)/$(file:.bin=.o)) \

SPLAT_YAML := pokemonstadium2.yaml
SPLAT = $(PYTHON) tools/splat/split.py $(SPLAT_YAML)

##################### Compiler Options #######################
CROSS = mips-linux-gnu-
AS = $(CROSS)as
LD = $(CROSS)ld
OBJDUMP = $(CROSS)objdump
OBJCOPY = $(CROSS)objcopy
CPP := cpp

CC = tools/ido_recomp/linux/5.3/cc

ASFLAGS = -EB -mtune=vr4300 -march=vr4300 -Iinclude
CFLAGS  = -G 0 -non_shared -Xfullwarn -Xcpluscomm -Iinclude -Wab,-r4300_mul -D _LANGUAGE_C -mips2 -O2
LDFLAGS = -T undefined_syms_auto.txt -T undefined_funcs_auto.txt -T $(BUILD_DIR)/$(LD_SCRIPT) -Map $(BUILD_DIR)/$(TARGET).map --no-check-sections

OPTFLAGS := -O2

######################## Targets #############################

$(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(DATA_DIRS) $(COMPRESSED_DIRS) $(MAP_DIRS) $(BGM_DIRS),$(shell mkdir -p build/$(dir)))

build/src/os/O1/%.o: OPTFLAGS := -O1
build/src/%.o: CC := python3 tools/asm_processor/build.py $(CC) -- $(AS) $(ASFLAGS) --

default: all

LD_SCRIPT = $(TARGET).ld

expected: all copy

copy:
	rm -rf $(EXPECTED_DIR)
	cp -r $(BUILD_DIR) $(EXPECTED_DIR)

all: $(BUILD_DIR) $(TARGET).z64 verify

clean:
	rm -rf $(BUILD_DIR) $(TARGET).z64

submodules:
	# git submodule update --init --recursive

split:
	rm -rf $(DATA_DIRS) $(ASM_DIRS) && ./tools/splat/split.py $(SPLAT_YAML)

setup: clean submodules split
	
$(BUILD_DIR):
	echo $(C_FILES)
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/$(LD_SCRIPT): $(LD_SCRIPT)
	@mkdir -p $(shell dirname $@)
	$(CPP) -P -DBUILD_DIR=$(BUILD_DIR) -o $@ $<

$(BUILD_DIR)/$(TARGET).bin: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) $< $@ -O binary

$(BUILD_DIR)/$(TARGET).elf: $(O_FILES) $(BUILD_DIR)/$(LD_SCRIPT)
	@$(LD) $(LDFLAGS) -o $@

$(BUILD_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(OPTFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: %.bin
	$(LD) -r -b binary -o $@ $<

# $(LD_SCRIPT): $(SPLAT_YAML)
# 	$(SPLAT) --modes ld

# final z64 updates checksum
$(TARGET).z64: $(BUILD_DIR)/$(TARGET).bin
	@cp $< $@

verify: $(TARGET).z64
	md5sum -c checksum.md5

.PHONY: all clean default split setup