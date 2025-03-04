# locations of source code and target build files
SRC_DIR = src
BUILD_DIR = build

# tracks all source files to be compiled on build, and compiler settings 
SRC_C = $(SRC_DIR)/main.c $(SRC_DIR)/hardware/chip_8.c $(SRC_DIR)/hardware/c_display.c
FLAGS = -Wall -Wextra -Werror

# program file to be loaded in make run
P ?= s.ch8

# BUILD TARGETS

# compile, clear terminal, and run
run: build
	clear
	@ cd $(BUILD_DIR); ./emu $(P)

# compile only in build dir
build: setup $(SRC_C) 
	gcc -o $(BUILD_DIR)/emu $(SRC_C) $(FLAGS)

# compile disassembler
d: setup $(SRC_C)
	gcc -o $(BUILD_DIR)/emu_disasm $(SRC_DIR)/hardware/chip_8.c $(SRC_DIR)/disasm.c

d_run: d
	clear
	@ cd $(BUILD_DIR); ./emu_disasm $(P)

# init setup
setup:
	@ if !([ -e $(BUILD_DIR) ]); then mkdir $(BUILD_DIR); fi;