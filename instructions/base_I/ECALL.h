//
// Created by mimoja on 29.06.17.
//

#ifndef RISCV_ECALL_H
#define RISCV_ECALL_H

#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class ECALL : public Instruction {
    public:
        ECALL(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
        sprintf(disas_buffer, "ECALL %s, %s, %d", reg.gp.getRegisterName(instr.I.rd),
                    reg.gp.getRegisterName(instr.I.rs1), instr.I.getImm());
        }

        void execute(registers *reg, memory *mem) {
            throw "unimplemented";
        }
    };
}

#endif //RISCV_ECALL_H
