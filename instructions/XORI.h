//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_XORI_H
#define RISCV_XORI_H

#include <netinet/in.h>
#include "Instruction.h"
#include "../hardware/registers.h"

namespace instructions {
    class XORI : public Instruction {
    public:
        XORI(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "XORI %d, %d, %d", instr.I.rd, instr.I.rs1, instr.I.getImm());
        }
        void execute(registers* reg, memory* mem) {
            reg->setReg32(instr.I.rd , reg->getReg32(instr.I.rs1) ^ instr.I.getImm());
        }
    };

}
#endif //RISCV_XORI_H
