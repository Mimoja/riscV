//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_LUI_H
#define RISCV_LUI_H

#include "Instruction.h"

namespace instructions {
    class LUI : public Instruction {
    public:
        LUI(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "LUI %d, %d", instr.U.rd, instr.U.getImm());
        }
        void execute(registers* reg, memory* mem) {
            reg->setReg32(instr.U.rd, instr.U.getImm());
        }
    };

}
#endif //RISCV_LUI_H
