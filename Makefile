# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

# Directories
SRC_DIR = src
OBJ_DIR = obj
INST_DIR = src/instructions
INST_OBJ_DIR = obj/instructions
INST_CB_DIR = src/instructionsCB
INST_CB_OBJ_DIR = obj/instructionsCB
BIN = main

# Source files (main directory)
SRCS = $(wildcard $(SRC_DIR)/*.c)
# Source files (instructions directory)
INST_SRCS = $(wildcard $(INST_DIR)/*.c)
# Source files (instructionsCB directory)
INST_CB_SRCS = $(wildcard $(INST_CB_DIR)/*.c)

# Object files (main directory)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
# Object files (instructions directory)
INST_OBJS = $(INST_SRCS:$(INST_DIR)/%.c=$(INST_OBJ_DIR)/%.o)
# Object files (instructionsCB directory)
INST_CB_OBJS = $(INST_CB_SRCS:$(INST_CB_DIR)/%.c=$(INST_CB_OBJ_DIR)/%.o)

# All object files
ALL_OBJS = $(OBJS) $(INST_OBJS) $(INST_CB_OBJS)

# Default target
all: $(BIN)

# Link object files into final binary
$(BIN): $(ALL_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files into object files (main directory)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile source files into object files (instructions directory)
$(INST_OBJ_DIR)/%.o: $(INST_DIR)/%.c | $(INST_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile source files into object files (instructionsCB directory)
$(INST_CB_OBJ_DIR)/%.o: $(INST_CB_DIR)/%.c | $(INST_CB_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create obj directories if they don't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(INST_OBJ_DIR): | $(OBJ_DIR)
	mkdir -p $(INST_OBJ_DIR)

$(INST_CB_OBJ_DIR): | $(OBJ_DIR)
	mkdir -p $(INST_CB_OBJ_DIR)

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN)

.PHONY: all clean