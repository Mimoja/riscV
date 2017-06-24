//
// Created by Mimoja on 24.06.2017.
//

#ifndef RISCV_MUL_H
#define RISCV_MUL_H

#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class MUL : public Instruction {
    public:
        MUL(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "MUL %s, %s, %s", registers::getName(instr.R.rd), registers::getName(instr.R.rs1), registers::getName(instr.R.rs2));
        }
        void execute(registers* reg, memory* mem) {
            reg->setReg32(instr.R.rd, reg->getReg32(instr.R.rs1) * reg->getReg32(instr.R.rs2));
        }
    };

}
#endif //RISCV_MUL_H
