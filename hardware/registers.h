//
// Created by mimoja on 21.06.17.
//

#ifndef RISCV_REGISTER_H
#define RISCV_REGISTER_H

#include <cinttypes>
#include <stdint.h>
#include <stdexcept>
#include <map>

#include "CSR.h"

class registers
{
public:
    csr_registers csr;

    registers():csr(){}

    uint32_t getReg32(uint8_t num){
        if(num >= 32) throw std::out_of_range("Unknown register read");
        if(num == 0) return 0;
        return regs[num] & 0xFFFFFFFF;
    }

    void setReg32(uint8_t num, uint64_t value){
        if(num >= 32) throw std::out_of_range("Unknown register write");
        if(num != 0)  regs[num] = value & 0xFFFFFFFF;
    }

    void setPC32(uint64_t pc){
        progcounter = pc & 0xFFFFFFFF;
    }

    uint32_t getPC32(){
        return progcounter & 0xFFFFFFFF;
    }

    std::string to_string() {
        std::string str;

        for (int i = 0; i+3 < 32; i += 4) {
            char output[1000];
            sprintf(output, "x%02d  %08" PRIX64 " %08" PRIx64 " %08" PRIx64 " %08" PRIx64 "\n", i,
                    regs[i], regs[i+1],
                    regs[i+2], regs[i+3]);
            str.append(output);
        }

        char output[1000];
        sprintf(output, "pc = 0x%08" PRIx64 "\n", progcounter);
        str.append(output);
        return str;
    }

    static const char* getRegisterName(uint8_t reg){
        if(reg>=32)return "null";
        static const char *reg_name[]{
                "zero",
                "ra",
                "sp",
                "gp",
                "tp",
                "t0",
                "t1",
                "t2",
                "s0",
                "s1",
                "a0",
                "a1",
                "a2",
                "a3",
                "a4",
                "a5",
                "a6",
                "a7",
                "s2",
                "s3",
                "s4",
                "s5",
                "s6",
                "s7",
                "s8",
                "s9",
                "s10",
                "s11",
                "t3",
                "t4",
                "t5",
                "t6",
        };
        return reg_name[reg];
    }

private:
    uint64_t regs[32];
    uint64_t progcounter;
};
#endif //RISCV_REGISTER_H
