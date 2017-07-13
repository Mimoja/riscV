//
// Created by mimoja on 22.06.17.
//

#ifndef RISCV_SLL_H
#define RISCV_SLL_H

#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class SLL : public Instruction {
    public:
        SLL(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "SLL %s, %s, %s", reg.gp.getRegisterName(instr.R.rd),
                    reg.gp.getRegisterName(instr.R.rs1),
                    reg.gp.getRegisterName(instr.R.rs2));
        }
        void execute(registers* reg, memory* mem) {
            reg->gp.setReg32Value(instr.I.rd, reg->gp.getReg32Value(instr.R.rs1) << (reg->gp.getReg32Value(instr.R.rs2) & 0x1F));
        }
    };

}

#endif //RISCV_SLL_H
