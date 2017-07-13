//
// Created by Mimoja on 13.07.2017.
//

#ifndef RISCV_URET_H
#define RISCV_URET_H

#include "../Instruction.h"
#include "../../hardware/interrups.h"

namespace instructions {
    class URET : public Instruction {
    public:
        URET(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "URET\n");
        }

        void execute(registers* reg, memory* mem) {
            throw priviledgeReturn();
        }
    };
}

#endif //RISCV_URET_H
