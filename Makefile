BUILD_DIR := build

CC := gcc
LD := ld
AS := nasm

CFLAGS := -m32 -ffreestanding -nostdlib -fno-builtin -fno-stack-protector \
          -Wall -Wextra -Werror

all: $(BUILD_DIR)/kernel.bin

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/kernel.o: src/kernel.asm | $(BUILD_DIR)
	$(AS) -f elf32 $< -o $@

$(BUILD_DIR)/main.o: src/main.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/kernel.bin: $(BUILD_DIR)/kernel.o $(BUILD_DIR)/main.o
	$(LD) -m elf_i386 -T src/link.ld $^ -o $@

clean:
	rm -rf $(BUILD_DIR)

run: $(BUILD_DIR)/kernel.bin
	qemu-system-i386 -kernel $<
