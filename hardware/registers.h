//
// Created by mimoja on 21.06.17.
//

#ifndef RISCV_REGISTER_H
#define RISCV_REGISTER_H

#include <cinttypes>
#include <stdint.h>
#include <stdexcept>
#include <map>

class registers
{
public:
    uint64_t getCSR(uint32_t index){
        return csr[index];
    }

    void setCSR(uint32_t index, uint32_t value){
        csr[index] = value;
    }

    void setCSRBit(uint32_t index, uint32_t bit, bool set){
        if(set)
            csr[index] |= BIT(bit);
        else
            csr[index] &= !BIT(bit);
    }

    uint32_t getReg32(uint8_t num){
        if(num >= 32) throw std::out_of_range("Unknown register read");
        if(num == 0) return 0;
        return registers[num] & 0xFFFFFFFF;
    }

    void setReg32(uint8_t num, uint64_t value){
        if(num >= 32) throw std::out_of_range("Unknown register write");
        if(num != 0)  registers[num] = value & 0xFFFFFFFF;
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
                    registers[i], registers[i+1],
                    registers[i+2], registers[i+3]);
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
uint64_t registers[32];
    uint64_t progcounter;
    std::map<uint16_t, uint32_t> csr ={
            //User Trap Setup
            {0x000,0},
            {0x004,0},
            {0x005,0},
            //User Trap Handling
            {0x040,0},
            {0x041,0},
            {0x042,0},
            {0x043,0},
            {0x044,0},
            //User floating point CSRs
            {0x001,0},
            {0x002,0},
            {0x003,0},
            //User Counter/Timers
            {0xC00,0},
            {0xC01,0},
            {0xC02,0},
            {0xC03,0},
            {0xC04,0},
            {0xC06,0},
            {0xC07,0},
            {0xC08,0},
            {0xC09,0},
            {0xC10,0},
            {0xC11,0},
            {0xC12,0},
            {0xC13,0},
            {0xC14,0},
            {0xC15,0},
            {0xC16,0},
            {0xC17,0},
            {0xC18,0},
            {0xC19,0},
            {0xC1A,0},
            {0xC1B,0},
            {0xC1C,0},
            {0xC1D,0},
            {0xC1E,0},
            {0xC1F,0},
            {0xC80,0},
            {0xC81,0},
            {0xC82,0},
            {0xC83,0},
            {0xC84,0},
            {0xC85,0},
            {0xC86,0},
            {0xC87,0},
            {0xC88,0},
            {0xC89,0},
            {0xC8A,0},
            {0xC8B,0},
            {0xC8C,0},
            {0xC8D,0},
            {0xC8E,0},
            {0xC8F,0},
            {0xC90,0},
            {0xC91,0},
            {0xC92,0},
            {0xC93,0},
            {0xC94,0},
            {0xC95,0},
            {0xC96,0},
            {0xC97,0},
            {0xC98,0},
            {0xC99,0},
            {0xC9A,0},
            {0xC9B,0},
            {0xC9C,0},
            {0xC9D,0},
            {0xC9E,0},
            {0xC9F,0},
            //Supervisor Trap Setup
            {0x100,0},
            {0x102,0},
            {0x103,0},
            {0x104,0},
            {0x105,0},
            {0x106,0},
            //Supervisor Trap Handling
            {0x140,0},
            {0x141,0},
            {0x142,0},
            {0x143,0},
            {0x144,0},
            //Supervisor Protection and Translation
            {0x180,0},
            //Machine Information Registers
            {0xF11,0},
            {0xF12,0},
            {0xF13,0},
            {0xF14,0},
            //Machine Trap Setup
            {0x300,0},
            {0x301,0},
            {0x302,0},
            {0x303,0},
            {0x304,0},
            {0x305,0},
            {0x306,0},
            //Machine Trap Handling
            {0x340,0},
            {0x341,0},
            {0x342,0},
            {0x343,0},
            {0x344,0},
            //Machine Protection and Translation
            {0x3A0,0},
            {0x3A1,0},
            {0x3A2,0},
            {0x3A3,0},
            {0x3B0,0},
            {0x3B1,0},
            {0x3B2,0},
            {0x3B3,0},
            {0x3B4,0},
            {0x3B5,0},
            {0x3B6,0},
            {0x3B7,0},
            {0x3B8,0},
            {0x3B9,0},
            {0x3BA,0},
            {0x3BB,0},
            {0x3BC,0},
            {0x3BD,0},
            {0x3BE,0},
            {0x3BF,0},
            //Machine Counter/Timers
            {0xB00,0},
            {0xB02,0},
            {0xB03,0},
            {0xB04,0},
            {0xB05,0},
            {0xB06,0},
            {0xB07,0},
            {0xB08,0},
            {0xB09,0},
            {0xB0A,0},
            {0xB0B,0},
            {0xB0C,0},
            {0xB0D,0},
            {0xB0E,0},
            {0xB0F,0},
            {0xB10,0},
            {0xB11,0},
            {0xB12,0},
            {0xB13,0},
            {0xB14,0},
            {0xB15,0},
            {0xB16,0},
            {0xB17,0},
            {0xB18,0},
            {0xB19,0},
            {0xB1A,0},
            {0xB1B,0},
            {0xB1C,0},
            {0xB1D,0},
            {0xB1E,0},
            {0xB1F,0},
            {0xB80,0},
            {0xB82,0},
            {0xB83,0},
            {0xB84,0},
            {0xB85,0},
            {0xB86,0},
            {0xB87,0},
            {0xB88,0},
            {0xB89,0},
            {0xB8A,0},
            {0xB8B,0},
            {0xB8C,0},
            {0xB8D,0},
            {0xB8E,0},
            {0xB8F,0},
            {0xB90,0},
            {0xB91,0},
            {0xB92,0},
            {0xB93,0},
            {0xB94,0},
            {0xB95,0},
            {0xB96,0},
            {0xB97,0},
            {0xB98,0},
            {0xB99,0},
            {0xB9A,0},
            {0xB9B,0},
            {0xB9C,0},
            {0xB9D,0},
            {0xB9E,0},
            {0xB9F,0},
            //Machine Counter Setup
            {0x323,0},
            {0x324,0},
            {0x325,0},
            {0x326,0},
            {0x327,0},
            {0x328,0},
            {0x329,0},
            {0x32A,0},
            {0x32B,0},
            {0x32C,0},
            {0x32D,0},
            {0x32E,0},
            {0x32F,0},
            {0x330,0},
            {0x331,0},
            {0x332,0},
            {0x333,0},
            {0x334,0},
            {0x335,0},
            {0x336,0},
            {0x337,0},
            {0x338,0},
            {0x339,0},
            {0x33A,0},
            {0x33B,0},
            {0x33C,0},
            {0x33D,0},
            {0x33E,0},
            {0x33F,0},
            //Debug/Trace Registers
            {0x7A0,0},
            {0x7A1,0},
            {0x7A2,0},
            {0x7A3,0},
            //Debug Mode Registers
            {0x7B0,0},
            {0x7B1,0},
            {0x7B2,0},
    };
};
#endif //RISCV_REGISTER_H
