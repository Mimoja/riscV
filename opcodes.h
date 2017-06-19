//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_OPCODES_H
#define RISCV_OPCODES_H

#include <stdint.h>

#define BIT(n) (1<<n)

namespace opcode {

typedef struct _rtype{
    uint8_t opcode : 7;
    uint8_t rd     : 5;
    uint8_t funct3 : 3;
    uint8_t rs1    : 5;
    uint8_t rs2    : 5;
    uint8_t funct7 : 7;
} __attribute__((packed)) rtype;

typedef struct _itype{
    uint8_t opcode   : 7;
    uint8_t rd       : 5;
    uint8_t funct3   : 3;
    uint8_t rs1      : 5;
    uint16_t imm0_11 : 12;
    uint32_t getImm(){
        uint32_t sign11 = 0x00000000;
        if(imm0_11 & BIT(11)) sign11 = 0xFFFFFFFF;
        return   (sign11  << 11)
                 | (imm0_11 << 0);
    }
} __attribute__((packed)) itype;

typedef struct _stype{
    uint8_t opcode  : 7;
    uint8_t imm0_4  : 5;
    uint8_t funct3  : 3;
    uint8_t rs1     : 5;
    uint8_t rs2     : 5;
    uint8_t imm5_11 : 7;
    uint32_t getImm(){
        uint32_t sign11 = 0x00000000;
        if(imm5_11 & BIT(7))sign11 = 0xFFFFFFFF;
        return   (sign11  << 11)
                 | (imm5_11 << 5)
                 | (imm0_4  << 0);
    }
} __attribute__((packed)) stype;

typedef struct _btype{
    uint8_t opcode  : 7;
    uint8_t imm11   : 1;
    uint8_t imm1_4  : 3;
    uint8_t funct3  : 3;
    uint8_t rs1     : 5;
    uint8_t rs2     : 5;
    uint8_t imm5_10 : 6;
    uint8_t imm12   : 1;
    uint32_t getImm(){
        uint32_t sign12 = 0x00000000;
        if(imm12 & BIT(0))sign12 = 0xFFFFFFFF;
        return   (sign12  << 12)
                 | (imm11   << 11)
                 | (imm5_10 << 5)
                 | (imm1_4  << 1);
    }
} __attribute__((packed)) btype;

typedef struct _utype{
    uint8_t  opcode   : 7;
    uint8_t  rd       : 5;
    uint32_t imm12_31 : 20;
    uint32_t getImm(){
        return (imm12_31 << 12);
    }
} __attribute__((packed)) utype;

typedef struct _jtype{
    uint8_t  opcode    : 7;
    uint8_t  rd        : 5;
    uint8_t  imm12_19  : 8;
    uint8_t  imm11     : 1;
    uint16_t imm1_10   : 10;
    uint8_t  imm20    : 1;
    uint32_t getImm(){
        uint32_t sign20 = 0x00000000;
        if(imm20 & BIT(0))sign20 = 0xFFFFFFFF;
        return   (sign20   << 20)
                 | (imm12_19 << 12)
                 | (imm11    << 11)
                 | (imm1_10  << 1);
    }
} __attribute__((packed)) jtype;

typedef struct _dummytype {
    uint8_t opcode    : 7;
    uint32_t unused   : 25;
} __attribute__((packed)) dummy;

extern utype LUI     ;
extern utype AUIPC   ;
extern jtype JAL     ;
extern itype JALR    ;
extern btype BEQ     ;
extern btype BNE     ;
extern btype BLT     ;
extern btype BGE     ;
extern btype BLTU    ;
extern btype BGEU    ;
extern itype LB      ;
extern itype LH      ;
extern itype LW      ;
extern itype LBU     ;
extern itype LHU     ;
extern stype SB      ;
extern stype SH      ;
extern stype SW      ;
extern itype ADDI    ;
extern itype SLTI    ;
extern itype SLTIU   ;
extern itype XORI    ;
extern itype ORI     ;
extern itype ANDI    ;
extern rtype SLLI    ;
extern rtype SRLI    ;
extern rtype SRAI    ;
extern rtype ADD     ;
extern rtype SUB     ;
extern rtype SLL     ;
extern rtype SLT     ;
extern rtype SLTU    ;
extern rtype XOR     ;
extern rtype SRL     ;
extern rtype SRA     ;
extern rtype OR      ;
extern rtype AND     ;
extern itype FENCE   ;
extern itype FENCE_I ;
extern itype ECALL   ;
extern itype EBREAK  ;
extern itype CSRRW   ;
extern itype CSRRS   ;
extern itype CSRRC   ;
extern itype CSRRWI  ;
extern itype CSRRSI  ;
extern itype CSRRCI  ;

union instruction{
    rtype R;
    itype I;
    stype S;
    btype B;
    utype U;
    jtype J;
    dummy unknown;
    uint32_t  val;
};

}

#endif //RISCV_OPCODES_H

