//
// Created by Mimoja on 24.06.2017.
//

#ifndef RISCV_DIV_H
#define RISCV_DIV_H

#include "../../Instruction.h"
#include "../../../hardware/registers.h"

namespace instructions {
    class DIV : public Instruction {
    public:
        DIV(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "DIV %s, %s, %s", registers::getRegisterName(instr.R.rd),
                    registers::getRegisterName(instr.R.rs1),
                    registers::getRegisterName(instr.R.rs2));
        }
        void execute(registers* reg, memory* mem) {
            int32_t val1 = (int32_t) reg->getReg32(instr.R.rs2);
            int32_t val2 = (int32_t) reg->getReg32(instr.R.rs2);
            if(val2 == 0) reg->setReg32(instr.R.rd, -1);
            else if(val1 == -0x80000000 && val2 == -1)
                reg->setReg32(instr.R.rd, 0x80000000);
            else reg->setReg32(instr.R.rd, val1 / val2);
        }
    };

}
#endif //RISCV_DIV_H
