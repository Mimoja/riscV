//
// Created by Mimoja on 13.07.2017.
//

#ifndef RISCV_SRET_H
#define RISCV_SRET_H

#include "../../Instruction.h"
#include "../../../hardware/interrups.h"

namespace instructions {
    class SRET : public Instruction {
    public:
        SRET(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "SRET\n");
        }

        void execute(registers* reg, memory* mem) {
            throw priviledgeReturn();
        }
    };
}

#endif //RISCV_SRET_H
