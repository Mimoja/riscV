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
        SLT(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "SLT %s, %s, %s", reg.gp.getRegisterName(instr.R.rd),
                    reg.gp.getRegisterName(instr.R.rs1),
                    reg.gp.getRegisterName(instr.R.rs2));
        }
        void execute(registers* reg, memory* mem) {
            reg->gp.setReg32Value(instr.I.rd , ((int32_t)reg->gp.getReg32Value(instr.R.rs1)) < ((int32_t)reg->gp.getReg32Value(instr.R.rs2)));
        }
    };

}

#endif //RISCV_SLT_H
