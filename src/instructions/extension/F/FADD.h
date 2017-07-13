//
// Created by Mimoja on 13.07.2017.
//

#ifndef RISCV_FADD_H
#define RISCV_FADD_H

#include "../../Instruction.h"

namespace instructions {
    class FADD : public Instruction {
    public:
        FADD(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "FADD %s, %s, %s", reg.gp.getRegisterName(instr.R.rd),
                    reg.gp.getRegisterName(instr.R.rs1),
                    reg.gp.getRegisterName(instr.R.rs2));
        }
        void execute(registers* reg, memory* mem) {
            float val1 = reg->fp.getSinglePrevisionValue(instr.R.rs1);
            float val2 = reg->fp.getSinglePrevisionValue(instr.R.rs2);
            reg->fp.setSinglePrevisionValue(instr.R.rd, val1 + val2);
        }
    };
}

#endif //RISCV_FADD_H