//
// Created by Mimoja on 24.06.2017.
//

#ifndef RISCV_MULHSU_H
#define RISCV_MULHSU_H

#include "../../Instruction.h"
#include "../../../hardware/registers.h"

namespace instructions {
    class MULHSU : public Instruction {
    public:
        MULHSU(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "MULHSU %s, %s, %s", registers::getRegisterName(instr.R.rd),
                    registers::getRegisterName(instr.R.rs1),
                    registers::getRegisterName(instr.R.rs2));
        }
        void execute(registers* reg, memory* mem) {
            uint64_t val = ((int32_t) reg->getReg32(instr.R.rs1)) * reg->getReg32(instr.R.rs2);
            reg->setReg32(instr.R.rd, val >> 32);
        }
    };

}

#endif //RISCV_MULHSU_H
