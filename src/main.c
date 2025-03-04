#include "hardware/chip_8.h"
#include "hardware/c_display.h"

int main(int argc, char **argv) {
    if(argc != 2) {
        fprintf(stderr, "%s: usage - %s program_path\n", CHIP8_EMU_NAME, argv[0]);
        exit(2);
    }

    c_device emu_chip8;
    c_display emu_display;
    (void) emu_display;

    int load_status = load_program(&emu_chip8, argv[1]);
    if(load_status < 0){
        goto init_err;
    }

    // main loop, execute program
    bool should_stop = false;
    while(!should_stop) {
        // 
    }

    return 0;


// generic label for failure to init chip_8
init_err:
    fprintf(stderr, "%s::ABORT: device failed to initialize\n", CHIP8_EMU_NAME);
    exit(1);
}