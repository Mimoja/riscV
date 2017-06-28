//
// Created by Mimoja on 24.06.2017.
//

#ifndef RISCV_DIVU_H
#define RISCV_DIVU_H

#include "../../Instruction.h"
#include "../../../hardware/registers.h"

namespace instructions {
    class DIVU : public Instruction {
    public:
        DIVU(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "DIVU %s, %s, %s", registers::getName(instr.R.rd), registers::getName(instr.R.rs1), registers::getName(instr.R.rs2));
        }
        void execute(registers* reg, memory* mem) {
            uint32_t val1 = reg->getReg32(instr.R.rs2);
            uint32_t val2 = reg->getReg32(instr.R.rs2);
            if (val2 == 0) reg->setReg32(instr.R.rd, 0xffffffff);
            else reg->setReg32(instr.R.rd, val1 / val2);
        }
    };

}

#endif //RISCV_DIVU_H
