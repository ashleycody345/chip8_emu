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

    // get prog size
    fseek(prog_text, 0, SEEK_END);
    uint16_t prog_size = (uint16_t)ftell(prog_text);
    chip_8->program.program_size = prog_size;

    if(prog_size > CHIP8_MAX_PROG_SIZE) {
        fprintf(stderr, "%s::ERROR: program data at %s (size %u bytes) exceeds max Chip-8 program size of %u\n",
        CHIP8_EMU_NAME, filepath, prog_size, CHIP8_MAX_PROG_SIZE);
        return -1;
    }

    printf("%s: size of prog %s is %u\n", CHIP8_EMU_NAME, filepath, prog_size);

    // set memory pointer in chip-8 RAM
    chip_8->program.program_space = &chip_8->ram[CHIP8_PROG_START_DEFAULT];

    // load program into memory
    fseek(prog_text, 0, SEEK_SET);
    uint16_t prog_bytes_read = fread(chip_8->program.program_space, sizeof(uint8_t), prog_size, prog_text);

    if(prog_bytes_read != prog_size) {
        fprintf(stderr, "%s::ERROR: program data at \"%s\" was not read successfully (read %u out of %u bytes)\n", 
        CHIP8_EMU_NAME, filepath, prog_bytes_read, prog_size);
        return -1;
    }

    // close file and exit successfully
    fclose(prog_text);
    return 0;
}