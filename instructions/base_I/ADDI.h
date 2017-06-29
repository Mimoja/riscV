//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_ADDI_H
#define RISCV_ADDI_H


#include "../Instruction.h"
#include "../../hardware/registers.h"

namespace instructions {
    class ADDI : public Instruction {
    public:
        ADDI(const decode::instruction_type &decoded) : Instruction(decoded) {
            sprintf(disas_buffer, "ADDI %s, %s, %d", registers::getRegisterName(instr.I.rd),
                    registers::getRegisterName(instr.I.rs1), instr.I.getImm());
        }
        void execute(registers* reg, memory* mem) {
            reg->setReg32(instr.I.rd , reg->getReg32(instr.I.rs1) + instr.I.getImm());
        }
    };

}
#endif //RISCV_ADDI_H
