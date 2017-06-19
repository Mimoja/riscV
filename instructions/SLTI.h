//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_SLTI_H
#define RISCV_SLTI_H

#include "Instruction.h"

namespace instructions {
    class SLTI : public Instruction {
    public:
        SLTI(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "SLTI %d, %d, %d", instr.I.rd, instr.I.rs1, instr.I.getImm());
        }
        void execute() {
            Instruction::execute();
            // rd  = rs1 < imm
        }
    };

}
#endif //RISCV_SLTI_H
