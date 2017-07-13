//
// Created by mimoja on 13.07.17.
//

#ifndef RISCV_MSTATUS_H
#define RISCV_MSTATUS_H

#include "csr_entry.h"
#include "csr_ids.h"

class msu_status : public csr_entry {
public:
    msu_status() : csr_entry("status", 0) {};

    virtual const char* get_name(uint16_t id){
        switch(id){
            case MSTATUS_ID:
                return "mstatus";
            case SSTATUS_ID:
                return "sstatus";
            case USTATUS_ID:
                return "ustatus";
        }
        return "status";
    }

    virtual uint32_t read(uint16_t id){
        switch(id){
            case MSTATUS_ID:
                return value & M_MASK;
            case SSTATUS_ID:
                return value & S_MASK;
            case USTATUS_ID:
                return value & U_MASK;
        }
        return value;
    };

    virtual void write(uint16_t id, uint32_t val) {
        switch(id){
            case MSTATUS_ID:
                val &= M_MASK;
            case SSTATUS_ID:
                val &= S_MASK;
            case USTATUS_ID:
                val &= U_MASK;
        }
        value = val;
    };

    static const uint32_t SD = (0b01 << 31);
    static const uint32_t TSR = (0b01 << 22);
    static const uint32_t TW = (0b01 << 21);
    static const uint32_t TVM = (0b01 << 20);
    static const uint32_t MXR = (0b01 << 19);
    static const uint32_t SUM = (0b01 << 18);
    static const uint32_t MPRV = (0b01 << 17);
    static const uint32_t XS = (0b11 << 15);
    static const uint32_t FS = (0b11 << 13);
    static const uint32_t MPP = (0b11 << 11);
    static const uint32_t SPP = (0b01 << 8);
    static const uint32_t MPIE = (0b01 << 7);
    static const uint32_t SPIE = (0b01 << 5);
    static const uint32_t UPIE = (0b01 << 4);
    static const uint32_t MIE = (0b01 << 3);
    static const uint32_t SIE = (0b01 << 1);
    static const uint32_t UIE = (0b01 << 0);

    static const uint32_t M_MASK = SD|TSR|TW|TVM|MXR|SUM|MPRV|XS|FS|MPP|SPP|MPIE|SPIE|UPIE|MIE|SIE|UIE;
    static const uint32_t S_MASK = SD|MXR|SUM|XS|FS|SPP|SPIE|UPIE|SIE|UIE;
    static const uint32_t U_MASK = UPIE|UIE;
};


#endif //RISCV_MSTATUS_H
