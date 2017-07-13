//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_JAL_H
#define RISCV_JAL_H


#include "../Instruction.h"

namespace instructions {
    class JAL : public Instruction {
    public:
        JAL(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "JAL %s, %d", reg.gp.getRegisterName(instr.J.rd), instr.J.getImm());
        }
        void execute(registers* reg, memory* mem) {
            reg->gp.setReg32Value(instr.J.rd , reg->getPC32() + 4);
            reg->setPC32(reg->getPC32() + instr.J.getImm());
        }
        uint8_t pc_increment(){
            return 0;
        }
    };


}

#endif //RISCV_JAL_H
