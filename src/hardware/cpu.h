//
// Created by Mimoja on 13.07.2017.
//

#ifndef RISCV_CPU_H
#define RISCV_CPU_H

#include <cstdint>
#include "memory.h"
#include "registers.h"
#include "../instructions/Instruction.h"
#include "traps.h"
#include "../decoder/decoder.h"
#include "CSR/mcause.h"

class cpu {

public:
    cpu(memory *mem, uint32_t intitalPC, uint32_t returnAddress) : mem(mem), returnAddress(returnAddress) {
        reg = new registers();

        reg->setPC32(intitalPC);
        reg->gp.setReg32Value(2, mem->getSize());
        reg->gp.setReg32Value(1, returnAddress);


    }

    int run() {
        instructions::Instruction *instruction = nullptr;
        while (reg->getPC32() != returnAddress) {
            /*char c;
            do {
                c = getchar();
            }
            while (isspace(c) && !(c == 'n' || c == 'r'));
            if(c == 'r') {
                printf("Register dump:\n%s\n", reg->to_string().c_str());
                continue;
            }*/

            try {
                instruction = decode::decode_instruction((uint32_t) mem->getWord(reg->getPC32()), *reg);
                printf("0x%08X: 0x%08" PRIX64 ": %s\n", reg->getPC32(), mem->getWord(reg->getPC32()),
                       instruction->to_string());
                instruction->execute(reg, mem);
                // increment PC
                reg->setPC32(reg->getPC32() + instruction->pc_increment());


            } catch (trap t) {

                // TODO implement
                registers::accesslevel targetLevel = registers::accesslevel_M;

                switch(targetLevel){
                    case registers::accesslevel_M:
                        //save pc to mpec
                        reg->csr.regs_by_name.at("mpec")->value = reg->getPC32();
                        break;
                    case registers::accesslevel_S:
                        break;
                    case registers::accesslevel_U:
                        break;
                    case registers::accesslevel_D:
                        break;
                    default:
                        throw "Unknown accesslevel!";
                        break;
                }


                printf("MRET!!!!!!!\n");
                //Todo implement
                reg->setPC32(returnAddress);
            }
            catch (const std::out_of_range &e) {
                printf("Expception: %s\n", e.what());
                if (instruction)
                    printf("Instruction: %s\n", instruction->to_string());
                printf("Register dump:\n%s\n", reg->to_string().c_str());
                return 6;
            }
            catch (const char *c) {
                printf("%s \n", c);
                return 7;
            }
            delete instruction;
        }
        printf("Return is %u\n", reg->gp.getReg32Value(10));
        //printf("%s", reg->csr.toString().c_str());
        return 0;
    }

private:
    memory *mem;
    registers *reg;
    uint32_t returnAddress;

};
#endif //RISCV_CPU_H
