//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_ANDI_H
#define RISCV_ANDI_H

#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class ANDI : public Instruction {
    public:
        ANDI(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg)  {
            sprintf(disas_buffer, "ANDI %s, %s, %d", reg.gp.getRegisterName(instr.I.rd),
                    reg.gp.getRegisterName(instr.I.rs1), instr.I.getImm());
        }
        void execute(registers* reg, memory* mem) {
            reg->gp.setReg32Value(instr.I.rd , reg->gp.getReg32Value(instr.I.rs1) & instr.I.getImm());
        }
    };

}
#endif //RISCV_ANDI_H
