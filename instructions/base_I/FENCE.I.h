//
// Created by mimoja on 29.06.17.
//

#ifndef RISCV_FENCE_I_H
#define RISCV_FENCE_I_H

#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class FENCE_I : public Instruction {
    public:
        FENCE_I(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "FENCE.I %s, %s, %d", registers::getRegisterName(instr.I.rd),
                    registers::getRegisterName(instr.I.rs1), instr.I.getImm());
        }

        void execute(registers *reg, memory *mem) {
            throw "unimplemented";
        }
    };
}

#endif //RISCV_FENCE_I_H
