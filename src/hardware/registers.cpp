//
// Created by Mimoja on 13.07.2017.
//

#include "registers.h"

/*
 * CSR
 */

uint32_t csr_registers::getCSR(uint32_t index){
    csr_entry* tmp = regs[index];
    if(tmp == NULL) throw new std::out_of_range("csr not found!");
    return tmp->read();
}

void csr_registers::setCSR(uint32_t index, uint32_t value){
    csr_entry* tmp = regs[index];
    if(tmp == NULL) throw new std::out_of_range("csr not found!");
    tmp->write(value);
}

void csr_registers::setCSRBit(uint32_t index, uint32_t bit, bool set){
    csr_entry* tmp = regs[index];
    if(tmp == NULL) throw new std::out_of_range("csr not found!");

    uint32_t newVal = tmp->value;
    if(set)
        newVal |= BIT(bit);
    else
        newVal &= ~BIT(bit);
    tmp->write(newVal);
}

std::string csr_registers::to_string() {
    std::stringstream ss;
    for (auto const &entry : regs) {
        ss << "0x" << std::hex << (uint16_t) entry.first << " " << entry.second->toString() << std::endl;
    }
    return ss.str();
}

/*
 * FP
 */
void fp_registers::setSinglePrecisionValue(uint8_t num, float value){
    if(num >= 32) throw std::out_of_range("Unknown register write");
    regs.at(num)->value = value;
}

float fp_registers::getSinglePrecisionValue(uint8_t num){
    if(num >= 32) throw std::out_of_range("Unknown register read");
    return regs.at(num)->value;
}

void fp_registers::setDoublePrecisionValue(uint8_t num, double value){
    if(num >= 32) throw std::out_of_range("Unknown register write");
    regs.at(num)->value = value;
}

double fp_registers::getDoublePrecisionValue(uint8_t num){
    if(num >= 32) throw std::out_of_range("Unknown register read");
    return regs.at(num)->value;
}

csr_entry* fp_registers::getFFLAGS(registers* reg){
    return reg->csr.regs.at(0x001);
}

csr_entry* fp_registers::getFRM(registers* reg){
    return reg->csr.regs.at(0x002);
}

CSR::fcsr* fp_registers::getFCSR(registers* reg){
    return (CSR::fcsr*) reg->csr.regs.at(0x003);
}

/*
 * GP
 */

uint32_t gp_registers::getReg32Value(uint8_t num){
    if(num >= 32) throw std::out_of_range("Unknown register read");
    if(num == 0) return 0;
    return regs.at(num)->value & 0xFFFFFFFF;
}

void gp_registers::setReg32Value(uint8_t num, uint64_t value){
    if(num >= 32) throw std::out_of_range("Unknown register write");
    if(num != 0)  regs.at(num)->value = value & 0xFFFFFFFF;
}

const char* gp_registers::getRegisterName(uint8_t num){
    if (num >= 32) throw std::out_of_range("Unknown register read");
    return regs.at(num)->name;
}

std::string gp_registers::to_string() {
    std::string str;

    for (int i = 0; i+3 < 32; i += 4) {
        char output[1000];
        sprintf(output, "%-5s 0x%08" PRIX64 " %-5s 0x%08" PRIx64 " %-5s 0x%08" PRIx64 " %-5s 0x%08" PRIx64 "\n",
                getRegisterName(i),   regs.at(i)->value,
                getRegisterName(i+1), regs.at(i+1)->value,
                getRegisterName(i+2), regs.at(i+2)->value,
                getRegisterName(i+3), regs.at(i+3)->value);
        str.append(output);
    }

    return str;
}

/*
 * registers
 */

void registers::setPC32(uint64_t pc){
    progcounter = pc & 0xFFFFFFFF;
}

uint32_t registers::getPC32(){
    return progcounter & 0xFFFFFFFF;
}

std::string registers::to_string() {
    std::string str;
    str.append(gp.to_string());
    str.append(csr.to_string());

    char output[1000];
    sprintf(output, "pc = 0x%08" PRIx64 "\n", progcounter);
    str.append(output);
    return str;
}

