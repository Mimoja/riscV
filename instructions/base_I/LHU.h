//
// Created by mimoja on 22.06.17.
//

#ifndef RISCV_LHU_H
#define RISCV_LHU_H

#include "../Instruction.h"

namespace instructions {
    class LHU : public Instruction {
    public:
        LHU(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "LHU %s, %d(%s)", registers::getName(instr.I.rd), instr.I.getImm(), registers::getName(instr.I.rs1));
        }
        void execute(registers* reg, memory* mem) {
            uint16_t value = mem->getHalfWord(reg->getReg32(instr.I.rs1) + instr.I.getImm());
            reg->setReg32(instr.I.rd, value & 0x0000FFFF);
        }
    };

}
#endif //RISCV_LHU_H
