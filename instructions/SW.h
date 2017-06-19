//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_SW_H
#define RISCV_SW_H

#include "Instruction.h"

namespace instructions {
    class SW : public Instruction {
    public:
        SW(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "SW %d, %d(%d)", instr.S.rs2, instr.S.getImm(), instr.S.rs1);
        }
        void execute() {
            Instruction::execute();
            //  * (rs1 + getImm()) = rs2
        }
    };

}

#endif //RISCV_SW_H
