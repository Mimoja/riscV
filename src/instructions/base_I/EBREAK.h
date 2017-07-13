//
// Created by mimoja on 29.06.17.
//

#ifndef RISCV_EBREAK_H
#define RISCV_EBREAK_H

#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class EBREAK : public Instruction {
    public:
        EBREAK(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "EBREAK %s, %s, %d", reg.gp.getRegisterName(instr.I.rd),
                    reg.gp.getRegisterName(instr.I.rs1), instr.I.getImm());
        }

        void execute(registers *reg, memory *mem) {
            throw "unimplemented";
        }
    };
}

#endif //RISCV_EBREAK_H
