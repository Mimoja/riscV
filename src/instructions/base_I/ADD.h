//
// Created by mimoja on 22.06.17.
//

#ifndef RISCV_ADD_H
#define RISCV_ADD_H

#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class ADD : public Instruction {
    public:
        ADD(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "ADD %s, %s, %s", reg.gp.getRegisterName(instr.R.rd),
                    reg.gp.getRegisterName(instr.R.rs1),
                    reg.gp.getRegisterName(instr.R.rs2));
        }
        void execute(registers* reg, memory* mem) {
            reg->gp.setReg32Value(instr.R.rd , reg->gp.getReg32Value(instr.R.rs1) + reg->gp.getReg32Value(instr.R.rs2));
        }
    };

}

#endif //RISCV_ADD_H
