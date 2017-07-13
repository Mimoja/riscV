//
// Created by Mimoja on 13.07.2017.
//

#ifndef RISCV_FLW_H
#define RISCV_FLW_H

#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class FLW : public Instruction {
    public:
        FLW(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "FLW %s, %s, %d", registers::getRegisterName(instr.I.rd),
                    registers::getRegisterName(instr.I.rs1), instr.I.getImm());
        }

        void execute(registers* reg, memory* mem) {
            reg->setReg32(instr.I.rd, mem->getWord(reg->getReg32(instr.I.rs1)  + instr.I.getImm()));
        }
    };

}
#endif //RISCV_FLW_H
