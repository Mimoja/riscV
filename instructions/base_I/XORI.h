//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_XORI_H
#define RISCV_XORI_H

#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class XORI : public Instruction {
    public:
        XORI(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "XORI %s, %s, %d", reg.gp.getRegisterName(instr.I.rd),
                    reg.gp.getRegisterName(instr.I.rs1), instr.I.getImm());
        }
        void execute(registers* reg, memory* mem) {
            reg->gp.setReg32Value(instr.I.rd , reg->gp.getReg32Value(instr.I.rs1) ^ instr.I.getImm());
        }
    };

}
#endif //RISCV_XORI_H
