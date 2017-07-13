//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_SLLI_H
#define RISCV_SLLI_H

#include "../Instruction.h"

namespace instructions {
    class SLLI : public Instruction {
    public:
        SLLI(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
        sprintf(disas_buffer, "SLLI %s, %s, %d", reg.gp.getRegisterName(instr.I.rd),
                    reg.gp.getRegisterName(instr.I.rs1), instr.I.getImm());
        }
        void execute(registers* reg, memory* mem) {
            reg->gp.setReg32Value(instr.I.rd, reg->gp.getReg32Value(instr.I.rs1) << (instr.I.getImm() & 0x1F));
        }
    };

}
#endif //RISCV_SLLI_H
