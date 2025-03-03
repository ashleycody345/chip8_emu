#include "hardware/chip_8.h"

int main(int argc __attribute__((unused)), char **argv __attribute((unused))) {

    device emu_chip8;

    load_program(&emu_chip8);

    for(int i = 0; i < CHIP8_RAM_SIZE; i++) {
        printf("%d: %d\n", i, emu_chip8.ram[i]);
    }
    return 0;
}