//
// Created by mimoja on 29.06.17.
//

#ifndef RISCV_CSRRSI_H
#define RISCV_CSRRSI_H

#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class CSRRSI : public Instruction {
    public:
        CSRRSI(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "CSRRSI %s<-csr:%d<-0x%05X", registers::getRegisterName(instr.I.rd), instr.I.getImm() & 0xFFF, instr.I.rs1);
        }
        void execute(registers* reg, memory* mem) {

            uint32_t old = reg->csr.getCSR(instr.I.getImm() & 0xFFF);
            reg->setReg32(instr.I.rd, old);

            if (instr.I.rs1 != 0) {
                uint8_t mask = instr.I.rs1;
                for (int i = 0; i < 4; i++) {
                    if(mask & BIT(i))
                        reg->csr.setCSRBit(instr.I.getImm() & 0xFFF, i, true);
                }
            }
        }
    };

}

#endif //RISCV_CSRRSI_H
