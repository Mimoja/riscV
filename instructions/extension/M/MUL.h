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
        MUL(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "MUL %s, %s, %s", registers::getRegisterName(instr.R.rd),
                    registers::getRegisterName(instr.R.rs1),
                    registers::getRegisterName(instr.R.rs2));
        }
        void execute(registers* reg, memory* mem) {
            int32_t val1 = reg->getReg32(instr.R.rs1);
            int32_t val2 = reg->getReg32(instr.R.rs2);
            int64_t res = val1 * val2;
            reg->setReg32(instr.R.rd,  res);
        }
    };

}
#endif //RISCV_MUL_H

