//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_SB_H
#define RISCV_SB_H

#include "../Instruction.h"

namespace instructions {
    class SB : public Instruction {
    public:
        SB(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "SB %s, %d(%s)", reg.gp.getRegisterName(instr.S.rs2), instr.S.getImm(),
                    reg.gp.getRegisterName(instr.S.rs1));
        }
        void execute(registers* reg, memory* mem) {
            uint32_t targetAddr = reg->gp.getReg32Value(instr.S.rs1)+ instr.S.getImm();
            mem->setByte(reg->gp.getReg32Value(instr.S.rs2) & 0xFF, targetAddr);
        }
    };

}

#endif //RISCV_SB_H
