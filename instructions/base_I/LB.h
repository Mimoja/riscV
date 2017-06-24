//
// Created by mimoja on 22.06.17.
//

#ifndef RISCV_LB_H
#define RISCV_LB_H

#include "../Instruction.h"

namespace instructions {
    class LB : public Instruction {
    public:
        LB(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "LB %s, %d(%s)", registers::getName(instr.I.rd), instr.I.getImm(), registers::getName(instr.I.rs1));
        }
        void execute(registers* reg, memory* mem) {
            uint8_t value = mem->getByte(reg->getReg32(instr.I.rs1) + instr.I.getImm());
            if(value & BIT(7)) value |= 0xFFFFFF00;
            reg->setReg32(instr.I.rd, value);
        }
    };

}
#endif //RISCV_LB_H
