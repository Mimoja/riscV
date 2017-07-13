cmake_minimum_required(VERSION 3.7)
project(riscV)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

include_directories(extern)

set(SOURCE_FILES
        src/main.cpp
        src/decoder/opcodes.cpp
        src/decoder/decoder.cpp
        src/decoder/decoder.h
        src/decoder/opcodes.h
        src/hardware/memory.h
        src/hardware/registers.h
        src/hardware/registers.cpp
        src/hardware/CSR/csr_entry.h
        src/hardware/CSR/misa.h
        src/instructions/all.h
        src/instructions/base_I/ADD.h
        src/instructions/base_I/ADDI.h
        src/instructions/base_I/AND.h
        src/instructions/base_I/ANDI.h
        src/instructions/base_I/AUIPC.h
        src/instructions/base_I/BEQ.h
        src/instructions/base_I/BGE.h
        src/instructions/base_I/BGEU.h
        src/instructions/base_I/BLT.h
        src/instructions/base_I/BLTU.h
        src/instructions/base_I/BNE.h
        src/instructions/base_I/CSRRC.h
        src/instructions/base_I/CSRRCI.h
        src/instructions/base_I/CSRRS.h
        src/instructions/base_I/CSRRSI.h
        src/instructions/base_I/CSRRW.h
        src/instructions/base_I/CSRRWI.h
        src/instructions/base_I/ECALL.h
        src/instructions/base_I/EBREAK.h
        src/instructions/base_I/FENCE.h
        src/instructions/base_I/FENCE.I.h
        src/instructions/base_I/JAL.h
        src/instructions/base_I/JALR.h
        src/instructions/base_I/LB.h
        src/instructions/base_I/LBU.h
        src/instructions/base_I/LH.h
        src/instructions/base_I/LHU.h
        src/instructions/base_I/LUI.h
        src/instructions/base_I/LW.h
        src/instructions/base_I/OR.h
        src/instructions/base_I/ORI.h
        src/instructions/base_I/SB.h
        src/instructions/base_I/SH.h
        src/instructions/base_I/SLL.h
        src/instructions/base_I/SLLI.h
        src/instructions/base_I/SLT.h
        src/instructions/base_I/SLTI.h
        src/instructions/base_I/SLTIU.h
        src/instructions/base_I/SLTU.h
        src/instructions/base_I/SRA.h
        src/instructions/base_I/SRAI.h
        src/instructions/base_I/SRL.h
        src/instructions/base_I/SRLI.h
        src/instructions/base_I/SUB.h
        src/instructions/base_I/SW.h
        src/instructions/base_I/XOR.h
        src/instructions/base_I/XORI.h
        src/instructions/Instruction.h
        src/instructions/extension/M/DIV.h
        src/instructions/extension/M/DIVU.h
        src/instructions/extension/M/MUL.h
        src/instructions/extension/M/MULH.h
        src/instructions/extension/M/MULHSU.h
        src/instructions/extension/M/MULHU.h
        src/instructions/extension/M/REM.h
        src/instructions/extension/M/REMU.h
        src/instructions/extension/F/FLW.h
        src/instructions/extension/F/FSW.h
        src/instructions/extension/F/FMADD.S.h
        src/instructions/extension/F/FADD.S..h
        src/instructions/extension/F/FSUB.S.h
        src/instructions/extension/F/FMUL.S.h
        src/instructions/extension/F/FDIV.S.h
        src/instructions/extension/F/FMIN.S.h
        src/instructions/extension/F/FMAX.S.h
        )

add_executable(riscV ${SOURCE_FILES})