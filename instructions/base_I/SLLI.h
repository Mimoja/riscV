//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_SLLI_H
#define RISCV_SLLI_H

#include "../Instruction.h"

namespace instructions {
    class SLLI : public Instruction {
    public:
        SLLI(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "SLLI %s, %s, %d", registers::getName(instr.I.rd), registers::getName(instr.I.rs1), instr.I.getImm());
        }
        void execute(registers* reg, memory* mem) {
            reg->setReg32(instr.I.rd, reg->getReg32(instr.I.rs1) << (instr.I.getImm() & 0x1F));
        }
    };

}
#endif //RISCV_SLLI_H
