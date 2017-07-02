cmake_minimum_required(VERSION 3.7)
project(riscV)

set(CMAKE_CXX_STANDARD 14)

include_directories(extern)
set(SOURCE_FILES
        main.cpp
        decoder/opcodes.cpp
        decoder/decoder.cpp
        decoder/decoder.h
        decoder/opcodes.h
        hardware/memory.h
        hardware/registers.h
        instructions/all.h
        instructions/base_I/ADD.h
        instructions/base_I/ADDI.h
        instructions/base_I/AND.h
        instructions/base_I/ANDI.h
        instructions/base_I/AUIPC.h
        instructions/base_I/BEQ.h
        instructions/base_I/BGE.h
        instructions/base_I/BGEU.h
        instructions/base_I/BLT.h
        instructions/base_I/BLTU.h
        instructions/base_I/BNE.h
        instructions/base_I/CSRRC.h
        instructions/base_I/CSRRCI.h
        instructions/base_I/CSRRS.h
        instructions/base_I/CSRRSI.h
        instructions/base_I/CSRRW.h
        instructions/base_I/CSRRWI.h
        instructions/base_I/ECALL.h
        instructions/base_I/EBREAK.h
        instructions/base_I/FENCE.h
        instructions/base_I/FENCE.I.h
        instructions/base_I/JAL.h
        instructions/base_I/JALR.h
        instructions/base_I/LB.h
        instructions/base_I/LBU.h
        instructions/base_I/LH.h
        instructions/base_I/LHU.h
        instructions/base_I/LUI.h
        instructions/base_I/LW.h
        instructions/base_I/OR.h
        instructions/base_I/ORI.h
        instructions/base_I/SB.h
        instructions/base_I/SH.h
        instructions/base_I/SLL.h
        instructions/base_I/SLLI.h
        instructions/base_I/SLT.h
        instructions/base_I/SLTI.h
        instructions/base_I/SLTIU.h
        instructions/base_I/SLTU.h
        instructions/base_I/SRA.h
        instructions/base_I/SRAI.h
        instructions/base_I/SRL.h
        instructions/base_I/SRLI.h
        instructions/base_I/SUB.h
        instructions/base_I/SW.h
        instructions/base_I/XOR.h
        instructions/base_I/XORI.h
        instructions/Instruction.h
        instructions/extension/M/DIV.h
        instructions/extension/M/DIVU.h
        instructions/extension/M/MUL.h
        instructions/extension/M/MULH.h
        instructions/extension/M/MULHSU.h
        instructions/extension/M/MULHU.h
        instructions/extension/M/REM.h
        instructions/extension/M/REMU.h hardware/CSR/csr_register.h hardware/CSR/misa.h)

add_executable(riscV ${SOURCE_FILES})