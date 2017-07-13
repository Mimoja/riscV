//
// Created by Mimoja on 13.07.2017.
//

#ifndef RISCV_FMIN_D_H
#define RISCV_FMIN_D_H

#include "../../Instruction.h"

namespace instructions {
    class FMIN_D : public Instruction {
    public:
        FMIN_D(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "FMIN.D %s, %s, %s",
                    reg.gp.getRegisterName(instr.R.rd),
                    reg.gp.getRegisterName(instr.R.rs1),
                    reg.gp.getRegisterName(instr.R.rs2));
        }
        void execute(registers* reg, memory* mem) {
            double val1 = reg->fp.getDoublePrevisionValue(instr.R.rs1);
            double val2 = reg->fp.getDoublePrevisionValue(instr.R.rs2);
            reg->fp.setDoublePrevisionValue(instr.R.rd, (val1 < val2)? val1 : val2);
        }
    };
}

#endif //RISCV_FMIN_D_H
