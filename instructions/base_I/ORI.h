//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_ORI_H
#define RISCV_ORI_H

#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class ORI : public Instruction {
    public:
        ORI(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "ORI %s, %s, %d", reg.gp.getRegisterName(instr.I.rd),
                    reg.gp.getRegisterName(instr.I.rs1), instr.I.getImm());
        }
        void execute(registers* reg, memory* mem) {
            reg->gp.setReg32Value(instr.I.rd , reg->gp.getReg32Value(instr.I.rs1) | instr.I.getImm());
        }
    };

}
#endif //RISCV_ORI_H
