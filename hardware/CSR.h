//
// Created by Mimoja on 02.07.2017.
//

#ifndef RISCV_CSR_H
#define RISCV_CSR_H

#include <sstream>
#include <string>

#include "CSR/csr_register.h"
#include "CSR/misa.h"

class csr_registers{
public:
    uint32_t getCSR(uint32_t index){
        return csr[index]->read();
    }

    void setCSR(uint32_t index, uint32_t value){
        csr[index]->write(value);
    }

    void setCSRBit(uint32_t index, uint32_t bit, bool set){
        uint32_t newVal = csr[index]->value;
        if(set)
            newVal |= BIT(bit);
        else
            newVal &= ~BIT(bit);
        csr[index]->write(newVal);
    }

    std::string toString(){
        std::stringstream ss;
        for(auto const &entry : csr) {
            ss << "0x" << std::hex << (uint16_t )entry.first << " " <<entry.second->toString() << std::endl;
        }
        return ss.str();
    }

    // allow direct access for sideffect free handling
    std::map<uint16_t, CSR::csr_register*> csr ={
            //User Trap Setup
            {0x000, new CSR::csr_register("ustatus", 0)},
            {0x004, new CSR::csr_register("uie", 0)},
            {0x005, new CSR::csr_register("utvec", 0)},
            //User Trap Handling
            {0x040, new CSR::csr_register("uscratch", 0)},
            {0x041, new CSR::csr_register("uepc", 0)},
            {0x042, new CSR::csr_register("ucause", 0)},
            {0x043, new CSR::csr_register("utval", 0)},
            {0x044, new CSR::csr_register("uip", 0)},
            //User floating point CSRs
            {0x001, new CSR::csr_register("fflags", 0)},
            {0x002, new CSR::csr_register("frm", 0)},
            {0x003, new CSR::csr_register("fcsr", 0)},
            //User Counter/Timers
            {0xC00, new CSR::csr_register("cycle", 0)},
            {0xC01, new CSR::csr_register("time", 0)},
            {0xC02, new CSR::csr_register("instret", 0)},
            {0xC03, new CSR::csr_register("hpmcounter3", 0)},
            {0xC04, new CSR::csr_register("hpmcounter4", 0)},
            {0xC05, new CSR::csr_register("hpmcounter5", 0)},
            {0xC06, new CSR::csr_register("hpmcounter6", 0)},
            {0xC07, new CSR::csr_register("hpmcounter7", 0)},
            {0xC08, new CSR::csr_register("hpmcounter8", 0)},
            {0xC09, new CSR::csr_register("hpmcounter9", 0)},
            {0xC0A, new CSR::csr_register("hpmcounter10", 0)},
            {0xC0B, new CSR::csr_register("hpmcounter11", 0)},
            {0xC0C, new CSR::csr_register("hpmcounter12", 0)},
            {0xC0D, new CSR::csr_register("hpmcounter13", 0)},
            {0xC0E, new CSR::csr_register("hpmcounter14", 0)},
            {0xC0F, new CSR::csr_register("hpmcounter15", 0)},
            {0xC10, new CSR::csr_register("hpmcounter16", 0)},
            {0xC11, new CSR::csr_register("hpmcounter17", 0)},
            {0xC12, new CSR::csr_register("hpmcounter18", 0)},
            {0xC13, new CSR::csr_register("hpmcounter19", 0)},
            {0xC14, new CSR::csr_register("hpmcounter20", 0)},
            {0xC15, new CSR::csr_register("hpmcounter21", 0)},
            {0xC16, new CSR::csr_register("hpmcounter22", 0)},
            {0xC17, new CSR::csr_register("hpmcounter23", 0)},
            {0xC18, new CSR::csr_register("hpmcounter24", 0)},
            {0xC19, new CSR::csr_register("hpmcounter25", 0)},
            {0xC1A, new CSR::csr_register("hpmcounter26", 0)},
            {0xC1B, new CSR::csr_register("hpmcounter27", 0)},
            {0xC1C, new CSR::csr_register("hpmcounter28", 0)},
            {0xC1D, new CSR::csr_register("hpmcounter29", 0)},
            {0xC1E, new CSR::csr_register("hpmcounter30", 0)},
            {0xC1F, new CSR::csr_register("hpmcounter31", 0)},
            {0xC80, new CSR::csr_register("cycleh", 0)},
            {0xC81, new CSR::csr_register("timeh", 0)},
            {0xC82, new CSR::csr_register("instreth", 0)},
            {0xC83, new CSR::csr_register("hpmcounter3h", 0)},
            {0xC84, new CSR::csr_register("hpmcounter4h", 0)},
            {0xC85, new CSR::csr_register("hpmcounter5h", 0)},
            {0xC86, new CSR::csr_register("hpmcounter6h", 0)},
            {0xC87, new CSR::csr_register("hpmcounter7h", 0)},
            {0xC88, new CSR::csr_register("hpmcounter8h", 0)},
            {0xC89, new CSR::csr_register("hpmcounter9h", 0)},
            {0xC8A, new CSR::csr_register("hpmcounter10h", 0)},
            {0xC8B, new CSR::csr_register("hpmcounter11h", 0)},
            {0xC8C, new CSR::csr_register("hpmcounter12h", 0)},
            {0xC8D, new CSR::csr_register("hpmcounter13h", 0)},
            {0xC8E, new CSR::csr_register("hpmcounter14h", 0)},
            {0xC8F, new CSR::csr_register("hpmcounter15h", 0)},
            {0xC90, new CSR::csr_register("hpmcounter16h", 0)},
            {0xC91, new CSR::csr_register("hpmcounter17h", 0)},
            {0xC92, new CSR::csr_register("hpmcounter18h", 0)},
            {0xC93, new CSR::csr_register("hpmcounter19h", 0)},
            {0xC94, new CSR::csr_register("hpmcounter20h", 0)},
            {0xC95, new CSR::csr_register("hpmcounter21h", 0)},
            {0xC96, new CSR::csr_register("hpmcounter22h", 0)},
            {0xC97, new CSR::csr_register("hpmcounter23h", 0)},
            {0xC98, new CSR::csr_register("hpmcounter24h", 0)},
            {0xC99, new CSR::csr_register("hpmcounter25h", 0)},
            {0xC9A, new CSR::csr_register("hpmcounter26h", 0)},
            {0xC9B, new CSR::csr_register("hpmcounter27h", 0)},
            {0xC9C, new CSR::csr_register("hpmcounter28h", 0)},
            {0xC9D, new CSR::csr_register("hpmcounter29h", 0)},
            {0xC9E, new CSR::csr_register("hpmcounter30h", 0)},
            {0xC9F, new CSR::csr_register("hpmcounter31h", 0)},
            //Supervisor Trap Setup
            {0x100, new CSR::csr_register("sstatus", 0)},
            {0x102, new CSR::csr_register("sedeleg", 0)},
            {0x103, new CSR::csr_register("sideleg", 0)},
            {0x104, new CSR::csr_register("sie", 0)},
            {0x105, new CSR::csr_register("stvec", 0)},
            {0x106, new CSR::csr_register("scounteren", 0)},
            //Supervisor Trap Handling
            {0x140, new CSR::csr_register("sscratch", 0)},
            {0x141, new CSR::csr_register("sepc", 0)},
            {0x142, new CSR::csr_register("scause", 0)},
            {0x143, new CSR::csr_register("stval", 0)},
            {0x144, new CSR::csr_register("sip", 0)},
            //Supervisor Protection and Translation
            {0x180, new CSR::csr_register("satp", 0)},
            //Machine Information Registers
            {0xF11, new CSR::csr_register("mvendorid", 0)},
            {0xF12, new CSR::csr_register("marchid", 1337)},
            {0xF13, new CSR::csr_register("mimpid", 42)},
            {0xF14, new CSR::csr_register("mhartid", 0)},
            //Machine Trap Setup
            {0x300, new CSR::csr_register("mstatus", 0)},
            {0x301, new CSR::misa()},
            {0x302, new CSR::csr_register("medeleg", 0)},
            {0x303, new CSR::csr_register("mideleg", 0)},
            {0x304, new CSR::csr_register("mie", 0)},
            {0x305, new CSR::csr_register("mtvec", 0)},
            {0x306, new CSR::csr_register("mcounteren", 0)},
            //Machine Trap Handling
            {0x340, new CSR::csr_register("mscratch", 0)},
            {0x341, new CSR::csr_register("mepc", 0)},
            {0x342, new CSR::csr_register("mcause", 0)},
            {0x343, new CSR::csr_register("mtval", 0)},
            {0x344, new CSR::csr_register("mip", 0)},
            //Machine Protection and Translation
            {0x3A0, new CSR::csr_register("pmpcfg0", 0)},
            {0x3A1, new CSR::csr_register("pmpcfg1", 0)},
            {0x3A2, new CSR::csr_register("pmpcfg2", 0)},
            {0x3A3, new CSR::csr_register("pmpcfg3", 0)},
            {0x3B0, new CSR::csr_register("pmpaddr0", 0)},
            {0x3B1, new CSR::csr_register("pmpaddr1", 0)},
            {0x3B2, new CSR::csr_register("pmpaddr2", 0)},
            {0x3B3, new CSR::csr_register("pmpaddr3", 0)},
            {0x3B4, new CSR::csr_register("pmpaddr4", 0)},
            {0x3B5, new CSR::csr_register("pmpaddr5", 0)},
            {0x3B6, new CSR::csr_register("pmpaddr6", 0)},
            {0x3B7, new CSR::csr_register("pmpaddr7", 0)},
            {0x3B8, new CSR::csr_register("pmpaddr8", 0)},
            {0x3B9, new CSR::csr_register("pmpaddr9", 0)},
            {0x3BA, new CSR::csr_register("pmpaddr10", 0)},
            {0x3BB, new CSR::csr_register("pmpaddr11", 0)},
            {0x3BC, new CSR::csr_register("pmpaddr12", 0)},
            {0x3BD, new CSR::csr_register("pmpaddr13", 0)},
            {0x3BE, new CSR::csr_register("pmpaddr14", 0)},
            {0x3BF, new CSR::csr_register("pmpaddr15", 0)},
            //Machine Counter/Timers
            {0xB00, new CSR::csr_register("mcycle", 0)},
            {0xB02, new CSR::csr_register("minstret", 0)},
            {0xB03, new CSR::csr_register("mhpmcounter3", 0)},
            {0xB04, new CSR::csr_register("mhpmcounter4", 0)},
            {0xB05, new CSR::csr_register("mhpmcounter5", 0)},
            {0xB06, new CSR::csr_register("mhpmcounter6", 0)},
            {0xB07, new CSR::csr_register("mhpmcounter7", 0)},
            {0xB08, new CSR::csr_register("mhpmcounter8", 0)},
            {0xB09, new CSR::csr_register("mhpmcounter9", 0)},
            {0xB0A, new CSR::csr_register("mhpmcounter10", 0)},
            {0xB0B, new CSR::csr_register("mhpmcounter11", 0)},
            {0xB0C, new CSR::csr_register("mhpmcounter12", 0)},
            {0xB0D, new CSR::csr_register("mhpmcounter13", 0)},
            {0xB0E, new CSR::csr_register("mhpmcounter14", 0)},
            {0xB0F, new CSR::csr_register("mhpmcounter15", 0)},
            {0xB10, new CSR::csr_register("mhpmcounter16", 0)},
            {0xB11, new CSR::csr_register("mhpmcounter17", 0)},
            {0xB12, new CSR::csr_register("mhpmcounter18", 0)},
            {0xB13, new CSR::csr_register("mhpmcounter19", 0)},
            {0xB14, new CSR::csr_register("mhpmcounter20", 0)},
            {0xB15, new CSR::csr_register("mhpmcounter21", 0)},
            {0xB16, new CSR::csr_register("mhpmcounter22", 0)},
            {0xB17, new CSR::csr_register("mhpmcounter23", 0)},
            {0xB18, new CSR::csr_register("mhpmcounter24", 0)},
            {0xB19, new CSR::csr_register("mhpmcounter25", 0)},
            {0xB1A, new CSR::csr_register("mhpmcounter26", 0)},
            {0xB1B, new CSR::csr_register("mhpmcounter27", 0)},
            {0xB1C, new CSR::csr_register("mhpmcounter28", 0)},
            {0xB1D, new CSR::csr_register("mhpmcounter29", 0)},
            {0xB1E, new CSR::csr_register("mhpmcounter30", 0)},
            {0xB1F, new CSR::csr_register("mhpmcounter21", 0)},
            {0xB80, new CSR::csr_register("mcycleh", 0)},
            {0xB82, new CSR::csr_register("minstreth", 0)},
            {0xB83, new CSR::csr_register("mhpmcounter3h", 0)},
            {0xB84, new CSR::csr_register("mhpmcounter4h", 0)},
            {0xB85, new CSR::csr_register("mhpmcounter5h", 0)},
            {0xB86, new CSR::csr_register("mhpmcounter6h", 0)},
            {0xB87, new CSR::csr_register("mhpmcounter7h", 0)},
            {0xB88, new CSR::csr_register("mhpmcounter8h", 0)},
            {0xB89, new CSR::csr_register("mhpmcounter9h", 0)},
            {0xB8A, new CSR::csr_register("mhpmcounter10h", 0)},
            {0xB8B, new CSR::csr_register("mhpmcounter11h", 0)},
            {0xB8C, new CSR::csr_register("mhpmcounter12h", 0)},
            {0xB8D, new CSR::csr_register("mhpmcounter13h", 0)},
            {0xB8E, new CSR::csr_register("mhpmcounter14h", 0)},
            {0xB8F, new CSR::csr_register("mhpmcounter15h", 0)},
            {0xB90, new CSR::csr_register("mhpmcounter16h", 0)},
            {0xB91, new CSR::csr_register("mhpmcounter17h", 0)},
            {0xB92, new CSR::csr_register("mhpmcounter18h", 0)},
            {0xB93, new CSR::csr_register("mhpmcounter19h", 0)},
            {0xB94, new CSR::csr_register("mhpmcounter20h", 0)},
            {0xB95, new CSR::csr_register("mhpmcounter21h", 0)},
            {0xB96, new CSR::csr_register("mhpmcounter22h", 0)},
            {0xB97, new CSR::csr_register("mhpmcounter23h", 0)},
            {0xB98, new CSR::csr_register("mhpmcounter24h", 0)},
            {0xB99, new CSR::csr_register("mhpmcounter25h", 0)},
            {0xB9A, new CSR::csr_register("mhpmcounter26h", 0)},
            {0xB9B, new CSR::csr_register("mhpmcounter27h", 0)},
            {0xB9C, new CSR::csr_register("mhpmcounter28h", 0)},
            {0xB9D, new CSR::csr_register("mhpmcounter29h", 0)},
            {0xB9E, new CSR::csr_register("mhpmcounter30h", 0)},
            {0xB9F, new CSR::csr_register("mhpmcounter31h", 0)},
            //Machine Counter Setup
            {0x323, new CSR::csr_register("mhpmevent3", 0)},
            {0x324, new CSR::csr_register("mhpmevent4", 0)},
            {0x325, new CSR::csr_register("mhpmevent5", 0)},
            {0x326, new CSR::csr_register("mhpmevent6", 0)},
            {0x327, new CSR::csr_register("mhpmevent7", 0)},
            {0x328, new CSR::csr_register("mhpmevent8", 0)},
            {0x329, new CSR::csr_register("mhpmevent9", 0)},
            {0x32A, new CSR::csr_register("mhpmevent10", 0)},
            {0x32B, new CSR::csr_register("mhpmevent11", 0)},
            {0x32C, new CSR::csr_register("mhpmevent12", 0)},
            {0x32D, new CSR::csr_register("mhpmevent13", 0)},
            {0x32E, new CSR::csr_register("mhpmevent14", 0)},
            {0x32F, new CSR::csr_register("mhpmevent15", 0)},
            {0x330, new CSR::csr_register("mhpmevent16", 0)},
            {0x331, new CSR::csr_register("mhpmevent17", 0)},
            {0x332, new CSR::csr_register("mhpmevent18", 0)},
            {0x333, new CSR::csr_register("mhpmevent19", 0)},
            {0x334, new CSR::csr_register("mhpmevent20", 0)},
            {0x335, new CSR::csr_register("mhpmevent21", 0)},
            {0x336, new CSR::csr_register("mhpmevent22", 0)},
            {0x337, new CSR::csr_register("mhpmevent23", 0)},
            {0x338, new CSR::csr_register("mhpmevent24", 0)},
            {0x339, new CSR::csr_register("mhpmevent25", 0)},
            {0x33A, new CSR::csr_register("mhpmevent26", 0)},
            {0x33B, new CSR::csr_register("mhpmevent27", 0)},
            {0x33C, new CSR::csr_register("mhpmevent28", 0)},
            {0x33D, new CSR::csr_register("mhpmevent29", 0)},
            {0x33E, new CSR::csr_register("mhpmevent30", 0)},
            {0x33F, new CSR::csr_register("mhpmevent31", 0)},
            //Debug/Trace Registers
            {0x7A0, new CSR::csr_register("tselect", 0)},
            {0x7A1, new CSR::csr_register("tdata1", 0)},
            {0x7A2, new CSR::csr_register("tdata2", 0)},
            {0x7A3, new CSR::csr_register("tdata3", 0)},
            //Debug Mode Registers
            {0x7B0, new CSR::csr_register("dcsr", 0)},
            {0x7B1, new CSR::csr_register("dpc", 0)},
            {0x7B2, new CSR::csr_register("dscratch", 0)},
    };
};
#endif //RISCV_CSR_H
