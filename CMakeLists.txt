cmake_minimum_required(VERSION 3.7)
project(riscV)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp decoder/opcodes.h decoder/decoder.h decoder/opcodes.cpp decoder/decoder.cpp instructions/Instruction.h instructions/ADDI.h instructions/SLTI.h instructions/LUI.h instructions/JAL.h instructions/LW.h instructions/JALR.h instructions/SW.h)
add_executable(riscV ${SOURCE_FILES})