//
// Created by mimoja on 19.06.17.
//

#include <stdio.h>
#include "decoder.h"

using namespace opcode;
void decode_instruction(instruction next){
    printf("next is %08X\n", next.val);
    printf("opcode is %04X\n", next.unknown.opcode);
    uint8_t next_opcode = next.unknown.opcode;
    if(next_opcode == LUI.opcode){
        printf("LUI\n");
    }else if(next_opcode == AUIPC.opcode){
        printf("AUIPC\n");
    }else if(next_opcode == JAL.opcode){
        printf("JAL\n");
    }else if(next_opcode == JALR.opcode){
        printf("JALR\n");
    }else if(next_opcode == BEQ.opcode){
        uint8_t function = next.B.funct3;
        if(function == BEQ.funct3){
            printf("BEQ\n");
        }else if(function == BNE.funct3){
            printf("BNE\n");
        }else if(function == BLT.funct3){
            printf("BLT\n");
        }else if(function == BGE.funct3){
            printf("BGE\n");
        }else if(function == BLTU.funct3){
            printf("BLTU\n");
        }else if(function == BGEU.funct3){
            printf("BGEU\n");
        }
    }else if(next_opcode == LB.opcode){
        uint8_t function = next.I.funct3;
        if(function == LB.funct3){
            printf("LB\n");
        }else if(function == LH.funct3){
            printf("LH\n");
        }else if(function == LW.funct3){
            printf("LW\n");
        }else if(function == LBU.funct3){
            printf("LBU\n");
        }else if(function == LHU.funct3){
            printf("LHU\n");
        }
    }else if(next_opcode == SB.opcode){
        uint8_t function = next.S.funct3;
        if(function == SB.funct3){
            printf("SB\n");
        }else if(function == SH.funct3){
            printf("SH\n");
        }else if(function == SW.funct3){
            printf("SW\n");
        }
    }else if(next_opcode == ADDI.opcode){
        uint8_t function = next.I.funct3;
        if(function == ADDI.funct3){
            printf("ADDI\n");
        }else if(function == SLTI.funct3) {
            printf("SLTI\n");
        }else if(function == SLTIU.funct3) {
            printf("SLTIU\n");
        }else if(function == XORI.funct3) {
            printf("XORI\n");
        }else if(function == ORI.funct3) {
            printf("ORI\n");
        }else if(function == ANDI.funct3) {
            printf("ANDI\n");
        }else if(function == SLLI.funct3) {
            printf("SLLI\n");
        }else if(function == SRLI.funct3) {
            uint8_t func = next.R.funct7;
            if(func == SRLI.funct7){
                printf("SRLI\n");
            }else if(func == SRAI.funct7) {
                printf("SRAI\n");
            }
        }
    }else if(next_opcode == ADD.opcode) {
        uint8_t function = next.R.funct3;
        if(function == ADD.funct3) {
            uint8_t func = next.R.funct7;
            if(func == ADD.funct7){
                printf("ADD\n");
            }else if(func == SUB.funct7) {
                printf("SUB\n");
            }
        }else if(function == SLL.funct3) {
            printf("SLL\n");
        }else if(function == SLT.funct3) {
            printf("SLT\n");
        }else if(function == SLTU.funct3) {
            printf("SLTU\n");
        }else if(function == XOR.funct3) {
            printf("XOR\n");
        }else if(function == SRL.funct3) {
            uint8_t func = next.R.funct7;
            if(func == SRL.funct7){
                printf("SRL\n");
            }else if(func == SRA.funct7) {
                printf("SRA\n");
            }
        }else if(function == OR.funct3) {
            printf("SLT\n");
        }else if(function == AND.funct3) {
            printf("SLT\n");
        }
    }else if(next_opcode == FENCE.opcode) {
        uint8_t function = next.I.funct3;
        if(function == FENCE.funct3){
            printf("FENCE\n");
        }else if(function == FENCE_I.funct3){
            printf("FENCE.I\n");
        }
    }else if(next_opcode == ECALL.opcode) {
        uint8_t function = next.I.funct3;
        if(function == ECALL.funct3){
            uint16_t func = next.I.imm0_11;
            if(func == ECALL.imm0_11){
                printf("ECALL\n");
            }else if(func == EBREAK.imm0_11){
                printf("EBREAK\n");
            }
        }else if(function == CSRRW.funct3){
            printf("CSRRW\n");
        }else if(function == CSRRS.funct3){
            printf("CSRRS\n");
        }else if(function == CSRRC.funct3){
            printf("CSRRC\n");
        }else if(function == CSRRWI.funct3){
            printf("CSRRWI\n");
        }else if(function == CSRRSI.funct3){
            printf("CSRRSI\n");
        }else if(function == CSRRCI.funct3){
            printf("CSRRCI\n");
        }
    }
}