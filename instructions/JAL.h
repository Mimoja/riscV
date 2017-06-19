//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_JAL_H
#define RISCV_JAL_H


#include "Instruction.h"

namespace instructions {
    class JAL : public Instruction {
    public:
        JAL(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "JAL %d, %d", instr.J.rd, instr.J.getImm());
        }
        void execute() {
            Instruction::execute();
            // rd  = pc + 4
            // pc = pc + getImm()
        }
    };

}

#endif //RISCV_JAL_H
