//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_SB_H
#define RISCV_SB_H

#include "../Instruction.h"

namespace instructions {
    class SB : public Instruction {
    public:
        SB(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "SB %d, %d(%d)", instr.S.rs2, instr.S.getImm(), instr.S.rs1);
        }
        void execute(registers* reg, memory* mem) {
            uint32_t targetAddr = reg->getReg32(instr.S.rs1)+ instr.S.getImm();
            mem->setByte(reg->getReg32(instr.S.rs2) & 0xFF, targetAddr);
        }
    };

}

#endif //RISCV_SB_H
