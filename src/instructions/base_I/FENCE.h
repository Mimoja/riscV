//
// Created by mimoja on 29.06.17.
//

#ifndef RISCV_FENCE_H
#define RISCV_FENCE_H

#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class FENCE : public Instruction {
    public:
        FENCE(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg){
        sprintf(disas_buffer, "FENCE %s, %s, %d", reg.gp.getRegisterName(instr.I.rd),
                    reg.gp.getRegisterName(instr.I.rs1), instr.I.getImm());
        }

        void execute(registers *reg, memory *mem) {
            throw "unimplemented";
        }
    };
}

#endif //RISCV_FENCE_H
