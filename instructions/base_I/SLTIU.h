//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_SLTIU_H
#define RISCV_SLTIU_H

#include "../Instruction.h"

namespace instructions {
    class SLTIU : public Instruction {
    public:
        SLTIU(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "SLTIU %d, %d, %d", instr.I.rd, instr.I.rs1, instr.I.getImm());
        }
        void execute(registers* reg, memory* mem) {
            reg->setReg32(instr.I.rd, reg->getReg32(instr.I.rs1) < instr.I.getImm());
        }
    };

}
#endif //RISCV_SLTIU_H
