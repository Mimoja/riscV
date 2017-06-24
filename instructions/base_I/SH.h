//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_SH_H
#define RISCV_SH_H

#include "../Instruction.h"

namespace instructions {
    class SH : public Instruction {
    public:
        SH(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "SH %d, %d(%d)", instr.S.rs2, instr.S.getImm(), instr.S.rs1);
        }
        void execute(registers* reg, memory* mem) {
            uint32_t targetAddr = reg->getReg32(instr.S.rs1)+ instr.S.getImm();
            mem->setHalfWord(reg->getReg32(instr.S.rs2) & 0xFFFF, targetAddr);
        }
    };

}

#endif //RISCV_SH_H
