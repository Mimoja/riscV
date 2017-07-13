//
// Created by mimoja on 13.07.17.
//

#ifndef RISCV_MSTATUS_H
#define RISCV_MSTATUS_H


#include "csr_entry.h"

class mstatus : public csr_entry {
public:
    mstatus() : csr_entry("mstatus", 0) {};


    static const SD = (0b01 << 31);
    static const TSR = (0b01 << 22);
    static const TW = (0b01 << 21);
    static const TVM = (0b01 << 20);
    static const MXR = (0b01 << 19);
    static const SUM = (0b01 << 18);
    static const MPRV = (0b01 << 17);
    static const XS = (0b11 << 15);
    static const FS = (0b11 << 13);
    static const MPP = (0b11 << 11);
    static const SPP = (0b01 << 8);
    static const MPIE = (0b01 << 7);
    static const SPIE = (0b01 << 6);
    static const UPIE = (0b01 << 5);
    static const MIE = (0b01 << 4);
    static const SIE = (0b01 << 3);
    static const UIE = (0b01 << 1);
    static const sd = (0b01 << 0);
};


#endif //RISCV_MSTATUS_H
