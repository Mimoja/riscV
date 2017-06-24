//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_AUIPC_H
#define RISCV_AUIPC_H

#include "../Instruction.h"

namespace instructions {
    class AUIPC : public Instruction {
    public:
        AUIPC(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "AUIPC %d, %d", instr.U.rd, instr.U.getImm());
        }
        void execute(registers* reg, memory* mem) {
            reg->setReg32(instr.I.rd, reg->getPC32() + instr.I.getImm());
        }
    };

}

#endif //RISCV_AUIPC_H
