//
// Created by mimoja on 29.06.17.
//

#ifndef RISCV_CSRWW_H
#define RISCV_CSRWW_H


#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class CSRRW : public Instruction {
    public:
        CSRRW(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "CSRRW %s<-csr:%d<-%s", registers::getName(instr.I.rd), instr.I.getImm(), registers::getName(instr.I.rs1));
        }
        void execute(registers* reg, memory* mem) {
            if (instr.I.rd != 0) {
                uint64_t old = reg->getCSR(instr.I.getImm());
                reg->setReg32(instr.I.rd, old);
            }
            reg->setCSR(instr.I.getImm(), reg->getReg32(instr.I.rs1));
        }
    };

}


#endif //RISCV_CSRWW_H
