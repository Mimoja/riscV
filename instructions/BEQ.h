//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_BEQ_H
#define RISCV_BEQ_H

#include "Instruction.h"

namespace instructions {
    class BEQ : public Instruction {
    public:
        BEQ(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "BEQ %d, %d %08X", instr.B.rs1, instr.B.rs2, instr.B.getImm());
        }
        void execute(registers* reg, memory* mem) {
            if(reg->getReg32(instr.B.rs1) == reg->getReg32(instr.B.rs2))
                reg->setPC32(reg->getPC32()+instr.B.getImm());
        }
    };

}


#endif //RISCV_BEQ_H
