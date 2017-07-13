//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_SLTI_H
#define RISCV_SLTI_H

#include "../Instruction.h"

namespace instructions {
    class SLTI : public Instruction {
    public:
        SLTI(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "SLTI %s, %s, %d", reg.gp.getRegisterName(instr.I.rd),
                    reg.gp.getRegisterName(instr.I.rs1), instr.I.getImm());
        }
        void execute(registers* reg, memory* mem) {
            reg->gp.setReg32Value(instr.I.rd, ((int32_t)reg->gp.getReg32Value(instr.I.rs1)) < ((int32_t)instr.I.getImm()));
        }
    };

}
#endif //RISCV_SLTI_H
