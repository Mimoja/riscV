//
// Created by mimoja on 19.06.17.
//

#include "opcodes.h"

namespace decode {
    utype _LUI     = {.opcode = 0b0110111};
    utype _AUIPC   = {.opcode = 0b0010111};
    jtype _JAL     = {.opcode = 0b1101111};
    itype _JALR    = {.opcode = 0b1100111, .funct3 = 0b000};
    btype _BEQ     = {.opcode = 0b1100011, .funct3 = 0b000};
    btype _BNE     = {.opcode = 0b1100011, .funct3 = 0b001};
    btype _BLT     = {.opcode = 0b1100011, .funct3 = 0b100};
    btype _BGE     = {.opcode = 0b1100011, .funct3 = 0b101};
    btype _BLTU    = {.opcode = 0b1100011, .funct3 = 0b110};
    btype _BGEU    = {.opcode = 0b1100011, .funct3 = 0b111};
    itype _LB      = {.opcode = 0b0000011, .funct3 = 0b000};
    itype _LH      = {.opcode = 0b0000011, .funct3 = 0b001};
    itype _LW      = {.opcode = 0b0000011, .funct3 = 0b010};
    itype _LBU     = {.opcode = 0b0000011, .funct3 = 0b100};
    itype _LHU     = {.opcode = 0b0000011, .funct3 = 0b101};
    stype _SB      = {.opcode = 0b0100011, .funct3 = 0b000};
    stype _SH      = {.opcode = 0b0100011, .funct3 = 0b001};
    stype _SW      = {.opcode = 0b0100011, .funct3 = 0b010};
    itype _ADDI    = {.opcode = 0b0010011, .funct3 = 0b000};
    itype _SLTI    = {.opcode = 0b0010011, .funct3 = 0b010};
    itype _SLTIU   = {.opcode = 0b0010011, .funct3 = 0b011};
    itype _XORI    = {.opcode = 0b0010011, .funct3 = 0b100};
    itype _ORI     = {.opcode = 0b0010011, .funct3 = 0b110};
    itype _ANDI    = {.opcode = 0b0010011, .funct3 = 0b111};
    rtype _SLLI    = {.opcode = 0b0010011, .funct3 = 0b001, .funct7 = 0b0000000};
    rtype _SRLI    = {.opcode = 0b0010011, .funct3 = 0b101, .funct7 = 0b0000000};
    rtype _SRAI    = {.opcode = 0b0010011, .funct3 = 0b101, .funct7 = 0b0100000};
    rtype _ADD     = {.opcode = 0b0110011, .funct3 = 0b000, .funct7 = 0b0000000};
    rtype _SUB     = {.opcode = 0b0110011, .funct3 = 0b000, .funct7 = 0b0100000};
    rtype _SLL     = {.opcode = 0b0110011, .funct3 = 0b001, .funct7 = 0b0000000};
    rtype _SLT     = {.opcode = 0b0110011, .funct3 = 0b010, .funct7 = 0b0000000};
    rtype _SLTU    = {.opcode = 0b0110011, .funct3 = 0b011, .funct7 = 0b0000000};
    rtype _XOR     = {.opcode = 0b0110011, .funct3 = 0b100, .funct7 = 0b0000000};
    rtype _SRL     = {.opcode = 0b0110011, .funct3 = 0b101, .funct7 = 0b0000000};
    rtype _SRA     = {.opcode = 0b0110011, .funct3 = 0b101, .funct7 = 0b0100000};
    rtype _OR      = {.opcode = 0b0110011, .funct3 = 0b110, .funct7 = 0b0000000};
    rtype _AND     = {.opcode = 0b0110011, .funct3 = 0b111, .funct7 = 0b0000000};
    itype _FENCE   = {.opcode = 0b0001111, .funct3 = 0b000, .rd = 0b00000, .rs1 = 0b00000};
    itype _FENCE_I = {.opcode = 0b0001111, .funct3 = 0b001, .rd = 0b00000, .rs1 = 0b00000, .imm0_11 = 0b000000000000};
    itype _ECALL   = {.opcode = 0b1110011, .funct3 = 0b000, .rd = 0b00000, .rs1 = 0b00000, .imm0_11 = 0b000000000000};
    itype _EBREAK  = {.opcode = 0b1110011, .funct3 = 0b001, .rd = 0b00000, .rs1 = 0b00000, .imm0_11 = 0b000000000001};
    itype _CSRRW   = {.opcode = 0b1110011, .funct3 = 0b001};
    itype _CSRRS   = {.opcode = 0b1110011, .funct3 = 0b010};
    itype _CSRRC   = {.opcode = 0b1110011, .funct3 = 0b011};
    itype _CSRRWI  = {.opcode = 0b1110011, .funct3 = 0b101};
    itype _CSRRSI  = {.opcode = 0b1110011, .funct3 = 0b110};
    itype _CSRRCI  = {.opcode = 0b1110011, .funct3 = 0b111};

    itype _MRET = {.opcode = 0b1110011, .funct3 = 0b000, .rd = 0b00000, .rs1 = 0b00000, .imm0_11 = 0b001100000010};
    itype _SRET = {.opcode = 0b1110011, .funct3 = 0b000, .rd = 0b00000, .rs1 = 0b00000, .imm0_11 = 0b000100000010};
    itype _URET = {.opcode = 0b1110011, .funct3 = 0b000, .rd = 0b00000, .rs1 = 0b00000, .imm0_11 = 0b000000000010};

    // M extension
    rtype _MUL     = {.opcode = 0b0110011, .funct3 = 0b000, .funct7 = 0b0000001};
    rtype _MULH    = {.opcode = 0b0110011, .funct3 = 0b001, .funct7 = 0b0000001};
    rtype _MULHSU  = {.opcode = 0b0110011, .funct3 = 0b010, .funct7 = 0b0000001};
    rtype _MULHU   = {.opcode = 0b0110011, .funct3 = 0b011, .funct7 = 0b0000001};
    rtype _DIV     = {.opcode = 0b0110011, .funct3 = 0b100, .funct7 = 0b0000001};
    rtype _DIVU    = {.opcode = 0b0110011, .funct3 = 0b101, .funct7 = 0b0000001};
    rtype _REM     = {.opcode = 0b0110011, .funct3 = 0b110, .funct7 = 0b0000001};
    rtype _REMU    = {.opcode = 0b0110011, .funct3 = 0b111, .funct7 = 0b0000001};

    // F extension
    itype _FLW       = {.opcode = 0b0000111, .funct3 = 0b010};
    stype _FSW       = {.opcode = 0b0100111, .funct3 = 0b010};
    r4type _FMADD_S  = {.opcode = 0b1000011, .funct2 = 0b00};
    r4type _FMSUB_S  = {.opcode = 0b1000111, .funct2 = 0b00};
    r4type _FNMADD_S = {.opcode = 0b1001011, .funct2 = 0b00};
    r4type _FNMSUM_S = {.opcode = 0b1001111, .funct2 = 0b00};
    rtype _FADD_S    = {.opcode = 0b1010011, .funct7 = 0b0000000};
    rtype _FSUB_S    = {.opcode = 0b1010011, .funct7 = 0b0000100};
    rtype _FMUL_S    = {.opcode = 0b1010011, .funct7 = 0b0001000};
    rtype _FDIV_S    = {.opcode = 0b1010011, .funct7 = 0b0001100};
    rtype _FSQRT_S   = {.opcode = 0b1010011, .funct7 = 0b0101100, .rs2 = 0b00000};
    rtype _FSGNJ_S   = {.opcode = 0b1010011, .funct7 = 0b0010000, .funct3 = 0b000};
    rtype _FSGNJN_S  = {.opcode = 0b1010011, .funct7 = 0b0010000, .funct3 = 0b001};
    rtype _FSGNJX_S  = {.opcode = 0b1010011, .funct7 = 0b0010000, .funct3 = 0b010};
    rtype _FMIN_S    = {.opcode = 0b1010011, .funct7 = 0b0010100, .funct3 = 0b000};
    rtype _FMAX_S    = {.opcode = 0b1010011, .funct7 = 0b0010100, .funct3 = 0b001};
    rtype _FCVT_W_S  = {.opcode = 0b1010011, .funct7 = 0b1100000, .rs2 = 0b00000};
    rtype _FCVT_WU_S = {.opcode = 0b1010011, .funct7 = 0b1100000, .rs2 = 0b00001};
    rtype _FMV_X_W   = {.opcode = 0b1010011, .funct7 = 0b1110000, .rs2 = 0b00000};
    rtype _FEQ_S     = {.opcode = 0b1010011, .funct7 = 0b1010000};
    rtype _FLT_S     = {.opcode = 0b1010011, .funct7 = 0b1010000};
    rtype _FLE_S     = {.opcode = 0b1010011, .funct7 = 0b1010000};
    rtype _FCLASS_S  = {.opcode = 0b1010011, .funct7 = 0b1110000, .rs2 = 0b00000};
    rtype _FCVT_S_W  = {.opcode = 0b1010011, .funct7 = 0b1101000, .rs2 = 0b00000};
    rtype _FCVT_S_WU = {.opcode = 0b1010011, .funct7 = 0b1101000, .rs2 = 0b00001};
    rtype _FMV_W_X   = {.opcode = 0b1010011, .funct7 = 0b1111000, .rs2 = 0b00000};

    // D extension
    itype _FLD       = {.opcode = 0b0000111, .funct3 = 0b011};
    stype _FSD       = {.opcode = 0b0100111, .funct3 = 0b011};
    r4type _FMADD_D  = {.opcode = 0b1000011, .funct2 = 0b01};
    r4type _FMSUB_D  = {.opcode = 0b1000111, .funct2 = 0b01};
    r4type _FNMADD_D = {.opcode = 0b1001011, .funct2 = 0b01};
    r4type _FNMSUM_D = {.opcode = 0b1001111, .funct2 = 0b01};
    rtype _FADD_D    = {.opcode = 0b1010011, .funct7 = 0b0000001};
    rtype _FSUB_D    = {.opcode = 0b1010011, .funct7 = 0b0000101};
    rtype _FMUL_D    = {.opcode = 0b1010011, .funct7 = 0b0001001};
    rtype _FDIV_D    = {.opcode = 0b1010011, .funct7 = 0b0001101};
    rtype _FSQRT_D   = {.opcode = 0b1010011, .funct7 = 0b0101101, .rs2 = 0b00000};
    rtype _FSGNJ_D   = {.opcode = 0b1010011, .funct7 = 0b0010001, .funct3 = 0b000};
    rtype _FSGNJN_D  = {.opcode = 0b1010011, .funct7 = 0b0010001, .funct3 = 0b001};
    rtype _FSGNJX_D  = {.opcode = 0b1010011, .funct7 = 0b0010001, .funct3 = 0b010};
    rtype _FMIN_D    = {.opcode = 0b1010011, .funct7 = 0b0010101, .funct3 = 0b000};
    rtype _FMAX_D    = {.opcode = 0b1010011, .funct7 = 0b0010101, .funct3 = 0b001};
    rtype _FCVT_S_D  = {.opcode = 0b1010011, .funct7 = 0b0100000, .rs2 = 0b00001};
    rtype _FCVT_D_S  = {.opcode = 0b1010011, .funct7 = 0b0100001, .rs2 = 0b00000};
    rtype _FEQ_D     = {.opcode = 0b1010011, .funct7 = 0b1010001, .funct3 = 0b010};
    rtype _FLT_D     = {.opcode = 0b1010011, .funct7 = 0b1010001, .funct3 = 0b001};
    rtype _FLE_D     = {.opcode = 0b1010011, .funct7 = 0b1010001, .funct3 = 0b000};
    rtype _FCLASS_D  = {.opcode = 0b1010011, .funct7 = 0b1110001, .rs2 = 0b00000, .funct3 = 0b001};
    rtype _FCVT_W_D  = {.opcode = 0b1010011, .funct7 = 0b1100001, .rs2 = 0b00000};
    rtype _FCVT_WU_D = {.opcode = 0b1010011, .funct7 = 0b1100001, .rs2 = 0b00001};
    rtype _FCVT_D_W  = {.opcode = 0b1010011, .funct7 = 0b1101000, .rs2 = 0b00000};
    rtype _FCVT_D_WU = {.opcode = 0b1010011, .funct7 = 0b1101000, .rs2 = 0b00001};

}