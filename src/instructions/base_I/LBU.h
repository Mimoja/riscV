//
// Created by mimoja on 22.06.17.
//

#ifndef RISCV_LBU_H
#define RISCV_LBU_H

#include "../Instruction.h"

namespace instructions {
    class LBU : public Instruction {
    public:
        LBU(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "LBU %s, %d(%s)", reg.gp.getRegisterName(instr.I.rd), instr.I.getImm(),
                    reg.gp.getRegisterName(instr.I.rs1));
        }
        void execute(registers* reg, memory* mem) {
            uint8_t value = mem->getByte(reg->gp.getReg32Value(instr.I.rs1) + instr.I.getImm());
            reg->gp.setReg32Value(instr.I.rd, value & 0x000000FF);
        }
    };

}
#endif //RISCV_LBU_H
