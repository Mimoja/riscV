//
// Created by mimoja on 22.06.17.
//

#ifndef RISCV_SLL_H
#define RISCV_SLL_H

#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class SLL : public Instruction {
    public:
        SLL(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "SLL %d, %d, %d", instr.R.rd, instr.R.rs1, instr.R.rs2);
        }
        void execute(registers* reg, memory* mem) {
            reg->setReg32(instr.I.rd, reg->getReg32(instr.R.rs1) << (reg->getReg32(instr.R.rs2) & 0x1F));
        }
    };

}

#endif //RISCV_SLL_H
