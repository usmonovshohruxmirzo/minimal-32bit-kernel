#define VIDEO_MEMORY (void *)0xb8000

#define WHITE_ON_BLUE 0x1F
#define GREEN_ON_BLACK 0x02

#define VGA_MEM_WIDTH 80
#define VGA_MEM_HEIGHT 25

void clear_screen() {
  char *video_memory = VIDEO_MEMORY;
  unsigned int i = 0;

  while (i < VGA_MEM_WIDTH * VGA_MEM_HEIGHT * 2) {
    video_memory[i] = 0;
    video_memory[i + 1] = WHITE_ON_BLUE;
    i += 2;
  }
}

unsigned int cursor = 0;

void putchar(char c) {
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

void putstr(const char *str) {
  unsigned int i = 0;

  while (str[i] != '\0') {
    putchar(str[i]);
    i++;
  }
}

void kernel_main(void) {
  clear_screen();

  putstr(" $ Nitro Kernel");
  putchar('\n');
  putstr(" $ HAHAHAHHAH");
  putchar('\n');
  putstr(" $ Helloooooooooo");

  while (1) {
    __asm__("hlt");
  }

  return;
}
