#include "chip_8.h"

#include <string.h>

//
// - system functions -
//

// load program onto device located at chip_8, initialize device
// returns 0 on success, < 0 else
int load_program(device *chip_8, char *filepath) {
    // set RAM to all 0
    memset(chip_8->ram, 0, CHIP8_RAM_SIZE);

    // open file 
    FILE *prog_text = fopen(filepath, "r");
    if(!prog_text) {
        fprintf(stderr, "%s::ERROR: could not find program data located at %s\n", CHIP8_EMU_NAME, filepath);
        return -1;
    }

    return 0;
}