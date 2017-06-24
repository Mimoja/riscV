//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_ANDI_H
#define RISCV_ANDI_H

#include <netinet/in.h>
#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class ANDI : public Instruction {
    public:
        ANDI(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "ANDI %s, %s, %d", registers::getName(instr.I.rd), registers::getName(instr.I.rs1), instr.I.getImm());
        }
        void execute(registers* reg, memory* mem) {
            reg->setReg32(instr.I.rd , reg->getReg32(instr.I.rs1) & instr.I.getImm());
        }
    };

}
#endif //RISCV_ANDI_H
