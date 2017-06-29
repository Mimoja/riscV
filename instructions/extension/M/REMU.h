//
// Created by Mimoja on 24.06.2017.
//

#ifndef RISCV_REMU_H
#define RISCV_REMU_H

#include "../../Instruction.h"
#include "../../../hardware/registers.h"

namespace instructions {
    class REMU : public Instruction {
    public:
        REMU(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "REMU %s, %s, %s", registers::getRegisterName(instr.R.rd),
                    registers::getRegisterName(instr.R.rs1),
                    registers::getRegisterName(instr.R.rs2));
        }
        void execute(registers* reg, memory* mem) {
            uint32_t val1 = reg->getReg32(instr.R.rs2);
            uint32_t val2 = reg->getReg32(instr.R.rs2);
            if(val2 == 0) reg->setReg32(instr.R.rd, val1);
            else reg->setReg32(instr.R.rd, val1 % val2);
        }
    };

}


#endif //RISCV_REMU_H
