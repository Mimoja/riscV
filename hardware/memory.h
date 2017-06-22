//
// Created by mimoja on 21.06.17.
//

#ifndef RISCV_MEMORY_H
#define RISCV_MEMORY_H

#include <stdint.h>
#include <stdexcept>

class memory
{
public:

    memory(uint64_t bytes) {
        mem = new uint8_t[bytes];
        size = bytes;
    }
    ~memory() {
        delete mem;
    }

    uint64_t getByte(uint64_t address)
    {
        if(address >= size) {
            char buffer[1024];
            sprintf(buffer,"Unallowed memory read at 0x%08lX", address);
            throw std::out_of_range(buffer);
        }
        return mem[address];
    }

    uint64_t getHalfWord(uint64_t address)
    {
        return getByte(address) | (getByte(address+1) << 8);
    }

    uint64_t getWord(uint64_t address)
    {
        return getHalfWord(address) | (getHalfWord(address+2) << 16);
    }
    uint64_t getLongWord(uint64_t address)
    {
        return getWord(address) | (getWord(address+4) << 32);;
    }

    void setByte(uint8_t byte, uint64_t address){
        if(address >= size){
            char buffer[1024];
            sprintf(buffer,"Unallowed memory write at 0x%08lX to 0x%02X", address, byte);
            throw std::out_of_range(buffer);
        }
        mem[address] = byte;
    }

    void setHalfWord(uint16_t hw, uint64_t address){
        setByte(hw & 0xFFFF, address);
        setByte((hw >> 8) & 0xFFFF, address + 1);
    }

    void setWord(uint32_t w, uint64_t address){
        setHalfWord(w & 0xFFFFFFFF, address);
        setHalfWord((w >> 16) & 0xFFFFFFFF, address + 2);
    }

    void setLongWord(uint64_t lw, uint64_t address){
        setWord(lw & 0xFFFFFFFFFFFFFFFF, address);
        setWord((lw >> 32) & 0xFFFFFFFFFFFFFFFF, address + 4);
    }
    void copyToMem(uint8_t * src, uint64_t dest_offset, uint32_t length){
        for (int i = 0; i < length; ++i) {
            setByte(src[i], dest_offset+i);
        }
    }
private:
    uint8_t* mem;
    uint64_t size;
};
#endif //RISCV_MEMORY_H
