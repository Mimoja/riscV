//
// Created by mimoja on 22.06.17.
//

#ifndef RISCV_SLT_H
#define RISCV_SLT_H

#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class SLT : public Instruction {
    public:
        SLT(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "SLT %s, %s, %s", registers::getRegisterName(instr.R.rd),
                    registers::getRegisterName(instr.R.rs1),
                    registers::getRegisterName(instr.R.rs2));
        }
        void execute(registers* reg, memory* mem) {
            reg->setReg32(instr.I.rd , ((int32_t)reg->getReg32(instr.R.rs1)) < ((int32_t)reg->getReg32(instr.R.rs2)));
        }
    };

}

#endif //RISCV_SLT_H
