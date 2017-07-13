//
// Created by Mimoja on 13.07.2017.
//

#ifndef RISCV_MRET_H
#define RISCV_MRET_H

#include "../../Instruction.h"
#include "../../../hardware/interrups.h"

namespace instructions {
    class MRET : public Instruction {
    public:
        MRET(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "MRET\n");
        }

        void execute(registers* reg, memory* mem) {
            throw priviledgeReturn();
        }
    };
}

#endif //RISCV_MRET_H
