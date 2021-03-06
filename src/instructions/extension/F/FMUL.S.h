//
// Created by Mimoja on 13.07.2017.
//

#ifndef RISCV_FMUL_H
#define RISCV_FMUL_H

#include "../../Instruction.h"

namespace instructions {
    class FMUL : public Instruction {
    public:
        FMUL(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "FMUL.S %s, %s, %s",
                    reg.gp.getRegisterName(instr.R.rd),
                    reg.gp.getRegisterName(instr.R.rs1),
                    reg.gp.getRegisterName(instr.R.rs2));
        }
        void execute(registers* reg, memory* mem) {
            float val1 = reg->fp.getSinglePrecisionValue(instr.R.rs1);
            float val2 = reg->fp.getSinglePrecisionValue(instr.R.rs2);
            reg->fp.setSinglePrecisionValue(instr.R.rd, val1 * val2);
        }
    };
}

#endif //RISCV_FMUL_H
