//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_OPCODES_H
#define RISCV_OPCODES_H

#include <stdint.h>
#include <stdio.h>

#define BIT(n) (1<<n)

namespace decode {

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
        return   (sign11 << 11)
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
        if(imm5_11 & BIT(6))sign11 = 0xFFFFFFFF;
        return   (sign11  << 11)
                 | (imm5_11 << 5)
                 | (imm0_4  << 0);
    }
} __attribute__((packed)) stype;

typedef struct _btype{
    uint8_t opcode  : 7;
    uint8_t imm11   : 1;
    uint8_t imm1_4  : 4;
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
    uint8_t  imm20     : 1;
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

extern utype _LUI     ;
extern utype _AUIPC   ;
extern jtype _JAL     ;
extern itype _JALR    ;
extern btype _BEQ     ;
extern btype _BNE     ;
extern btype _BLT     ;
extern btype _BGE     ;
extern btype _BLTU    ;
extern btype _BGEU    ;
extern itype _LB      ;
extern itype _LH      ;
extern itype _LW      ;
extern itype _LBU     ;
extern itype _LHU     ;
extern stype _SB      ;
extern stype _SH      ;
extern stype _SW      ;
extern itype _ADDI    ;
extern itype _SLTI    ;
extern itype _SLTIU   ;
extern itype _XORI    ;
extern itype _ORI     ;
extern itype _ANDI    ;
extern rtype _SLLI    ;
extern rtype _SRLI    ;
extern rtype _SRAI    ;
extern rtype _ADD     ;
extern rtype _SUB     ;
extern rtype _SLL     ;
extern rtype _SLT     ;
extern rtype _SLTU    ;
extern rtype _XOR     ;
extern rtype _SRL     ;
extern rtype _SRA     ;
extern rtype _OR      ;
extern rtype _AND     ;
extern itype _FENCE   ;
extern itype _FENCE_I ;
extern itype _ECALL   ;
extern itype _EBREAK  ;
extern itype _CSRRW   ;
extern itype _CSRRS   ;
extern itype _CSRRC   ;
extern itype _CSRRWI  ;
extern itype _CSRRSI  ;
extern itype _CSRRCI  ;

// M Extension
extern rtype _MUL     ;
extern rtype _MULH    ;
extern rtype _MULHSU  ;
extern rtype _MULHU   ;
extern rtype _DIV     ;
extern rtype _DIVU    ;
extern rtype _REM     ;
extern rtype _REMU    ;


union instruction_type{
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

