//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_BLTU_H
#define RISCV_BLTU_H

#include "../Instruction.h"

namespace instructions {
    class BLTU : public Instruction {
    public:
        BLTU(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "BLTU %s, %s, %08X", registers::getRegisterName(instr.B.rs1),
                    registers::getRegisterName(instr.B.rs2), instr.B.getImm());
        }
        void execute(registers* reg, memory* mem) {
            if(reg->getReg32(instr.B.rs1) < reg->getReg32(instr.B.rs2))
                reg->setPC32(reg->getPC32()+instr.B.getImm());
        }
    };

}

#endif //RISCV_BLTU_H
