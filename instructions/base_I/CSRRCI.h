//
// Created by mimoja on 29.06.17.
//

#ifndef RISCV_CSRRCI_H
#define RISCV_CSRRCI_H

#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class CSRRCI : public Instruction {
    public:
        CSRRCI(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "CSRRCI %s<-csr:%d<-0x%05X", registers::getRegisterName(instr.I.rd), instr.I.getImm(),
                    instr.I.rs1);
        }

        void execute(registers *reg, memory *mem) {

            uint32_t old = reg->getCSR(instr.I.getImm());
            reg->setReg32(instr.I.rd, old);

            if (instr.I.rs1 != 0) {
                uint8_t mask = instr.I.rs1;
                for (int i = 0; i < 4; i++) {
                    if (!(mask & BIT(i)))
                        reg->setCSRBit(instr.I.getImm(), i, false);
                }
            }
        }
    };
}

#endif //RISCV_CSRRCI_H
