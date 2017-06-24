//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_SRLI_H
#define RISCV_SRLI_H

#include "../Instruction.h"

namespace instructions {
    class SRLI : public Instruction {
    public:
        SRLI(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "SRLI %s, %s, %d", registers::getName(instr.I.rd), registers::getName(instr.I.rs1), instr.I.getImm());
        }
        void execute(registers* reg, memory* mem) {
            reg->setReg32(instr.I.rd, reg->getReg32(instr.I.rs1) >> (instr.I.getImm() & 0x1F) );
        }
    };

}
#endif //RISCV_SRLI_H
