//
// Created by Mimoja on 02.07.2017.
//

#ifndef RISCV_CSR_H
#define RISCV_CSR_H

class CSR{
public:
    uint64_t getCSR(uint32_t index){
        uint32_t val = csr[index].value;
        if(csr[index].read != NULL){
            csr[index].read();
        }
        return val;
    }

    void setCSR(uint32_t index, uint32_t value){
        csr[index].value = value;
        if(csr[index].write != NULL){
            csr[index].write();
        }
    }

    void setCSRBit(uint32_t index, uint32_t bit, bool set){
        if(set)
            csr[index].value |= BIT(bit);
        else
            csr[index].value &= !BIT(bit);

        if(csr[index].write != NULL){
            csr[index].write();
        }
    }

    typedef struct {
        uint32_t value;
        void (*read)(void);
        void (*write)(void);
    }csr_register;

    // allow direct access for sideeffect free handling
    std::map<uint16_t, csr_register> csr ={
            //User Trap Setup
            {0x000, {0, NULL, NULL}},
            {0x004, {0, NULL, NULL}},
            {0x005, {0, NULL, NULL}},
            //User Trap Handling
            {0x040, {0, NULL, NULL}},
            {0x041, {0, NULL, NULL}},
            {0x042, {0, NULL, NULL}},
            {0x043, {0, NULL, NULL}},
            {0x044, {0, NULL, NULL}},
            //User floating point CSRs
            {0x001, {0, NULL, NULL}},
            {0x002, {0, NULL, NULL}},
            {0x003, {0, NULL, NULL}},
            //User Counter/Timers
            {0xC00, {0, NULL, NULL}},
            {0xC01, {0, NULL, NULL}},
            {0xC02, {0, NULL, NULL}},
            {0xC03, {0, NULL, NULL}},
            {0xC04, {0, NULL, NULL}},
            {0xC06, {0, NULL, NULL}},
            {0xC07, {0, NULL, NULL}},
            {0xC08, {0, NULL, NULL}},
            {0xC09, {0, NULL, NULL}},
            {0xC10, {0, NULL, NULL}},
            {0xC11, {0, NULL, NULL}},
            {0xC12, {0, NULL, NULL}},
            {0xC13, {0, NULL, NULL}},
            {0xC14, {0, NULL, NULL}},
            {0xC15, {0, NULL, NULL}},
            {0xC16, {0, NULL, NULL}},
            {0xC17, {0, NULL, NULL}},
            {0xC18, {0, NULL, NULL}},
            {0xC19, {0, NULL, NULL}},
            {0xC1A, {0, NULL, NULL}},
            {0xC1B, {0, NULL, NULL}},
            {0xC1C, {0, NULL, NULL}},
            {0xC1D, {0, NULL, NULL}},
            {0xC1E, {0, NULL, NULL}},
            {0xC1F, {0, NULL, NULL}},
            {0xC80, {0, NULL, NULL}},
            {0xC81, {0, NULL, NULL}},
            {0xC82, {0, NULL, NULL}},
            {0xC83, {0, NULL, NULL}},
            {0xC84, {0, NULL, NULL}},
            {0xC85, {0, NULL, NULL}},
            {0xC86, {0, NULL, NULL}},
            {0xC87, {0, NULL, NULL}},
            {0xC88, {0, NULL, NULL}},
            {0xC89, {0, NULL, NULL}},
            {0xC8A, {0, NULL, NULL}},
            {0xC8B, {0, NULL, NULL}},
            {0xC8C, {0, NULL, NULL}},
            {0xC8D, {0, NULL, NULL}},
            {0xC8E, {0, NULL, NULL}},
            {0xC8F, {0, NULL, NULL}},
            {0xC90, {0, NULL, NULL}},
            {0xC91, {0, NULL, NULL}},
            {0xC92, {0, NULL, NULL}},
            {0xC93, {0, NULL, NULL}},
            {0xC94, {0, NULL, NULL}},
            {0xC95, {0, NULL, NULL}},
            {0xC96, {0, NULL, NULL}},
            {0xC97, {0, NULL, NULL}},
            {0xC98, {0, NULL, NULL}},
            {0xC99, {0, NULL, NULL}},
            {0xC9A, {0, NULL, NULL}},
            {0xC9B, {0, NULL, NULL}},
            {0xC9C, {0, NULL, NULL}},
            {0xC9D, {0, NULL, NULL}},
            {0xC9E, {0, NULL, NULL}},
            {0xC9F, {0, NULL, NULL}},
            //Supervisor Trap Setup
            {0x100, {0, NULL, NULL}},
            {0x102, {0, NULL, NULL}},
            {0x103, {0, NULL, NULL}},
            {0x104, {0, NULL, NULL}},
            {0x105, {0, NULL, NULL}},
            {0x106, {0, NULL, NULL}},
            //Supervisor Trap Handling
            {0x140, {0, NULL, NULL}},
            {0x141, {0, NULL, NULL}},
            {0x142, {0, NULL, NULL}},
            {0x143, {0, NULL, NULL}},
            {0x144, {0, NULL, NULL}},
            //Supervisor Protection and Translation
            {0x180, {0, NULL, NULL}},
            //Machine Information Registers
            {0xF11, {0, NULL, NULL}},
            {0xF12, {0, NULL, NULL}},
            {0xF13, {0, NULL, NULL}},
            {0xF14, {0, NULL, NULL}},
            //Machine Trap Setup
            {0x300, {0, NULL, NULL}},
            {0x301, {0, NULL, NULL}},
            {0x302, {0, NULL, NULL}},
            {0x303, {0, NULL, NULL}},
            {0x304, {0, NULL, NULL}},
            {0x305, {0, NULL, NULL}},
            {0x306, {0, NULL, NULL}},
            //Machine Trap Handling
            {0x340, {0, NULL, NULL}},
            {0x341, {0, NULL, NULL}},
            {0x342, {0, NULL, NULL}},
            {0x343, {0, NULL, NULL}},
            {0x344, {0, NULL, NULL}},
            //Machine Protection and Translation
            {0x3A0, {0, NULL, NULL}},
            {0x3A1, {0, NULL, NULL}},
            {0x3A2, {0, NULL, NULL}},
            {0x3A3, {0, NULL, NULL}},
            {0x3B0, {0, NULL, NULL}},
            {0x3B1, {0, NULL, NULL}},
            {0x3B2, {0, NULL, NULL}},
            {0x3B3, {0, NULL, NULL}},
            {0x3B4, {0, NULL, NULL}},
            {0x3B5, {0, NULL, NULL}},
            {0x3B6, {0, NULL, NULL}},
            {0x3B7, {0, NULL, NULL}},
            {0x3B8, {0, NULL, NULL}},
            {0x3B9, {0, NULL, NULL}},
            {0x3BA, {0, NULL, NULL}},
            {0x3BB, {0, NULL, NULL}},
            {0x3BC, {0, NULL, NULL}},
            {0x3BD, {0, NULL, NULL}},
            {0x3BE, {0, NULL, NULL}},
            {0x3BF, {0, NULL, NULL}},
            //Machine Counter/Timers
            {0xB00, {0, NULL, NULL}},
            {0xB02, {0, NULL, NULL}},
            {0xB03, {0, NULL, NULL}},
            {0xB04, {0, NULL, NULL}},
            {0xB05, {0, NULL, NULL}},
            {0xB06, {0, NULL, NULL}},
            {0xB07, {0, NULL, NULL}},
            {0xB08, {0, NULL, NULL}},
            {0xB09, {0, NULL, NULL}},
            {0xB0A, {0, NULL, NULL}},
            {0xB0B, {0, NULL, NULL}},
            {0xB0C, {0, NULL, NULL}},
            {0xB0D, {0, NULL, NULL}},
            {0xB0E, {0, NULL, NULL}},
            {0xB0F, {0, NULL, NULL}},
            {0xB10, {0, NULL, NULL}},
            {0xB11, {0, NULL, NULL}},
            {0xB12, {0, NULL, NULL}},
            {0xB13, {0, NULL, NULL}},
            {0xB14, {0, NULL, NULL}},
            {0xB15, {0, NULL, NULL}},
            {0xB16, {0, NULL, NULL}},
            {0xB17, {0, NULL, NULL}},
            {0xB18, {0, NULL, NULL}},
            {0xB19, {0, NULL, NULL}},
            {0xB1A, {0, NULL, NULL}},
            {0xB1B, {0, NULL, NULL}},
            {0xB1C, {0, NULL, NULL}},
            {0xB1D, {0, NULL, NULL}},
            {0xB1E, {0, NULL, NULL}},
            {0xB1F, {0, NULL, NULL}},
            {0xB80, {0, NULL, NULL}},
            {0xB82, {0, NULL, NULL}},
            {0xB83, {0, NULL, NULL}},
            {0xB84, {0, NULL, NULL}},
            {0xB85, {0, NULL, NULL}},
            {0xB86, {0, NULL, NULL}},
            {0xB87, {0, NULL, NULL}},
            {0xB88, {0, NULL, NULL}},
            {0xB89, {0, NULL, NULL}},
            {0xB8A, {0, NULL, NULL}},
            {0xB8B, {0, NULL, NULL}},
            {0xB8C, {0, NULL, NULL}},
            {0xB8D, {0, NULL, NULL}},
            {0xB8E, {0, NULL, NULL}},
            {0xB8F, {0, NULL, NULL}},
            {0xB90, {0, NULL, NULL}},
            {0xB91, {0, NULL, NULL}},
            {0xB92, {0, NULL, NULL}},
            {0xB93, {0, NULL, NULL}},
            {0xB94, {0, NULL, NULL}},
            {0xB95, {0, NULL, NULL}},
            {0xB96, {0, NULL, NULL}},
            {0xB97, {0, NULL, NULL}},
            {0xB98, {0, NULL, NULL}},
            {0xB99, {0, NULL, NULL}},
            {0xB9A, {0, NULL, NULL}},
            {0xB9B, {0, NULL, NULL}},
            {0xB9C, {0, NULL, NULL}},
            {0xB9D, {0, NULL, NULL}},
            {0xB9E, {0, NULL, NULL}},
            {0xB9F, {0, NULL, NULL}},
            //Machine Counter Setup
            {0x323, {0, NULL, NULL}},
            {0x324, {0, NULL, NULL}},
            {0x325, {0, NULL, NULL}},
            {0x326, {0, NULL, NULL}},
            {0x327, {0, NULL, NULL}},
            {0x328, {0, NULL, NULL}},
            {0x329, {0, NULL, NULL}},
            {0x32A, {0, NULL, NULL}},
            {0x32B, {0, NULL, NULL}},
            {0x32C, {0, NULL, NULL}},
            {0x32D, {0, NULL, NULL}},
            {0x32E, {0, NULL, NULL}},
            {0x32F, {0, NULL, NULL}},
            {0x330, {0, NULL, NULL}},
            {0x331, {0, NULL, NULL}},
            {0x332, {0, NULL, NULL}},
            {0x333, {0, NULL, NULL}},
            {0x334, {0, NULL, NULL}},
            {0x335, {0, NULL, NULL}},
            {0x336, {0, NULL, NULL}},
            {0x337, {0, NULL, NULL}},
            {0x338, {0, NULL, NULL}},
            {0x339, {0, NULL, NULL}},
            {0x33A, {0, NULL, NULL}},
            {0x33B, {0, NULL, NULL}},
            {0x33C, {0, NULL, NULL}},
            {0x33D, {0, NULL, NULL}},
            {0x33E, {0, NULL, NULL}},
            {0x33F, {0, NULL, NULL}},
            //Debug/Trace Registers
            {0x7A0, {0, NULL, NULL}},
            {0x7A1, {0, NULL, NULL}},
            {0x7A2, {0, NULL, NULL}},
            {0x7A3, {0, NULL, NULL}},
            //Debug Mode Registers
            {0x7B0, {0, NULL, NULL}},
            {0x7B1, {0, NULL, NULL}},
            {0x7B2, {0, NULL, NULL}},
    };
};
#endif //RISCV_CSR_H
