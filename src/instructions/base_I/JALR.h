//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_JALR_H
#define RISCV_JALR_H

#include "../Instruction.h"

namespace instructions {
    class JALR : public Instruction {
    public:
        JALR(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "JALR %s, %08X(%s)", reg.gp.getRegisterName(instr.I.rd), instr.I.getImm(),
                    reg.gp.getRegisterName(instr.I.rs1));
        }

        void execute(registers* reg, memory* mem) {
            reg->gp.setReg32Value(instr.I.rd, reg->getPC32() + 4);
            reg->setPC32((reg->gp.getReg32Value(instr.I.rs1) + instr.I.getImm()) & ~BIT(0));
        }

        uint8_t pc_increment(){
            return 0;
        }
    };
}

#endif //RISCV_JALR_H
