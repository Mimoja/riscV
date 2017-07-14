//
// Created by Mimoja on 14.07.2017.
//

#ifndef RISCV_WFI_H
#define RISCV_WFI_H

#include "../../Instruction.h"
#include "../../../hardware/traps.h"

namespace instructions {
    class WFI : public Instruction {
    public:
        WFI(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "WFI\n");
        }

        void execute(registers *reg, memory *mem) {
            // implemented as NOP
        };
    };
}


#endif //RISCV_WFI_H
