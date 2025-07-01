PROJECT=blinky_to_bootloader
BUILD_DIR=build
SRC=$(wildcard src/*.c)
LIBOPENCM3="../libopencm3"

CC=arm-none-eabi-gcc
CFLAGS=-I$(LIBOPENCM3)/include -O2 -g -Wall \
	   -mcpu=cortex-m4 -mthumb -std=gnu11 \
	   -DSTM32F4 \
	   -mfloat-abi=hard -mfpu=fpv4-sp-d16

LDFLAGS=-L$(LIBOPENCM3)/lib \
		-Tlinkerscript.ld \
		-nostartfiles -Wl,--gc-sections -Wl,-Map=$(BUILD_DIR)/$(PROJECT).map \
		-lopencm3_stm32f4 \
		-mfloat-abi=hard -mfpu=fpv4-sp-d16

$(BUILD_DIR)/$(PROJECT).elf: $(SRC)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

all: $(BUILD_DIR)/$(PROJECT).elf

flash: all
	openocd -f interface/stlink.cfg -f target/stm32f4x.cfg \
		-c "program $(BUILD_DIR)/$(PROJECT).elf verify reset exit"

clean:
	rm -rf $(BUILD_DIR)
