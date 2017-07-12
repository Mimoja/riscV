//
// Created by Mimoja on 24.06.2017.
//

#ifndef RISCV_MULHU_H
#define RISCV_MULHU_H

#include "../../Instruction.h"
#include "../../../hardware/registers.h"

namespace instructions {
    class MULHU : public Instruction {
    public:
        MULHU(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "MULHU %s, %s, %s", reg.gp.getRegisterName(instr.R.rd),
                    reg.gp.getRegisterName(instr.R.rs1),
                    reg.gp.getRegisterName(instr.R.rs2));
        }
        void execute(registers* reg, memory* mem) {
            uint64_t val = reg->gp.getReg32Value(instr.R.rs1) * reg->gp.getReg32Value(instr.R.rs2);
            reg->gp.setReg32Value(instr.R.rd, val >> 32);
        }
    };

}

#endif //RISCV_MULHU_H
