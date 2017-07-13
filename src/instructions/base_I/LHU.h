//
// Created by mimoja on 22.06.17.
//

#ifndef RISCV_LHU_H
#define RISCV_LHU_H

#include "../Instruction.h"

namespace instructions {
    class LHU : public Instruction {
    public:
        LHU(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "LHU %s, %d(%s)", reg.gp.getRegisterName(instr.I.rd), instr.I.getImm(),
                    reg.gp.getRegisterName(instr.I.rs1));
        }
        void execute(registers* reg, memory* mem) {
            uint16_t value = mem->getHalfWord(reg->gp.getReg32Value(instr.I.rs1) + instr.I.getImm());
            reg->gp.setReg32Value(instr.I.rd, value & 0x0000FFFF);
        }
    };

}
#endif //RISCV_LHU_H
