//
// Created by Mimoja on 13.07.2017.
//

#ifndef RISCV_FSD_H
#define RISCV_FSD_H

#include "../../Instruction.h"

namespace instructions {
    class FSD : public Instruction {
    public:
        FSD(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "FSD %s, %d(%s)", reg.gp.getRegisterName(instr.S.rs2), instr.S.getImm(),
                    reg.gp.getRegisterName(instr.S.rs1));
        }

        void execute(registers* reg, memory* mem) {
            uint32_t targetAddr = reg->gp.getReg32Value(instr.S.rs1)+ instr.S.getImm();
            double value = reg->fp.getDoublePrevisionValue(instr.S.rs2);
            uint32_t intvalue = *((uint32_t*) &value);
            mem->setWord(intvalue,targetAddr);
        }
    };

}

#endif //RISCV_FSD_H
