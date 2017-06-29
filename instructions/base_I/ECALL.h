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
        ECALL(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "ECALL %s, %s, %d", registers::getRegisterName(instr.I.rd),
                    registers::getRegisterName(instr.I.rs1), instr.I.getImm());
        }

        void execute(registers *reg, memory *mem) {
            throw "unimplemented";
        }
    };
}

#endif //RISCV_ECALL_H
