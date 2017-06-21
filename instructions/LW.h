//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_LW_H
#define RISCV_LW_H

#include "Instruction.h"

namespace instructions {
    class LW : public Instruction {
    public:
        LW(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "LW %d, %d(%d)", instr.I.rd, instr.I.getImm(), instr.I.rs1);
        }
        void execute(registers* reg, memory* mem) {
            reg->setReg32(instr.I.rd, mem->getWord(reg->getReg32(instr.I.rs1)  + instr.I.getImm()));
        }
    };

}
#endif //RISCV_LW_H
