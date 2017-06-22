//
// Created by mimoja on 21.06.17.
//

#ifndef RISCV_LH_H
#define RISCV_LH_H

#include "Instruction.h"

namespace instructions {
    class LH : public Instruction {
    public:
        LH(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "LH %d, %d(%d)", instr.I.rd, instr.I.getImm(), instr.I.rs1);
        }
        void execute(registers* reg, memory* mem) {
            uint16_t value = mem->getHalfWord(reg->getReg32(instr.I.rs1) + instr.I.getImm());
            if(value & BIT(15)) value |= 0xFFFF0000;
            reg->setReg32(instr.I.rd, value);
        }
    };

}
#endif //RISCV_LH_H
