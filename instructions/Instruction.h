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

        virtual uint8_t pc_increment(){
            return 4;
        }

        virtual void execute(registers* reg, memory* mem) {

            printf("unknown instruction 0x%08X at 0x%08X\n", instr.val, reg->getPC32());
            printf("rtype opcode: 0x%X rd: 0x%X funct3: 0x%X rs1: 0x%X rs2: 0x%X funct7: 0x%X\n",
                   instr.R.opcode, instr.R.rd, instr.R.funct3, instr.R.rs1, instr.R.rs2, instr.R.funct7);
            printf("itype opcode: 0x%X rd: 0x%X funct3: 0x%X rs1: 0x%X imm: 0x%X\n",
                   instr.I.opcode, instr.I.rd, instr.I.funct3, instr.I.rs1, instr.I.getImm());
            printf("btype opcode: 0x%X funct3: 0x%X rs1: 0x%X rs2: 0x%X imm: 0x%X\n",
                   instr.B.opcode, instr.B.funct3, instr.B.rs1, instr.B.rs2, instr.B.getImm());
            printf("stype opcode: 0x%X funct3: 0x%X rs1: 0x%X rs2: 0x%X imm: 0x%X\n",
                   instr.S.opcode, instr.S.funct3, instr.S.rs1, instr.S.rs2, instr.S.getImm());
            printf("utype opcode: 0x%X rd: 0x%X imm: 0x%X\n",
                   instr.U.opcode, instr.U.rd, instr.U.getImm());
            printf("jtype opcode: 0x%X rd: 0x%X imm: 0x%X\n",
                   instr.J.opcode, instr.J.rd, instr.J.getImm());

            printf("no state besides pc was changed\n");
            throw "Unknown Instruction Exception";
        };
    protected:
        char disas_buffer[128];
        decode::instruction_type instr;
    };
}

#endif //RISCV_INSTRUCTION_H
