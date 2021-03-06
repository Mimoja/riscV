//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_BNE_H
#define RISCV_BNE_H

#include "../Instruction.h"

namespace instructions {
    class BNE : public Instruction {
    public:
        BNE(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "BNE %s, %s, %08X", reg.gp.getRegisterName(instr.B.rs1),
                    reg.gp.getRegisterName(instr.B.rs2), instr.B.getImm());
        }
        void execute(registers* reg, memory* mem) {
            if(reg->gp.getReg32Value(instr.B.rs1) != reg->gp.getReg32Value(instr.B.rs2))
                reg->setPC32(reg->getPC32()+instr.B.getImm());
        }
    };

}

#endif //RISCV_BNE_H
