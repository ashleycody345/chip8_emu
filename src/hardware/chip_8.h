#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// internally used program name
#define CHIP8_EMU_NAME      "chip8_emu\0"


//
// - system info -
//

#define CHIP8_RAM_SIZE      4096

// prog_data: program data info
typedef struct {
    uint8_t *program_space;         // points to start of addressable program memory (0x200 default)
    uint16_t program_size;          // size of program_space, initialized in load_program()
} prog_data;

// device: chip-8 virtual device info
typedef struct {
    uint8_t ram[CHIP8_RAM_SIZE];    // Chip-8 RAM buffer
    prog_data program;              // loaded program
} device;


//
// - system functions -
//

// load program onto device located at chip_8, initialize device
int load_program(device *chip_8, char *filepath);