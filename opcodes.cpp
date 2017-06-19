//
// Created by mimoja on 19.06.17.
//

#include "opcodes.h"

namespace opcode{

utype LUI     = {.opcode = 0b0110111};
utype AUIPC   = {.opcode = 0b0010111};
jtype JAL     = {.opcode = 0b1101111};
itype JALR    = {.opcode = 0b1100111, .funct3 = 0b000 };
btype BEQ     = {.opcode = 0b1100011, .funct3 = 0b000};
btype BNE     = {.opcode = 0b1100011, .funct3 = 0b001};
btype BLT     = {.opcode = 0b1100011, .funct3 = 0b100};
btype BGE     = {.opcode = 0b1100011, .funct3 = 0b101};
btype BLTU    = {.opcode = 0b1100011, .funct3 = 0b110};
btype BGEU    = {.opcode = 0b1100011, .funct3 = 0b111};
itype LB      = {.opcode = 0b0000011, .funct3 = 0b000};
itype LH      = {.opcode = 0b0000011, .funct3 = 0b001};
itype LW      = {.opcode = 0b0000011, .funct3 = 0b010};
itype LBU     = {.opcode = 0b0000011, .funct3 = 0b100};
itype LHU     = {.opcode = 0b0000011, .funct3 = 0b101};
stype SB      = {.opcode = 0b0100011, .funct3 = 0b000};
stype SH      = {.opcode = 0b0100011, .funct3 = 0b001};
stype SW      = {.opcode = 0b0100011, .funct3 = 0b010};
itype ADDI    = {.opcode = 0b0010011, .funct3 = 0b000};
itype SLTI    = {.opcode = 0b0010011, .funct3 = 0b010};
itype SLTIU   = {.opcode = 0b0010011, .funct3 = 0b011};
itype XORI    = {.opcode = 0b0010011, .funct3 = 0b100};
itype ORI     = {.opcode = 0b0010011, .funct3 = 0b110};
itype ANDI    = {.opcode = 0b0010011, .funct3 = 0b111};
rtype SLLI    = {.opcode = 0b0010011, .funct3 = 0b001, .funct7 = 0b0000000};
rtype SRLI    = {.opcode = 0b0010011, .funct3 = 0b101, .funct7 = 0b0000000};
rtype SRAI    = {.opcode = 0b0010011, .funct3 = 0b101, .funct7 = 0b0100000};
rtype ADD     = {.opcode = 0b0110011, .funct3 = 0b000, .funct7 = 0b0000000};
rtype SUB     = {.opcode = 0b0110011, .funct3 = 0b000, .funct7 = 0b0100000};
rtype SLL     = {.opcode = 0b0110011, .funct3 = 0b001, .funct7 = 0b0000000};
rtype SLT     = {.opcode = 0b0110011, .funct3 = 0b010, .funct7 = 0b0000000};
rtype SLTU    = {.opcode = 0b0110011, .funct3 = 0b011, .funct7 = 0b0000000};
rtype XOR     = {.opcode = 0b0110011, .funct3 = 0b100, .funct7 = 0b0000000};
rtype SRL     = {.opcode = 0b0110011, .funct3 = 0b101, .funct7 = 0b0000000};
rtype SRA     = {.opcode = 0b0110011, .funct3 = 0b101, .funct7 = 0b0100000};
rtype OR      = {.opcode = 0b0110011, .funct3 = 0b110, .funct7 = 0b0000000};
rtype AND     = {.opcode = 0b0110011, .funct3 = 0b111, .funct7 = 0b0000000};
itype FENCE   = {.opcode = 0b0001111, .funct3 = 0b000, .rd = 0b00000, .rs1 = 0b00000};
itype FENCE_I = {.opcode = 0b0001111, .funct3 = 0b001, .rd = 0b00000, .rs1 = 0b00000, .imm0_11 = 0b000000000000};
itype ECALL   = {.opcode = 0b1110011, .funct3 = 0b000, .rd = 0b00000, .rs1 = 0b00000, .imm0_11 = 0b000000000000};
itype EBREAK  = {.opcode = 0b1110011, .funct3 = 0b001, .rd = 0b00000, .rs1 = 0b00000, .imm0_11 = 0b000000000001};
itype CSRRW   = {.opcode = 0b1110011, .funct3 = 0b001};
itype CSRRS   = {.opcode = 0b1110011, .funct3 = 0b010};
itype CSRRC   = {.opcode = 0b1110011, .funct3 = 0b011};
itype CSRRWI  = {.opcode = 0b1110011, .funct3 = 0b101};
itype CSRRSI  = {.opcode = 0b1110011, .funct3 = 0b110};
itype CSRRCI  = {.opcode = 0b1110011, .funct3 = 0b111};

}