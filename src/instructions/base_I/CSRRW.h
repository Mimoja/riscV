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
        CSRRW(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "CSRRW %s<-csr:%d<-%s", reg.gp.getRegisterName(instr.I.rd), instr.I.getImm() & 0xFFF,
                    reg.gp.getRegisterName(instr.I.rs1));
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


#endif //RISCV_CSRWW_H
