//
// Created by mimoja on 22.06.17.
//

#ifndef RISCV_SLTU_H
#define RISCV_SLTU_H

#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class SLTU : public Instruction {
    public:
        SLTU(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "SLTU %s, %s, %s", registers::getRegisterName(instr.R.rd),
                    registers::getRegisterName(instr.R.rs1),
                    registers::getRegisterName(instr.R.rs2));
        }
        void execute(registers* reg, memory* mem) {
            reg->setReg32(instr.R.rd , (reg->getReg32(instr.R.rs1) < reg->getReg32(instr.R.rs2)));
        }
    };

}

#endif //RISCV_SLTU_H
