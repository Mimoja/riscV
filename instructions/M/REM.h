//
// Created by Mimoja on 24.06.2017.
//

#ifndef RISCV_REM_H
#define RISCV_REM_H

#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class REM : public Instruction {
    public:
        REM(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "REM %s, %s, %s", registers::getName(instr.R.rd), registers::getName(instr.R.rs1), registers::getName(instr.R.rs2));
        }
        void execute(registers* reg, memory* mem) {
            int32_t val1 = (int32_t) reg->getReg32(instr.R.rs2);
            int32_t val2 = (int32_t) reg->getReg32(instr.R.rs2);
            if(val2 == 0) reg->setReg32(instr.R.rd, val1);
            else if(val1 == -(2^(32-1)) && val2 == -1) reg->setReg32(instr.R.rd, -(2^(32-1)));
            else reg->setReg32(instr.R.rd, val1 % val2);
        }
    };

}

#endif //RISCV_REM_H