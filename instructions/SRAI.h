//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_SRAI_H
#define RISCV_SRAI_H

#include "Instruction.h"

namespace instructions {
    class SRAI : public Instruction {
    public:
        SRAI(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "SRAI %d, %d, %d", instr.I.rd, instr.I.rs1, instr.I.getImm()& 0xFFFFF);
        }
        void execute(registers* reg, memory* mem) {
            uint32_t regVal = reg->getReg32(instr.I.rs1);
            uint32_t value =  regVal >> (instr.I.getImm() & 0xFFFFF);
            if(regVal & BIT(31))value |= 0xFFFFFFFF << (32-(instr.I.getImm() & 0xFFFFF));
            reg->setReg32(instr.I.rd, value);
        }
    };

}
#endif //RISCV_SRAI_H
