//
// Created by mimoja on 22.06.17.
//

#ifndef RISCV_SUB_H
#define RISCV_SUB_H

#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class SUB : public Instruction {
    public:
        SUB(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "SUB %s, %s, %s", reg.gp.getRegisterName(instr.R.rd),
                    reg.gp.getRegisterName(instr.R.rs1),
                    reg.gp.getRegisterName(instr.R.rs2));
        }
        void execute(registers* reg, memory* mem) {
            reg->gp.setReg32Value(instr.R.rd , reg->gp.getReg32Value(instr.R.rs1) - reg->gp.getReg32Value(instr.R.rs2));
        }
    };

}

#endif //RISCV_SUB_H
