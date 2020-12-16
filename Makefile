CC = arm-none-eabi-gcc
CFLAGS = --specs=nosys.specs -mthumb -mcpu=cortex-m3

SRC_DIR = ./src
BIN_DIR = ./bin

compile : $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) $(SRC_DIR)/main.c -o $(BIN_DIR)/program.bin

flash: $(BIN_DIR)/program.bin
	st-flash write $(BIN_DIR)/program.bin 0x8000000