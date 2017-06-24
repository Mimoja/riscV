//
// Created by mimoja on 22.06.17.
//

#ifndef RISCV_ADD_H
#define RISCV_ADD_H

#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class ADD : public Instruction {
    public:
        ADD(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "ADD %s, %s, %s", registers::getName(instr.R.rd), registers::getName(instr.R.rs1), registers::getName(instr.R.rs2));
        }
        void execute(registers* reg, memory* mem) {
            reg->setReg32(instr.R.rd , reg->getReg32(instr.R.rs1) + reg->getReg32(instr.R.rs2));
        }
    };

}

#endif //RISCV_ADD_H
