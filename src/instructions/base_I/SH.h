//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_SH_H
#define RISCV_SH_H

#include "../Instruction.h"

namespace instructions {
    class SH : public Instruction {
    public:
        SH(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "SH %s, %d(%s)", reg.gp.getRegisterName(instr.S.rs2), instr.S.getImm(),
                    reg.gp.getRegisterName(instr.S.rs1));
        }
        void execute(registers* reg, memory* mem) {
            uint32_t targetAddr = reg->gp.getReg32Value(instr.S.rs1)+ instr.S.getImm();
            mem->setHalfWord(reg->gp.getReg32Value(instr.S.rs2) & 0xFFFF, targetAddr);
        }
    };

}

#endif //RISCV_SH_H
