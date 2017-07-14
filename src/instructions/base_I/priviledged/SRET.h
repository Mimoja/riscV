//
// Created by Mimoja on 13.07.2017.
//

#ifndef RISCV_SRET_H
#define RISCV_SRET_H

#include "../../Instruction.h"
#include "../../../hardware/traps.h"

namespace instructions {
    class SRET : public Instruction {
    public:
        SRET(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "SRET\n");
        }

        void execute(registers* reg, memory* mem) {
            csr_entry* SPP = reg->csr.regs_by_name.at("SPP");
            csr_entry* SIE = reg->csr.regs_by_name.at("SIE");
            csr_entry* SPIE =reg->csr.regs_by_name.at("SPIE");

            uint8_t  oldMode = SPP->value;

            SIE->value = SPIE->value;
            SPIE->value = 1;
            SPP->value = registers::accesslevel_U;

            reg->current_runlevel = static_cast<registers::accesslevel>(oldMode);

            uint32_t return_value = reg->csr.regs_by_name.at("SEPC")->value;
            reg->setPC32(return_value);
        }
    };
}

#endif //RISCV_SRET_H
