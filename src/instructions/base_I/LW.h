//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_LW_H
#define RISCV_LW_H

#include "../Instruction.h"

namespace instructions {
    class LW : public Instruction {
    public:
        LW(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "LW %s, %d(%s)", reg.gp.getRegisterName(instr.I.rd), instr.I.getImm(),
                    reg.gp.getRegisterName(instr.I.rs1));
        }
        void execute(registers* reg, memory* mem) {
            reg->gp.setReg32Value(instr.I.rd, mem->getWord(reg->gp.getReg32Value(instr.I.rs1)  + instr.I.getImm()));
        }
    };

}
#endif //RISCV_LW_H
