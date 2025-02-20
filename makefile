# # Project Name
PROJECT_NAME = simple_shell 

# # Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# # Directories
SRC_DIR = src
BUILD_DIR = builds
INCLUDE_DIR = includes

# # Find all the source files and generate object files for them
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# # Default target
all: $(BUILD_DIR)/$(PROJECT_NAME)

# # Link the final executable
$(BUILD_DIR)/$(PROJECT_NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

# # Rule for compiling .c to .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

install: $(BUILD_DIR)/$(PROJECT_NAME)
	sudo cp $(BUILD_DIR)/$(PROJECT_NAME) ~/bin/
# # Clean the build folder
clean:
	rm -rf $(BUILD_DIR)/*
