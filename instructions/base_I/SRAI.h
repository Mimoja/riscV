//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_SRAI_H
#define RISCV_SRAI_H

#include "../Instruction.h"

namespace instructions {
    class SRAI : public Instruction {
    public:
        SRAI(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg)  {
            sprintf(disas_buffer, "SRAI %s, %s, %d", reg.gp.getRegisterName(instr.I.rd),
                    reg.gp.getRegisterName(instr.I.rs1), instr.I.getImm() & 0x1F);
        }
        void execute(registers* reg, memory* mem) {
            uint32_t regVal = reg->gp.getReg32Value(instr.I.rs1);
            uint32_t value =  regVal >> (instr.I.getImm() & 0x1F);
            if(regVal & BIT(31))value |= 0xFFFFFFFF << (32-(instr.I.getImm() & 0x1F));
            reg->gp.setReg32Value(instr.I.rd, value);
        }
    };

}
#endif //RISCV_SRAI_H
