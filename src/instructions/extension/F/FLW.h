//
// Created by Mimoja on 13.07.2017.
//

#ifndef RISCV_FLW_H
#define RISCV_FLW_H

#include "../../Instruction.h"

namespace instructions {
    class FLW : public Instruction {
    public:
        FLW(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "FLW %s, %d(%s)", reg.gp.getRegisterName(instr.I.rd), instr.I.getImm(),
                    reg.gp.getRegisterName(instr.I.rs1));
        }
        void execute(registers* reg, memory* mem) {
            uint32_t memval =  mem->getWord(reg->gp.getReg32Value(instr.I.rs1)  + instr.I.getImm());
            float floatval = *((float*) &memval);
            reg->fp.setSinglePrecisionValue(instr.I.rd, floatval);
        }
    };

}
#endif //RISCV_FLW_H
