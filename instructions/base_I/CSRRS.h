//
// Created by mimoja on 29.06.17.
//

#ifndef RISCV_CSRRS_H
#define RISCV_CSRRS_H

#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class CSRRS : public Instruction {
    public:
        CSRRS(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "CSRRS %s<-csr:%d<-%s", reg.gp.getRegisterName(instr.I.rd), instr.I.getImm() & 0xFFF,
                    reg.gp.getRegisterName(instr.I.rs1));
        }
        void execute(registers* reg, memory* mem) {

            uint32_t old = reg->csr.getCSR(instr.I.getImm() & 0xFFF);
            reg->gp.setReg32Value(instr.I.rd, old);

            if (instr.I.rs1 != 0) {
                uint32_t mask = reg->gp.getReg32Value(instr.I.rs1);
                for (int i = 0; i < 31; i++) {
                    if(mask & BIT(i))
                        reg->csr.setCSRBit(instr.I.getImm() & 0xFFF, i, true);
                }
            }
        }
    };

}

#endif //RISCV_CSRRS_H
