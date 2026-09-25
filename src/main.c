#include "vga.h"

void kernel_main(void)
{
    clear_screen();

    putstr(" $ Nitro Kernel");
    putchar('\n');
    putstr(" $ HAHAHAHHAH");
    putchar('\n');
    putstr(" $ Helloooooooooo");

    while (1) {
        __asm__("hlt");
    }
}
