//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_BGE_H
#define RISCV_BGE_H

#include "../Instruction.h"

namespace instructions {
    class BGE : public Instruction {
    public:
        BGE(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "BGE %s, %s, %08X", reg.gp.getRegisterName(instr.B.rs1),
                    reg.gp.getRegisterName(instr.B.rs2), instr.B.getImm());
        }
        void execute(registers* reg, memory* mem) {
            if(((int32_t )reg->gp.getReg32Value(instr.B.rs1)) >= ((int32_t )reg->gp.getReg32Value(instr.B.rs2)))
                reg->setPC32(reg->getPC32() + instr.B.getImm());
        }
    };

}

#endif //RISCV_BGE_H
