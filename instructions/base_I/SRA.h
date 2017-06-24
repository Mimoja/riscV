//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_SRA_H
#define RISCV_SRA_H

#include "../Instruction.h"

namespace instructions {
    class SRA : public Instruction {
    public:
        SRA(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "SRA %d, %d, %d", instr.R.rd, instr.R.rs1, instr.R.rs2 & 0x1F);
        }
        void execute(registers* reg, memory* mem) {
            uint32_t regVal = reg->getReg32(instr.R.rs1);
            uint32_t value =  regVal >> (reg->getReg32(instr.R.rs2) & 0x1F);
            if(regVal & BIT(31))value |= 0xFFFFFFFF << (32-(reg->getReg32(instr.R.rs2) & 0x1F));
            reg->setReg32(instr.I.rd, value);
        }
    };

}
#endif //RISCV_SRA_H
