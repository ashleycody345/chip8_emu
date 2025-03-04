#include "hardware/chip_8.h"

void disassemble(c_device *chip_8);

int main(int argc, char **argv) {
    if(argc != 2) {
        fprintf(stderr, "%s: usage - %s program_path\n", CHIP8_EMU_NAME, argv[0]);
        exit(2);
    }

    c_device emu_chip8;

    int load_status = load_program(&emu_chip8, argv[1]);
    if(load_status < 0){
        goto init_err;
    }

    // disassemble program
    disassemble(&emu_chip8);

    return 0;


// generic label for failure to init chip_8
init_err:
    fprintf(stderr, "%s::ABORT: device failed to initialize\n", CHIP8_EMU_NAME);
    exit(1);
}

void disassemble(c_device *chip_8) {
    while(chip_8->reg_PC < chip_8->program.program_size) {
        ;
    }
}