//
// Created by mimoja on 22.06.17.
//

#ifndef RISCV_XOR_H
#define RISCV_XOR_H

#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class XOR : public Instruction {
    public:
        XOR(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "XOR %s, %s, %s", registers::getName(instr.R.rd), registers::getName(instr.R.rs1), registers::getName(instr.R.rs2));
        }
        void execute(registers* reg, memory* mem) {
            reg->setReg32(instr.R.rd , reg->getReg32(instr.R.rs1) ^ reg->getReg32(instr.R.rs2));
        }
    };

}

#endif //RISCV_XOR_H
