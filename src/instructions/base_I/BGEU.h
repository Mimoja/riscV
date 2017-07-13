//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_BGEU_H
#define RISCV_BGEU_H

#include "../Instruction.h"

namespace instructions {
    class BGEU : public Instruction {
    public:
        BGEU(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "BGEU %s, %s, %08X", reg.gp.getRegisterName(instr.B.rs1),
                    reg.gp.getRegisterName(instr.B.rs2), instr.B.getImm());
        }
        void execute(registers* reg, memory* mem) {
            if(reg->gp.getReg32Value(instr.B.rs1) >= reg->gp.getReg32Value(instr.B.rs2))
                reg->setPC32(reg->getPC32()+instr.B.getImm());
        }
    };

}

#endif //RISCV_BGEU_H
