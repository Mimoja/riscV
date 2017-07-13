//
// Created by mimoja on 22.06.17.
//

#ifndef RISCV_SRL_H
#define RISCV_SRL_H

#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class SRL : public Instruction {
    public:
        SRL(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "SRL %s, %s, %s", reg.gp.getRegisterName(instr.R.rd),
                    reg.gp.getRegisterName(instr.R.rs1),
                    reg.gp.getRegisterName(instr.R.rs2));
        }
        void execute(registers* reg, memory* mem) {
            reg->gp.setReg32Value(instr.I.rd, reg->gp.getReg32Value(instr.R.rs1) >> (reg->gp.getReg32Value(instr.R.rs2) & 0x1F));
        }
    };

}

#endif //RISCV_SRL_H
