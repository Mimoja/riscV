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
        EBREAK(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "EBREAK %s, %s, %d", registers::getName(instr.I.rd), registers::getName(instr.I.rs1), instr.I.getImm());
        }

        void execute(registers *reg, memory *mem) {
            throw "unimplemented";
        }
    };
}

#endif //RISCV_EBREAK_H
