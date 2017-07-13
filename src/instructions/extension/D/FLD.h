//
// Created by Mimoja on 13.07.2017.
//

#ifndef RISCV_FLD_H
#define RISCV_FLW_H

#include "../../Instruction.h"

namespace instructions {
    class FLD : public Instruction {
    public:
        FLW(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "FLD %s, %d(%s)", reg.gp.getRegisterName(instr.I.rd), instr.I.getImm(),
                    reg.gp.getRegisterName(instr.I.rs1));
        }
        void execute(registers* reg, memory* mem) {
            uint32_t memval =  mem->getWord(reg->gp.getReg32Value(instr.I.rs1)  + instr.I.getImm());
            double floatval = *((double*) &memval);
            reg->fp.setDoublePrevisionValue(instr.I.rd, floatval);
        }
    };

}
#endif //RISCV_FLD_H
