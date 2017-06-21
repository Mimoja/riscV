//
// Created by mimoja on 22.06.17.
//

#ifndef RISCV_LBU_H
#define RISCV_LBU_H

#include "Instruction.h"

namespace instructions {
    class LBU : public Instruction {
    public:
        LBU(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "LBU %d, %d(%d)", instr.I.rd, instr.I.getImm(), instr.I.rs1);
        }
        void execute(registers* reg, memory* mem) {
            uint8_t value = mem->getByte(reg->getReg32(instr.I.rs1) + instr.I.getImm());
            reg->setReg32(instr.I.rd, value & 0x000000FF);
        }
    };

}
#endif //RISCV_LBU_H
