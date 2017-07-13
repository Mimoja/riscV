//
// Created by mimoja on 22.06.17.
//

#ifndef RISCV_LB_H
#define RISCV_LB_H

#include "../Instruction.h"

namespace instructions {
    class LB : public Instruction {
    public:
        LB(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "LB %s, %d(%s)", reg.gp.getRegisterName(instr.I.rd), instr.I.getImm(),
                    reg.gp.getRegisterName(instr.I.rs1));
        }
        void execute(registers* reg, memory* mem) {
            uint8_t value = mem->getByte(reg->gp.getReg32Value(instr.I.rs1) + instr.I.getImm());
            if(value & BIT(7)) value |= 0xFFFFFF00;
            reg->gp.setReg32Value(instr.I.rd, value);
        }
    };

}
#endif //RISCV_LB_H
