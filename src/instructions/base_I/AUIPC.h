//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_AUIPC_H
#define RISCV_AUIPC_H

#include "../Instruction.h"

namespace instructions {
    class AUIPC : public Instruction {
    public:
        AUIPC(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg)  {
            sprintf(disas_buffer, "AUIPC %s, %d", reg.gp.getRegisterName(instr.U.rd), instr.U.getImm());
        }
        void execute(registers* reg, memory* mem) {
            reg->gp.setReg32Value(instr.I.rd, reg->getPC32() + instr.I.getImm());
        }
    };

}

#endif //RISCV_AUIPC_H
