//
// Created by Mimoja on 24.06.2017.
//

#ifndef RISCV_MUL_H
#define RISCV_MUL_H

#include "../../Instruction.h"
#include "../../../hardware/registers.h"

namespace instructions {
    class MUL : public Instruction {
    public:
        MUL(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "MUL %s, %s, %s", reg.gp.getRegisterName(instr.R.rd),
                    reg.gp.getRegisterName(instr.R.rs1),
                    reg.gp.getRegisterName(instr.R.rs2));
        }
        void execute(registers* reg, memory* mem) {
            int32_t val1 = reg->gp.getReg32Value(instr.R.rs1);
            int32_t val2 = reg->gp.getReg32Value(instr.R.rs2);
            int64_t res = val1 * val2;
            reg->gp.setReg32Value(instr.R.rd,  res);
        }
    };

}
#endif //RISCV_MUL_H

