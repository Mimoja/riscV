//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_INSTRUCTION_H
#define RISCV_INSTRUCTION_H


#include <stdio.h>
#include "../decoder/opcodes.h"
#include "../hardware/registers.h"
#include "../hardware/memory.h"

namespace instructions {
    class Instruction {
    public:
        Instruction(decode::instruction_type decoded) : instr(decoded){
            sprintf(disas_buffer, "unkown: 0x%02X 0x%07X", instr.unknown.opcode, instr.unknown.unused);
        };

        virtual ~Instruction() {}

        virtual char* to_string() {
            return disas_buffer;
        }

        virtual void execute(registers* reg, memory* mem) {
            printf("unknown instruction 0x%08X at 0x%08X\n", instr.val, reg->getPC32());
            printf("no state besides pc was changed\n", instr.val, reg->getPC32());
            throw "Unknown Instruction Exception";
        };
    protected:
        char disas_buffer[128];
        decode::instruction_type instr;
    };
}

#endif //RISCV_INSTRUCTION_H
