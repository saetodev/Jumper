#include "types.h"

#define REAL_SCREEN_WIDTH  240
#define REAL_SCREEN_HEIGHT 160

// VRAM BACKGROUND MODES
#define BG_MODE_0 0x0
#define BG_MODE_1 0x1
#define BG_MODE_2 0x2
#define BG_MODE_3 0x3
#define BG_MODE_4 0x4
#define BG_MODE_5 0x5

#define BG_BACKBUFFER 0x10

#define BG_ENABLE_0     0x100
#define BG_ENABLE_1     0x200
#define BG_ENABLE_2     0x400
#define BG_ENABLE_3     0x800
#define BG_ENABLE_OBJ   0x1000

// MEMORY MAPS
#define MEM_IO          0x04000000
#define MEM_PAL         0x05000000
#define MEM_VRAM        0x06000000
#define MEM_VRAM_BACK   0x0600A000
#define MEM_OAM         0x07000000

// DISPLAY REGISTORS
#define REG_DISPCNT  (*(volatile u16*)0x04000000)
#define REG_DISPSTAT (*(volatile u16*)0x04000004)
#define REG_VCOUNT   (*(volatile u16*)0x04000006)

static void WaitVBlanck(void) {
    while (REG_VCOUNT < 160);
}

static void WaitVDraw(void) {
    while (REG_VCOUNT >= 160);
}

int main(void) {

    while (1) {

        WaitVDraw();
        WaitVBlanck();
    }

    return 0;
}
