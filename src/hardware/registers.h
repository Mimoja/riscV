//
// Created by mimoja on 21.06.17.
//

#ifndef RISCV_REGISTER_H
#define RISCV_REGISTER_H

#include <cinttypes>
#include <stdint.h>
#include <stdexcept>
#include <map>
#include <string.h>
#include <vector>

#include "CSR/csr_entry.h"
#include "CSR/misa.h"
#include "CSR/fcsr.h"
#include "CSR/msu_status.h"
#include "CSR/csr_ids.h"

//prototypes
class csr_registers;
class fp_registers;
class gp_registers;
class registers;


class csr_registers{
public:
    csr_registers():regs(), regs_by_name(){
        //Trap Setup
        csr_entry* status = new msu_status();
        addEntry(USTATUS_ID, status);
        addEntry(SSTATUS_ID, status);
        addEntry(MSTATUS_ID, status);
 /*
  *        {0x004, new csr_entry("uie", 0)},
            {0x005, new csr_entry("utvec", 0)},
           //Trap Handling
            {0x040, new csr_entry("uscratch", 0)},
            {0x041, new csr_entry("uepc", 0)},
            {0x042, new csr_entry("ucause", 0)},
            {0x043, new csr_entry("utval", 0)},
            {0x044, new csr_entry("uip", 0)},
            //User floating point CSRs
            {0x001, new csr_entry("fflags", 0)},
            {0x002, new csr_entry("frm", 0)},
            {0x003, new CSR::fcsr()},
            */

        addEntry(CYCLE_ID, new csr_entry("cycle", 0));
    };
    uint32_t getCSR(uint32_t index);
    void setCSR(uint32_t index, uint32_t value);
    void setCSRBit(uint32_t index, uint32_t bit, bool set);
    std::string to_string();
    uint64_t getTwoEntryValue(uint16_t upper, uint16_t lower);
    void setTwoEntryValue(uint16_t upper, uint16_t lower, uint64_t value);

    // allow direct access for sideeffect free handling
    std::map<uint16_t, csr_entry*> regs;
    std::map<const char*, csr_entry*> regs_by_name;
/*
            //User Counter/Timers
            {0xC00, new csr_entry("cycle", 0)},
            {0xC01, new csr_entry("time", 0)},
            {0xC02, new csr_entry("instret", 0)},
            {0xC03, new csr_entry("hpmcounter3", 0)},
            {0xC04, new csr_entry("hpmcounter4", 0)},
            {0xC05, new csr_entry("hpmcounter5", 0)},
            {0xC06, new csr_entry("hpmcounter6", 0)},
            {0xC07, new csr_entry("hpmcounter7", 0)},
            {0xC08, new csr_entry("hpmcounter8", 0)},
            {0xC09, new csr_entry("hpmcounter9", 0)},
            {0xC0A, new csr_entry("hpmcounter10", 0)},
            {0xC0B, new csr_entry("hpmcounter11", 0)},
            {0xC0C, new csr_entry("hpmcounter12", 0)},
            {0xC0D, new csr_entry("hpmcounter13", 0)},
            {0xC0E, new csr_entry("hpmcounter14", 0)},
            {0xC0F, new csr_entry("hpmcounter15", 0)},
            {0xC10, new csr_entry("hpmcounter16", 0)},
            {0xC11, new csr_entry("hpmcounter17", 0)},
            {0xC12, new csr_entry("hpmcounter18", 0)},
            {0xC13, new csr_entry("hpmcounter19", 0)},
            {0xC14, new csr_entry("hpmcounter20", 0)},
            {0xC15, new csr_entry("hpmcounter21", 0)},
            {0xC16, new csr_entry("hpmcounter22", 0)},
            {0xC17, new csr_entry("hpmcounter23", 0)},
            {0xC18, new csr_entry("hpmcounter24", 0)},
            {0xC19, new csr_entry("hpmcounter25", 0)},
            {0xC1A, new csr_entry("hpmcounter26", 0)},
            {0xC1B, new csr_entry("hpmcounter27", 0)},
            {0xC1C, new csr_entry("hpmcounter28", 0)},
            {0xC1D, new csr_entry("hpmcounter29", 0)},
            {0xC1E, new csr_entry("hpmcounter30", 0)},
            {0xC1F, new csr_entry("hpmcounter31", 0)},
            {0xC80, new csr_entry("cycleh", 0)},
            {0xC81, new csr_entry("timeh", 0)},
            {0xC82, new csr_entry("instreth", 0)},
            {0xC83, new csr_entry("hpmcounter3h", 0)},
            {0xC84, new csr_entry("hpmcounter4h", 0)},
            {0xC85, new csr_entry("hpmcounter5h", 0)},
            {0xC86, new csr_entry("hpmcounter6h", 0)},
            {0xC87, new csr_entry("hpmcounter7h", 0)},
            {0xC88, new csr_entry("hpmcounter8h", 0)},
            {0xC89, new csr_entry("hpmcounter9h", 0)},
            {0xC8A, new csr_entry("hpmcounter10h", 0)},
            {0xC8B, new csr_entry("hpmcounter11h", 0)},
            {0xC8C, new csr_entry("hpmcounter12h", 0)},
            {0xC8D, new csr_entry("hpmcounter13h", 0)},
            {0xC8E, new csr_entry("hpmcounter14h", 0)},
            {0xC8F, new csr_entry("hpmcounter15h", 0)},
            {0xC90, new csr_entry("hpmcounter16h", 0)},
            {0xC91, new csr_entry("hpmcounter17h", 0)},
            {0xC92, new csr_entry("hpmcounter18h", 0)},
            {0xC93, new csr_entry("hpmcounter19h", 0)},
            {0xC94, new csr_entry("hpmcounter20h", 0)},
            {0xC95, new csr_entry("hpmcounter21h", 0)},
            {0xC96, new csr_entry("hpmcounter22h", 0)},
            {0xC97, new csr_entry("hpmcounter23h", 0)},
            {0xC98, new csr_entry("hpmcounter24h", 0)},
            {0xC99, new csr_entry("hpmcounter25h", 0)},
            {0xC9A, new csr_entry("hpmcounter26h", 0)},
            {0xC9B, new csr_entry("hpmcounter27h", 0)},
            {0xC9C, new csr_entry("hpmcounter28h", 0)},
            {0xC9D, new csr_entry("hpmcounter29h", 0)},
            {0xC9E, new csr_entry("hpmcounter30h", 0)},
            {0xC9F, new csr_entry("hpmcounter31h", 0)},
            //Supervisor Trap Setup
            {SSTATUS_ID, new csr_entry("sstatus", 0)},
            {0x102, new csr_entry("sedeleg", 0)},
            {0x103, new csr_entry("sideleg", 0)},
            {0x104, new csr_entry("sie", 0)},
            {0x105, new csr_entry("stvec", 0)},
            {0x106, new csr_entry("scounteren", 0)},
            //Supervisor Trap Handling
            {0x140, new csr_entry("sscratch", 0)},
            {0x141, new csr_entry("sepc", 0)},
            {0x142, new csr_entry("scause", 0)},
            {0x143, new csr_entry("stval", 0)},
            {0x144, new csr_entry("sip", 0)},
            //Supervisor Protection and Translation
            {0x180, new csr_entry("satp", 0)},
            //Machine Information Registers
            {0xF11, new csr_entry("mvendorid", 0)},
            {0xF12, new csr_entry("marchid", 1337)},
            {0xF13, new csr_entry("mimpid", 42)},
            {0xF14, new csr_entry("mhartid", 0)},
            //Machine Trap Setup
            {MSTATUS_ID, new csr_entry("mstatus", 0)},
            {0x301, new misa()},
            {0x302, new csr_entry("medeleg", 0)},
            {0x303, new csr_entry("mideleg", 0)},
            {0x304, new csr_entry("mie", 0)},
            {0x305, new csr_entry("mtvec", 0)},
            {0x306, new csr_entry("mcounteren", 0)},
            //Machine Trap Handling
            {0x340, new csr_entry("mscratch", 0)},
            {0x341, new csr_entry("mepc", 0)},
            {0x342, new csr_entry("mcause", 0)},
            {0x343, new csr_entry("mtval", 0)},
            {0x344, new csr_entry("mip", 0)},
            //Machine Protection and Translation
            {0x3A0, new csr_entry("pmpcfg0", 0)},
            {0x3A1, new csr_entry("pmpcfg1", 0)},
            {0x3A2, new csr_entry("pmpcfg2", 0)},
            {0x3A3, new csr_entry("pmpcfg3", 0)},
            {0x3B0, new csr_entry("pmpaddr0", 0)},
            {0x3B1, new csr_entry("pmpaddr1", 0)},
            {0x3B2, new csr_entry("pmpaddr2", 0)},
            {0x3B3, new csr_entry("pmpaddr3", 0)},
            {0x3B4, new csr_entry("pmpaddr4", 0)},
            {0x3B5, new csr_entry("pmpaddr5", 0)},
            {0x3B6, new csr_entry("pmpaddr6", 0)},
            {0x3B7, new csr_entry("pmpaddr7", 0)},
            {0x3B8, new csr_entry("pmpaddr8", 0)},
            {0x3B9, new csr_entry("pmpaddr9", 0)},
            {0x3BA, new csr_entry("pmpaddr10", 0)},
            {0x3BB, new csr_entry("pmpaddr11", 0)},
            {0x3BC, new csr_entry("pmpaddr12", 0)},
            {0x3BD, new csr_entry("pmpaddr13", 0)},
            {0x3BE, new csr_entry("pmpaddr14", 0)},
            {0x3BF, new csr_entry("pmpaddr15", 0)},
            //Machine Counter/Timers
            {0xB00, new csr_entry("mcycle", 0)},
            {0xB02, new csr_entry("minstret", 0)},
            {0xB03, new csr_entry("mhpmcounter3", 0)},
            {0xB04, new csr_entry("mhpmcounter4", 0)},
            {0xB05, new csr_entry("mhpmcounter5", 0)},
            {0xB06, new csr_entry("mhpmcounter6", 0)},
            {0xB07, new csr_entry("mhpmcounter7", 0)},
            {0xB08, new csr_entry("mhpmcounter8", 0)},
            {0xB09, new csr_entry("mhpmcounter9", 0)},
            {0xB0A, new csr_entry("mhpmcounter10", 0)},
            {0xB0B, new csr_entry("mhpmcounter11", 0)},
            {0xB0C, new csr_entry("mhpmcounter12", 0)},
            {0xB0D, new csr_entry("mhpmcounter13", 0)},
            {0xB0E, new csr_entry("mhpmcounter14", 0)},
            {0xB0F, new csr_entry("mhpmcounter15", 0)},
            {0xB10, new csr_entry("mhpmcounter16", 0)},
            {0xB11, new csr_entry("mhpmcounter17", 0)},
            {0xB12, new csr_entry("mhpmcounter18", 0)},
            {0xB13, new csr_entry("mhpmcounter19", 0)},
            {0xB14, new csr_entry("mhpmcounter20", 0)},
            {0xB15, new csr_entry("mhpmcounter21", 0)},
            {0xB16, new csr_entry("mhpmcounter22", 0)},
            {0xB17, new csr_entry("mhpmcounter23", 0)},
            {0xB18, new csr_entry("mhpmcounter24", 0)},
            {0xB19, new csr_entry("mhpmcounter25", 0)},
            {0xB1A, new csr_entry("mhpmcounter26", 0)},
            {0xB1B, new csr_entry("mhpmcounter27", 0)},
            {0xB1C, new csr_entry("mhpmcounter28", 0)},
            {0xB1D, new csr_entry("mhpmcounter29", 0)},
            {0xB1E, new csr_entry("mhpmcounter30", 0)},
            {0xB1F, new csr_entry("mhpmcounter21", 0)},
            {0xB80, new csr_entry("mcycleh", 0)},
            {0xB82, new csr_entry("minstreth", 0)},
            {0xB83, new csr_entry("mhpmcounter3h", 0)},
            {0xB84, new csr_entry("mhpmcounter4h", 0)},
            {0xB85, new csr_entry("mhpmcounter5h", 0)},
            {0xB86, new csr_entry("mhpmcounter6h", 0)},
            {0xB87, new csr_entry("mhpmcounter7h", 0)},
            {0xB88, new csr_entry("mhpmcounter8h", 0)},
            {0xB89, new csr_entry("mhpmcounter9h", 0)},
            {0xB8A, new csr_entry("mhpmcounter10h", 0)},
            {0xB8B, new csr_entry("mhpmcounter11h", 0)},
            {0xB8C, new csr_entry("mhpmcounter12h", 0)},
            {0xB8D, new csr_entry("mhpmcounter13h", 0)},
            {0xB8E, new csr_entry("mhpmcounter14h", 0)},
            {0xB8F, new csr_entry("mhpmcounter15h", 0)},
            {0xB90, new csr_entry("mhpmcounter16h", 0)},
            {0xB91, new csr_entry("mhpmcounter17h", 0)},
            {0xB92, new csr_entry("mhpmcounter18h", 0)},
            {0xB93, new csr_entry("mhpmcounter19h", 0)},
            {0xB94, new csr_entry("mhpmcounter20h", 0)},
            {0xB95, new csr_entry("mhpmcounter21h", 0)},
            {0xB96, new csr_entry("mhpmcounter22h", 0)},
            {0xB97, new csr_entry("mhpmcounter23h", 0)},
            {0xB98, new csr_entry("mhpmcounter24h", 0)},
            {0xB99, new csr_entry("mhpmcounter25h", 0)},
            {0xB9A, new csr_entry("mhpmcounter26h", 0)},
            {0xB9B, new csr_entry("mhpmcounter27h", 0)},
            {0xB9C, new csr_entry("mhpmcounter28h", 0)},
            {0xB9D, new csr_entry("mhpmcounter29h", 0)},
            {0xB9E, new csr_entry("mhpmcounter30h", 0)},
            {0xB9F, new csr_entry("mhpmcounter31h", 0)},
            //Machine Counter Setup
            {0x323, new csr_entry("mhpmevent3", 0)},
            {0x324, new csr_entry("mhpmevent4", 0)},
            {0x325, new csr_entry("mhpmevent5", 0)},
            {0x326, new csr_entry("mhpmevent6", 0)},
            {0x327, new csr_entry("mhpmevent7", 0)},
            {0x328, new csr_entry("mhpmevent8", 0)},
            {0x329, new csr_entry("mhpmevent9", 0)},
            {0x32A, new csr_entry("mhpmevent10", 0)},
            {0x32B, new csr_entry("mhpmevent11", 0)},
            {0x32C, new csr_entry("mhpmevent12", 0)},
            {0x32D, new csr_entry("mhpmevent13", 0)},
            {0x32E, new csr_entry("mhpmevent14", 0)},
            {0x32F, new csr_entry("mhpmevent15", 0)},
            {0x330, new csr_entry("mhpmevent16", 0)},
            {0x331, new csr_entry("mhpmevent17", 0)},
            {0x332, new csr_entry("mhpmevent18", 0)},
            {0x333, new csr_entry("mhpmevent19", 0)},
            {0x334, new csr_entry("mhpmevent20", 0)},
            {0x335, new csr_entry("mhpmevent21", 0)},
            {0x336, new csr_entry("mhpmevent22", 0)},
            {0x337, new csr_entry("mhpmevent23", 0)},
            {0x338, new csr_entry("mhpmevent24", 0)},
            {0x339, new csr_entry("mhpmevent25", 0)},
            {0x33A, new csr_entry("mhpmevent26", 0)},
            {0x33B, new csr_entry("mhpmevent27", 0)},
            {0x33C, new csr_entry("mhpmevent28", 0)},
            {0x33D, new csr_entry("mhpmevent29", 0)},
            {0x33E, new csr_entry("mhpmevent30", 0)},
            {0x33F, new csr_entry("mhpmevent31", 0)},
            //Debug/Trace Registers
            {0x7A0, new csr_entry("tselect", 0)},
            {0x7A1, new csr_entry("tdata1", 0)},
            {0x7A2, new csr_entry("tdata2", 0)},
            {0x7A3, new csr_entry("tdata3", 0)},
            //Debug Mode Registers
            {0x7B0, new csr_entry("dcsr", 0)},
            {0x7B1, new csr_entry("dpc", 0)},
            {0x7B2, new csr_entry("dscratch", 0)},
*/

private:
    void addEntry(uint16_t id, csr_entry* csr){
        regs.insert(std::pair<uint16_t, csr_entry*>(id, csr));
        regs_by_name.insert(std::pair<const char* , csr_entry*>(csr->get_name(id), csr));
    }
};

class fp_registers{

public:
    class fp_entry{
    public:
        fp_entry(const char* name):value(0), name(name){};
        double value;
        const char* name;
    };

    void setSinglePrecisionValue(uint8_t num, float value);
    float getSinglePrecisionValue(uint8_t num);
    void setDoublePrecisionValue(uint8_t num, double value);
    double getDoublePrecisionValue(uint8_t num);

    csr_entry* getFFLAGS(registers* reg);
    csr_entry* getFRM(registers* reg);
    CSR::fcsr* getFCSR(registers* reg);


private:
    std::array<fp_entry*, 32> regs = {
            new fp_entry("ft0"),
            new fp_entry("ft1"),
            new fp_entry("ft2"),
            new fp_entry("ft3"),
            new fp_entry("ft4"),
            new fp_entry("ft5"),
            new fp_entry("ft6"),
            new fp_entry("ft7"),
            new fp_entry("fs0"),
            new fp_entry("fs1"),
            new fp_entry("fa0"),
            new fp_entry("fa1"),
            new fp_entry("fa2"),
            new fp_entry("fa3"),
            new fp_entry("fa4"),
            new fp_entry("fa5"),
            new fp_entry("fa6"),
            new fp_entry("fa7"),
            new fp_entry("fs2"),
            new fp_entry("fs3"),
            new fp_entry("fs4"),
            new fp_entry("fs5"),
            new fp_entry("fs6"),
            new fp_entry("fs7"),
            new fp_entry("fs8"),
            new fp_entry("fs9"),
            new fp_entry("fs10"),
            new fp_entry("fs11"),
            new fp_entry("ft8"),
            new fp_entry("ft9"),
            new fp_entry("ft10"),
            new fp_entry("ft11"),
    };

};

class gp_registers{
public:
    class gp_entry{
    public:
        gp_entry(const char* name):value(0), name(name){};
        uint64_t value;
        const char* name;
    };

    uint32_t getReg32Value(uint8_t num);
    void setReg32Value(uint8_t num, uint64_t value);
    const char* getRegisterName(uint8_t num);
    std::string to_string();

private:
    std::array<gp_entry*, 32> regs = {
            new gp_entry("zero"),
            new gp_entry("ra"),
            new gp_entry("sp"),
            new gp_entry("gp"),
            new gp_entry("tp"),
            new gp_entry("t0"),
            new gp_entry("t1"),
            new gp_entry("t2"),
            new gp_entry("s0"),
            new gp_entry("s1"),
            new gp_entry("a0"),
            new gp_entry("a1"),
            new gp_entry("a2"),
            new gp_entry("a3"),
            new gp_entry("a4"),
            new gp_entry("a5"),
            new gp_entry("a6"),
            new gp_entry("a7"),
            new gp_entry("s2"),
            new gp_entry("s3"),
            new gp_entry("s4"),
            new gp_entry("s5"),
            new gp_entry("s6"),
            new gp_entry("s7"),
            new gp_entry("s8"),
            new gp_entry("s9"),
            new gp_entry("s10"),
            new gp_entry("s11"),
            new gp_entry("t3"),
            new gp_entry("t4"),
            new gp_entry("t5"),
            new gp_entry("t6"),
    };
};

class registers
{
public:
    csr_registers csr;
    gp_registers gp;
    fp_registers fp;


    enum accesslevel{
        accesslevel_M,
        accesslevel_S,
        accesslevel_U,
        accesslevel_D
    };

    accesslevel current_runlevel = accesslevel_M;

    registers():csr(), gp(), fp(){};

    void setPC32(uint64_t pc);
    uint32_t getPC32();
    std::string to_string();

private:
    uint64_t progcounter;
};

#endif //RISCV_REGISTER_H
