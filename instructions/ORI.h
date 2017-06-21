//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_ORI_H
#define RISCV_ORI_H

#include <netinet/in.h>
#include "Instruction.h"
#include "../hardware/registers.h"

namespace instructions {
    class ORI : public Instruction {
    public:
        ORI(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "ORI %d, %d, %d", instr.I.rd, instr.I.rs1, instr.I.getImm());
        }
        void execute(registers* reg, memory* mem) {
            reg->setReg32(instr.I.rd , reg->getReg32(instr.I.rs1) | instr.I.getImm());
        }
    };

}
#endif //RISCV_ORI_H
