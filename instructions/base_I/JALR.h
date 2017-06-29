//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_JALR_H
#define RISCV_JALR_H

#include "../Instruction.h"

namespace instructions {
    class JALR : public Instruction {
    public:
        JALR(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "JALR %s, %08X(%s)", registers::getRegisterName(instr.I.rd), instr.I.getImm(),
                    registers::getRegisterName(instr.I.rs1));
        }
        void execute(registers* reg, memory* mem) {
            reg->setReg32(instr.I.rd, reg->getPC32() + 4);
            reg->setPC32((reg->getReg32(instr.I.rs1) + instr.I.getImm()) & ~BIT(0));
        }
    };

}

#endif //RISCV_JALR_H
