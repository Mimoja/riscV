cmake_minimum_required(VERSION 3.7)
project(riscV)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp decoder/opcodes.h decoder/decoder.h decoder/opcodes.cpp decoder/decoder.cpp instructions/Instruction.h instructions/ADDI.h instructions/SLTI.h instructions/LUI.h instructions/JAL.h instructions/LW.h instructions/JALR.h instructions/SW.h instructions/AUIPC.h instructions/BEQ.h instructions/BNE.h hardware/memory.h hardware/registers.h instructions/LH.h instructions/LB.h instructions/ADD.h)
add_executable(riscV ${SOURCE_FILES})