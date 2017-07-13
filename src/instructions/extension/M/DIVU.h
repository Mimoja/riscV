//
// Created by Mimoja on 24.06.2017.
//

#ifndef RISCV_DIVU_H
#define RISCV_DIVU_H

#include "../../Instruction.h"
#include "../../../hardware/registers.h"

namespace instructions {
    class DIVU : public Instruction {
    public:
        DIVU(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "DIVU %s, %s, %s", reg.gp.getRegisterName(instr.R.rd),
                    reg.gp.getRegisterName(instr.R.rs1),
                    reg.gp.getRegisterName(instr.R.rs2));
        }
        void execute(registers* reg, memory* mem) {
            uint32_t val1 = reg->gp.getReg32Value(instr.R.rs2);
            uint32_t val2 = reg->gp.getReg32Value(instr.R.rs2);
            if (val2 == 0) reg->gp.setReg32Value(instr.R.rd, 0xffffffff);
            else reg->gp.setReg32Value(instr.R.rd, val1 / val2);
        }
    };

}

#endif //RISCV_DIVU_H
