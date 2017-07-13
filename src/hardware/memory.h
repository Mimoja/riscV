//
// Created by mimoja on 21.06.17.
//

#ifndef RISCV_MEMORY_H
#define RISCV_MEMORY_H

#include <stdint.h>
#include <stdexcept>
#include <string.h>

class memory
{
public:

    memory(uint64_t bytes) {
        mem = new uint8_t[bytes];
        memset(mem, 0, bytes);
        size = bytes;
    }

    ~memory() {
        delete mem;
    }

    uint64_t getByte(uint64_t address)
    {
        if(address >= size) {
            char buffer[1024];
            sprintf(buffer,"Unallowed memory read at 0x%08" PRIx64 "\n", address);
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

    void setByte(uint64_t address, uint8_t byte) {
        if(address >= size){
            char buffer[1024];
            sprintf(buffer,"Unallowed memory write at 0x%08" PRIx64 " to 0x%02X", address, byte);
            throw std::out_of_range(buffer);
        }
        mem[address] = byte;
    }

    void setHalfWord(uint64_t address, uint16_t hw) {
        setByte(address, hw & 0xFFFF);
        setByte(address + 1, (hw >> 8) & 0xFFFF);
    }

    void setWord(uint64_t address, uint32_t w) {
        setHalfWord(address, w & 0xFFFFFFFF);
        setHalfWord(address + 2, (w >> 16) & 0xFFFFFFFF);
    }

    void setLongWord(uint64_t address, uint64_t lw) {
        setWord(address, lw & 0xFFFFFFFFFFFFFFFF);
        setWord(address + 4, (lw >> 32) & 0xFFFFFFFFFFFFFFFF);
    }
    void copyToMem(uint8_t * src, uint64_t dest_offset, uint64_t length){
        for (int i = 0; i < length; ++i) {
            setByte(dest_offset + i, src[i]);
        }
    }

    uint64_t getSize(){
        return size;
    }
private:
    uint8_t* mem;
    uint64_t size;
};
#endif //RISCV_MEMORY_H
