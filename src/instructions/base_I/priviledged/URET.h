//
// Created by Mimoja on 13.07.2017.
//

#ifndef RISCV_URET_H
#define RISCV_URET_H

#include "../../Instruction.h"
#include "../../../hardware/traps.h"

namespace instructions {
    class URET : public Instruction {
    public:
        URET(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "URET\n");
        }

        void execute(registers* reg, memory* mem) {
            csr_entry* UPP = reg->csr.regs_by_name.at("UPP");
            csr_entry* UIE = reg->csr.regs_by_name.at("UIE");
            csr_entry* UPIE =reg->csr.regs_by_name.at("UPIE");

            uint8_t  oldMode = UPP->value;

            UIE->value = UPIE->value;
            UPIE->value = 1;
            UPP->value = registers::accesslevel_U;

            reg->current_runlevel = static_cast<registers::accesslevel>(oldMode);

            uint32_t return_value = reg->csr.regs_by_name.at("UEPC")->value;
            reg->setPC32(return_value);
        }
    };
}

#endif //RISCV_URET_H
