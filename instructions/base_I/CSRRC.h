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
            sprintf(disas_buffer, "CSRRC %s<-csr:%d<-%s", registers::getRegisterName(instr.I.rd), instr.I.getImm() & 0xFFF,
                    registers::getRegisterName(instr.I.rs1));
        }

        void execute(registers *reg, memory *mem) {

            uint64_t old = reg->csr.getCSR(instr.I.getImm() & 0xFFF);
            reg->setReg32(instr.I.rd, old);

            if (instr.I.rs1 != 0) {
                uint32_t mask = reg->getReg32(instr.I.rs1);
                for (int i = 0; i < 31; i++) {
                    if (!(mask & BIT(i)))
                        reg->csr.setCSRBit(instr.I.getImm() & 0xFFF, i, false);
                }
            }
        }
    };
}

#endif //RISCV_CSRRC_H
