#include "chip_8.h"

#include <string.h>

//
// - system functions -
//

// load program onto device located at chip_8, initialize device
int load_program(device *chip_8) {
    // set RAM to all 0
    memset(chip_8->ram, 0, CHIP8_RAM_SIZE);


    return 0;
}