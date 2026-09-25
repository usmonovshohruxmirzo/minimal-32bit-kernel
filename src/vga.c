#include "vga.h"

#define VIDEO_MEMORY (void *)0xb8000

#define WHITE_ON_BLUE 0x1F

#define VGA_MEM_WIDTH 80
#define VGA_MEM_HEIGHT 25

static unsigned int cursor = 0;

void clear_screen(void)
{
    char *video_memory = VIDEO_MEMORY;
    unsigned int i = 0;

    while (i < VGA_MEM_WIDTH * VGA_MEM_HEIGHT * 2) {
        video_memory[i] = 0;
        video_memory[i + 1] = WHITE_ON_BLUE;
        i += 2;
    }

    cursor = 0;
}

void putchar(char c)
{
    char *video_memory = VIDEO_MEMORY;

    if (c == '\n') {
        unsigned int row = cursor / (VGA_MEM_WIDTH * 2);
        cursor = (row + 1) * VGA_MEM_WIDTH * 2;
        return;
    }

    video_memory[cursor] = c;
    video_memory[cursor + 1] = WHITE_ON_BLUE;

    cursor += 2;
}

void putstr(const char *str)
{
    unsigned int i = 0;

    while (str[i] != '\0') {
        putchar(str[i]);
        i++;
    }
}
