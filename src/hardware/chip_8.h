#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// internally used program name
#define CHIP8_EMU_NAME      "chip8_emu\0"


//
// - system info -
//

#define CHIP8_RAM_SIZE              4096

#define CHIP8_PROG_START_DEFAULT    0x200
#define CHIP8_MAX_PROG_SIZE         CHIP8_RAM_SIZE - CHIP8_PROG_START_DEFAULT

// prog_data: program data info
typedef struct {
    uint8_t *program_space;         // points to start of addressable program memory (0x200 default)
    uint16_t program_size;          // size of program_space, initialized in load_program()
} prog_data;

// c_device: chip-8 virtual c_device info
typedef struct {
    uint8_t ram[CHIP8_RAM_SIZE];    // Chip-8 RAM buffer
    prog_data program;              // loaded program
} c_device;


//
// - system functions -
//

// load program onto device located at chip_8, initialize device
int load_program(c_device *chip_8, char *filepath);


//
// - error handling -
//

// list possible exception codes
enum err_code {
    SAMPLE_ERR,
};

// throw an exception and handle it accordingly, exiting if return is not possible
void throw_except(enum err_code err);