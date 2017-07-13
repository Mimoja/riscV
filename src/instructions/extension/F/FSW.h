//
// Created by Mimoja on 13.07.2017.
//

#ifndef RISCV_FSW_H
#define RISCV_FSW_H

#include "../../Instruction.h"

namespace instructions {
    class FSW : public Instruction {
    public:
        FSW(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "FSW %s, %d(%s)", reg.gp.getRegisterName(instr.S.rs2), instr.S.getImm(),
                    reg.gp.getRegisterName(instr.S.rs1));
        }

        void execute(registers* reg, memory* mem) {
            uint32_t targetAddr = reg->gp.getReg32Value(instr.S.rs1)+ instr.S.getImm();
            float value = reg->fp.getSinglePrevisionValue(instr.S.rs2);
            uint32_t intvalue = *((uint32_t*) &value);
            mem->setWord(intvalue,targetAddr);
        }
    };

}

#endif //RISCV_FSW_H
