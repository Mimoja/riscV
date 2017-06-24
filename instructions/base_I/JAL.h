//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_JAL_H
#define RISCV_JAL_H


#include "../Instruction.h"

namespace instructions {
    class JAL : public Instruction {
    public:
        JAL(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "JAL %s, %d", registers::getName(instr.J.rd), instr.J.getImm());
        }
        void execute(registers* reg, memory* mem) {
            reg->setReg32(instr.J.rd , reg->getPC32() + 4);
            reg->setPC32(reg->getPC32() + instr.J.getImm());
        }
    };

}

#endif //RISCV_JAL_H
