//
// Created by mimoja on 21.06.17.
//

#ifndef RISCV_LH_H
#define RISCV_LH_H

#include "../Instruction.h"

namespace instructions {
    class LH : public Instruction {
    public:
        LH(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "LH %s, %d(%s)", reg.gp.getRegisterName(instr.I.rd), instr.I.getImm(),
                    reg.gp.getRegisterName(instr.I.rs1));
        }
        void execute(registers* reg, memory* mem) {
            uint16_t value = mem->getHalfWord(reg->gp.getReg32Value(instr.I.rs1) + instr.I.getImm());
            if(value & BIT(15)) value |= 0xFFFF0000;
            reg->gp.setReg32Value(instr.I.rd, value);
        }
    };

}
#endif //RISCV_LH_H
