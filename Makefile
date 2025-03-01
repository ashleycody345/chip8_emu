SRC_DIR = src
BUILD_DIR = build

SRC_C = $(SRC_DIR)/main.c

FLAGS = -Wall -Wextra -Werror

build: setup $(SRC_C) 
	gcc -o $(BUILD_DIR)/emu $(SRC_C) $(FLAGS)

run: build
	clear
	@ ./$(BUILD_DIR)/emu

setup:
	@ if !([ -e $(BUILD_DIR) ]); then mkdir $(BUILD_DIR); fi;