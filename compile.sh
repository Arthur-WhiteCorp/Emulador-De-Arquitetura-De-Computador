#!/bin/bash

# Directories
SRC_DIR="src"
HEADER_DIR="headers"
OBJ_DIR="objects"
BUILD_DIR="build"
TEST_DIR="testes"

# Create output directories if they don't exist
mkdir -p $OBJ_DIR
mkdir -p $BUILD_DIR

# Compiler settings
CXX=g++  # Using g++ for C++ compilation
CXXFLAGS="-I$HEADER_DIR"  # Include headers from the headers directory
LDFLAGS=""  # Linker flags (if needed)
TARGET="$BUILD_DIR/main"  # Final compiled executable

# Find all .cpp files in the src directory
SRC_FILES=$(find $SRC_DIR -name "*.cpp")

# Compile each source file into object files in the objects directory
for src in $SRC_FILES; do
    # Get the relative path and replace the src directory with the object directory
    obj="$OBJ_DIR/$(basename ${src%.cpp}.o)"
    
    # Compile the source file into an object file
    $CXX -c $src $CXXFLAGS -o $obj
done

# Link all object files to create the final executable
$CXX $OBJ_DIR/*.o $LDFLAGS -o $TARGET

# Output result
if [ -f "$TARGET" ]; then
    echo "Compilation successful! Executable is located at $TARGET"
else
    echo "Compilation failed."
fi
