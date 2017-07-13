//
// Created by mimoja on 29.06.17.
//

#ifndef RISCV_CSRWWI_H
#define RISCV_CSRWWI_H


#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class CSRRWI : public Instruction {
    public:
        CSRRWI(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "CSRRWI %s<-csr:%d<-0x%05X", reg.gp.getRegisterName(instr.I.rd), instr.I.getImm() & 0xFFF, instr.I.rs1);
        }
        void execute(registers* reg, memory* mem) {
            if (instr.I.rd != 0) {
                uint64_t old = reg->csr.getCSR(instr.I.getImm() & 0xFFF);
                reg->gp.setReg32Value(instr.I.rd, old);
            }
            reg->csr.setCSR(instr.I.getImm() & 0xFFF, reg->gp.getReg32Value(instr.I.rs1));
        }
    };
}


#endif //RISCV_CSRWWI_H
