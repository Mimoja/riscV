//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_ADDI_H
#define RISCV_ADDI_H

#include <netinet/in.h>
#include "Instruction.h"

namespace instructions {
    class ADDI : public Instruction {
    public:
        ADDI(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "ADDI %d, %d, %d", instr.I.rd, instr.I.rs1, instr.I.getImm());
        }
        void execute() {
            Instruction::execute();
            // rd  = rs1 + imm
        }
    };

}
#endif //RISCV_ADDI_H
