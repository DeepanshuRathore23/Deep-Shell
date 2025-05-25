# Compiler and flags
CC = gcc
CFLAGS = -Iincludes

# Output directories and binaries
BUILD_DIR = build
CLI_BIN = $(BUILD_DIR)/cli
GUI_BIN = $(BUILD_DIR)/gui

# Source files
CLI_SRC = $(wildcard src/*.c) \
          $(wildcard src/file_management/*.c) \
          $(wildcard src/process_management/*.c)

GUI_SRC = gui/gui_main.c

# Object files
CLI_OBJ = $(CLI_SRC:.c=.o)

# Default target
all: $(CLI_BIN)

# CLI Build Rule
$(CLI_BIN): $(CLI_OBJ) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# GUI Build Rule
gui: $(GUI_SRC) | $(BUILD_DIR)
	$(CC) $(GUI_SRC) -o $(GUI_BIN) `pkg-config --cflags --libs gtk+-3.0`

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean Rule
clean:
	rm -f $(CLI_OBJ) $(CLI_BIN) $(GUI_BIN)
