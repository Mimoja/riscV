//
// Created by Mimoja on 24.06.2017.
//

#ifndef RISCV_DIV_H
#define RISCV_DIV_H

#include "../../Instruction.h"
#include "../../../hardware/registers.h"

namespace instructions {
    class DIV : public Instruction {
    public:
        DIV(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "DIV %s, %s, %s", reg.gp.getRegisterName(instr.R.rd),
                    reg.gp.getRegisterName(instr.R.rs1),
                    reg.gp.getRegisterName(instr.R.rs2));
        }
        void execute(registers* reg, memory* mem) {
            int32_t val1 = (int32_t) reg->gp.getReg32Value(instr.R.rs2);
            int32_t val2 = (int32_t) reg->gp.getReg32Value(instr.R.rs2);
            if(val2 == 0) reg->gp.setReg32Value(instr.R.rd, -1);
            else if(val1 == -0x80000000 && val2 == -1)
                reg->gp.setReg32Value(instr.R.rd, 0x80000000);
            else reg->gp.setReg32Value(instr.R.rd, val1 / val2);
        }
    };

}
#endif //RISCV_DIV_H
