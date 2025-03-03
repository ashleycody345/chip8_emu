#include "hardware/chip_8.h"

int main(int argc, char **argv) {
    if(argc != 2) {
        fprintf(stderr, "%s: usage - %s program_path\n", CHIP8_EMU_NAME, argv[0]);
        exit(2);
    }

    device emu_chip8;

    int load_status = load_program(&emu_chip8, argv[1]);
    if(load_status < 0){
        goto init_err;
    }


    for(int i = 0; i < CHIP8_RAM_SIZE; i++) {
        if(i%16 == 0) printf("\n%03x: ", i);
        printf("%02x ", emu_chip8.ram[i]);
    }

    return 0;


// generic label for failure to init chip_8
init_err:
    fprintf(stderr, "%s::ABORT: device failed to initialize\n", CHIP8_EMU_NAME);
    exit(1);
}