//
// Created by Mimoja on 14.07.2017.
//

#ifndef RISCV_MCAUSE_H
#define RISCV_MCAUSE_H

#include "csr_entry.h"
#include "../traps.h"

class mcause : public csr_entry {
public:
    mcause() : csr_entry("mcause", 0) {};

    void set_cause(trap cause){

        value = (cause.cause & CAUSE);

        if(cause.is_interrupt)
            value |= INTERRUPT;
        else
            value &= ~INTERRUPT;
    }

    static const uint32_t CAUSE = (0xEFFFFFFF << 0);
    static const uint32_t INTERRUPT = (1 << 31);
};
#endif //RISCV_MCAUSE_H
