//
// Created by Mimoja on 13.07.2017.
//

#ifndef RISCV_MRET_H
#define RISCV_MRET_H

#include "../../Instruction.h"
#include "../../../hardware/traps.h"

namespace instructions {
    class MRET : public Instruction {
    public:
        MRET(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "MRET\n");
        }

        void execute(registers* reg, memory* mem) {
            csr_entry* MPP = reg->csr.regs_by_name.at("MPP");
            csr_entry* MIE = reg->csr.regs_by_name.at("MIE");
            csr_entry* MPIE =reg->csr.regs_by_name.at("MPIE");

            uint8_t  oldMode = MPP->value;

            MIE->value = MPIE->value;
            MPIE->value = 1;
            MPP->value = registers::accesslevel_U;

            reg->current_runlevel = static_cast<registers::accesslevel>(oldMode);

            uint32_t return_value = reg->csr.regs_by_name.at("MEPC")->value;
            reg->setPC32(return_value);

        }
    };
}

#endif //RISCV_MRET_H
