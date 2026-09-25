#define VIDEO_MEMORY (void *)0xb8000

#define WHITE_ON_BLACK 0x0f
#define GREEN_ON_BLACK 0x02

#define VGA_MEM_WIDTH 80
#define VGA_MEM_HEIGHT 25

void clear_screen() {
  char *video_memory = VIDEO_MEMORY;
  unsigned int i = 0;

  while (i < VGA_MEM_WIDTH * VGA_MEM_HEIGHT * 2) {
    video_memory[i] = 0;
    video_memory[i + 1] = WHITE_ON_BLACK;
    i += 2;
  }
}

void kernel_main(void) {
  return;
}
