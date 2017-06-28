//
// Created by mimoja on 29.06.17.
//

#ifndef RISCV_CSRRC_H
#define RISCV_CSRRC_H

#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class CSRRC : public Instruction {
    public:
        CSRRC(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "CSRRC %s<-csr:%d<-%s", registers::getName(instr.I.rd), instr.I.getImm(),
                    registers::getName(instr.I.rs1));
        }

        void execute(registers *reg, memory *mem) {

            uint32_t old = reg->getCSR(instr.I.getImm());
            reg->setReg32(instr.I.rd, old);

            if (instr.I.rs1 != 0) {
                uint32_t mask = reg->getReg32(instr.I.rs1);
                for (int i = 0; i < 31; i++) {
                    if (!(mask & BIT(i)))
                        reg->setCSRBit(instr.I.getImm(), i, false);
                }
            }
        }
    };
}

#endif //RISCV_CSRRC_H
