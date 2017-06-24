//
// Created by mimoja on 22.06.17.
//

#ifndef RISCV_OR_H
#define RISCV_OR_H

#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class OR : public Instruction {
    public:
        OR(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "OR %d, %d, %d", instr.R.rd, instr.R.rs1, instr.R.rs2);
        }
        void execute(registers* reg, memory* mem) {
            reg->setReg32(instr.R.rd , reg->getReg32(instr.R.rs1) | reg->getReg32(instr.R.rs2));
        }
    };

}

#endif //RISCV_OR_H
