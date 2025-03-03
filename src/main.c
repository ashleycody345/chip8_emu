#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define CHIP8_RAM_SIZE      4096

int main(int argc __attribute__((unused)), char **argv __attribute((unused))) {
    uint8_t mem[CHIP8_RAM_SIZE] = { 0 };

    for(int i = 0; i < CHIP8_RAM_SIZE; i++) {
        printf("%x\n", mem[i]);
    }

    return 0;
}