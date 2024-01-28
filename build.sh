#!/bin/bash

# Colors
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
RED='\033[0;31m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
NC='\033[0m' # No Color

# Symbols
CHECKMARK='\xE2\x9C\x94'
ROCKET='\xF0\x9F\x9A\x80'
CROSSMARK='\xE2\x9C\x98'
HOURGLASS='\xE2\x8C\x9B'

# Check if the folder name is provided as an argument
if [ $# -ne 1 ]; then
    echo -e "${RED}${CROSSMARK} Usage: $0 FolderName${NC}"
    exit 1
fi

cpp_file="code.cpp"
folder_name="$1"
compile_success=0

# Check if the folder exists
if [ ! -d "$folder_name" ]; then
    echo -e "${RED}${CROSSMARK} Folder '$folder_name' does not exist.${NC}"
    exit 1
fi

# Check if '$cpp_file' file exists in the folder
if [ ! -f "$folder_name/$cpp_file" ]; then
    echo -e "${RED}${CROSSMARK} File '$cpp_file' does not exist in the folder '$folder_name'.${NC}"
    exit 1
fi

# Compile for Linux
echo ""
echo -e "${BLUE}${HOURGLASS} Compiling for Linux...${NC}"
g++ "$folder_name/$cpp_file" -o "$folder_name/run"

if [ $? -eq 0 ]; then
    echo -e "${GREEN}${CHECKMARK} Compilation for Linux completed successfully.${NC}"
    compile_success=1
else
    echo -e "${RED}${CROSSMARK} Compilation for Linux failed.${NC}"
fi

# Compile for Windows
echo ""
echo -e "${BLUE}${HOURGLASS} Compiling for Windows...${NC}"
x86_64-w64-mingw32-g++ "$folder_name/$cpp_file" -o "$folder_name/run.exe" -static -static-libgcc -static-libstdc++ -mwindows

if [ $? -eq 0 ]; then
    echo -e "${GREEN}${CHECKMARK} Compilation for Windows completed successfully.${NC}"
    compile_success=$((compile_success + 2))
else
    echo -e "${RED}${CROSSMARK} Compilation for Windows failed.${NC}"
fi

# Output final result based on compilation success
echo ""
case $compile_success in
0)
    echo -e "${RED}Both compilations failed.${NC}"
    exit 1
    ;;
1)
    echo -e "${RED}Windows compilation failed.${NC}"
    exit 1
    ;;
2)
    echo -e "${RED}Linux compilation failed.${NC}"
    exit 1
    ;;
3)
    echo -e "${GREEN}${ROCKET} Compilation completed successfully.${NC}"
    ;;
esac