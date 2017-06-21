//
// Created by mimoja on 21.06.17.
//

#ifndef RISCV_REGISTER_H
#define RISCV_REGISTER_H

#include <stdint.h>
#include <stdexcept>

class registers
{
public:
    uint32_t getReg32(uint8_t num){
        if(num >= 32) throw std::out_of_range("Unknown register read");
        if(num == 0) return 0;
        return registers[num] & 0xFFFFFFFF;
    }

    void setReg32(uint8_t num, uint32_t value){
        if(num >= 32) throw std::out_of_range("Unknown register write");
        if(num != 0)  registers[num] = value & 0xFFFFFFFF;
    }

    void setPC32(uint32_t pc){
        progcounter = pc & 0xFFFFFFFF;
    }

    uint32_t getPC32(){
        return progcounter & 0xFFFFFFFF;
    }

    std::string to_string() {
        std::string str;

        for (int i = 0; i < 32; i++) {
            char output[1000];
            sprintf(output, "registers[%d] = 0x%08lX\n", i, registers[i]);
            str.append(output);
        }
        char output[1000];
        sprintf(output, "pc = 0x%08lX\n", progcounter);
        str.append(output);
        return str;
    }

private:
uint64_t registers[32];
uint64_t progcounter;
};
#endif //RISCV_REGISTER_H
