//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_SW_H
#define RISCV_SW_H

#include "../Instruction.h"

namespace instructions {
    class SW : public Instruction {
    public:
        SW(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "SW %s, %d(%s)", registers::getRegisterName(instr.S.rs2), instr.S.getImm(),
                    registers::getRegisterName(instr.S.rs1));
        }
        void execute(registers* reg, memory* mem) {
            uint32_t targetAddr = reg->getReg32(instr.S.rs1)+ instr.S.getImm();
            mem->setWord(reg->getReg32(instr.S.rs2),targetAddr);
        }
    };

}

#endif //RISCV_SW_H
