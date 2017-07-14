//
// Created by Mimoja on 14.07.2017.
//

#ifndef RISCV_MTVEC_H
#define RISCV_MTVEC_H

#include "csr_entry.h"
#include "../traps.h"

class mtvec : public csr_entry {
public:
    mtvec() : csr_entry("mtvec", 0) {};

    uint64_t getJumpAddress(uint32_t cause) {
        switch (value & MODE) {
            case MODE_DIRECT:
                return getBaseAddress();
            case MODE_VECTORED:
                return getBaseAddress() + 4 * cause;
            default:
                throw invalidInstruction();
        }
    }

    static const uint32_t BASE = (0xFFFFFFFF << 2);
    static const uint32_t MODE = (0b11 << 0);

    enum {
        MODE_DIRECT = 0,
        MODE_VECTORED = 1,
        MODE_RESERVED1 = 2,
        MODE_RESERVED2 = 3,
        MODE_RESERVED3 = 4,
    };
private:

    uint64_t getBaseAddress(){
        return ((value & BASE) << 2);
    }

};

#endif //RISCV_MTVEC_H
