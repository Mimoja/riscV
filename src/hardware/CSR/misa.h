//
// Created by mimoja on 02.07.17.
//

#ifndef RISCV_MISA_H
#define RISCV_MISA_H


#include "csr_entry.h"

class misa : public csr_entry {
public:
    misa() : csr_entry("misa", 0) {};

    uint32_t read() {
        // Ignore all previous writes
        value = XLEN32;

        value |= extension(A);
        value |= extension(C);
        value |= extension(D);
        value |= extension(F);
        value |= extension(G);
        value |= extension(I);
        value |= extension(M);

        return value;
    }

private:
    const uint32_t XLEN32 = (1 << 30);
    const uint32_t XLEN64 = (2 << 30);
    const uint32_t XLEN128 = (3 << 30);
    enum ext {
        A = 0, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
    };

    uint32_t extension(ext e) { return BIT(e); }

};


#endif //RISCV_MISA_H
