#include <stdio.h>
#include "decoder.h"
#include "../instructions/all.h"


namespace decode {
    instructions::Instruction *decode_instruction(uint32_t next) {
        instruction_type next_instruction = {.val = next};
        uint8_t next_opcode = next_instruction.unknown.opcode;
        if (next_opcode == _LUI.opcode) {
            return new instructions::LUI(next_instruction);
        }
        if (next_opcode == _AUIPC.opcode) {
            return new instructions::AUIPC(next_instruction);
        }
        if (next_opcode == _JAL.opcode) {
            return new instructions::JAL(next_instruction);
        }
        if (next_opcode == _JALR.opcode) {
            return new instructions::JALR(next_instruction);
        }
        if (next_opcode == _BEQ.opcode) {
            uint8_t function = next_instruction.B.funct3;
            if (function == _BEQ.funct3) {
                return new instructions::BEQ(next_instruction);
            }
            if (function == _BNE.funct3) {
                return new instructions::BNE(next_instruction);
            }
            if (function == _BLT.funct3) {
                return new instructions::BLT(next_instruction);
            }
            if (function == _BGE.funct3) {
                return new instructions::BGE(next_instruction);
            }
            if (function == _BLTU.funct3) {
                return new instructions::BLTU(next_instruction);
            }
            if (function == _BGEU.funct3) {
                return new instructions::BGEU(next_instruction);
            }
        }
        if (next_opcode == _LB.opcode) {
            uint8_t function = next_instruction.I.funct3;
            if (function == _LB.funct3) {
                return new instructions::LB(next_instruction);
            }
            if (function == _LH.funct3) {
                return new instructions::LH(next_instruction);
            }
            if (function == _LW.funct3) {
                return new instructions::LW(next_instruction);
            }
            if (function == _LBU.funct3) {
                return new instructions::LBU(next_instruction);
            }
            if (function == _LHU.funct3) {
                return new instructions::LHU(next_instruction);
            }
        }
        if (next_opcode == _SB.opcode) {
            uint8_t function = next_instruction.S.funct3;
            if (function == _SB.funct3) {
                return new instructions::SB(next_instruction);
            }
            if (function == _SH.funct3) {
                return new instructions::SH(next_instruction);
            }
            if (function == _SW.funct3) {
                return new instructions::SW(next_instruction);
            }
        }
        if (next_opcode == _ADDI.opcode) {
            uint8_t function = next_instruction.I.funct3;
            if (function == _ADDI.funct3) {
                return new instructions::ADDI(next_instruction);
            }
            if (function == _SLTI.funct3) {
                return new instructions::SLTI(next_instruction);
            }
            if (function == _SLTIU.funct3) {
                return new instructions::SLTIU(next_instruction);
            }
            if (function == _XORI.funct3) {
                return new instructions::XORI(next_instruction);
            }
            if (function == _ORI.funct3) {
                return new instructions::ORI(next_instruction);
            }
            if (function == _ANDI.funct3) {
                return new instructions::ANDI(next_instruction);
            }
            if (function == _SLLI.funct3) {
                return new instructions::SLLI(next_instruction);
            }
            if (function == _SRLI.funct3) {
                uint8_t func = next_instruction.R.funct7;
                if (func == _SRLI.funct7) {
                    return new instructions::SRLI(next_instruction);
                }
                if (func == _SRAI.funct7) {
                    return new instructions::SRAI(next_instruction);
                }
            }
        }
        if (next_opcode == _ADD.opcode) {
            uint8_t function = next_instruction.R.funct3;
            if (function == _ADD.funct3) {
                uint8_t func = next_instruction.R.funct7;
                if (func == _ADD.funct7) {
                    return new instructions::ADD(next_instruction);
                }
                if (func == _SUB.funct7) {
                    return new instructions::SUB(next_instruction);
                }
            }
            if (function == _SLL.funct3) {
                return new instructions::SLL(next_instruction);
            }
            if (function == _SLT.funct3) {
                return new instructions::SLT(next_instruction);
            }
            if (function == _SLTU.funct3) {
                return new instructions::SLTU(next_instruction);
            }
            if (function == _XOR.funct3) {
                return new instructions::XOR(next_instruction);
            }
            if (function == _SRL.funct3) {
                uint8_t func = next_instruction.R.funct7;
                if (func == _SRL.funct7) {
                    return new instructions::SRL(next_instruction);
                }
                if (func == _SRA.funct7) {
                    return new instructions::SRA(next_instruction);
                }
            }
            if (function == _OR.funct3) {
                return new instructions::OR(next_instruction);
            }
            if (function == _AND.funct3) {
                return new instructions::AND(next_instruction);
            }
        }
        if (next_opcode == _FENCE.opcode) {
            uint8_t function = next_instruction.I.funct3;
            if (function == _FENCE.funct3) {
                return new instructions::FENCE(next_instruction);
            }
            if (function == _FENCE_I.funct3) {
                return new instructions::FENCE_I(next_instruction);
            }
        }
        if (next_opcode == _ECALL.opcode) {
            uint8_t function = next_instruction.I.funct3;
            if (function == _ECALL.funct3) {
                uint16_t func = next_instruction.I.imm0_11;
                if (func == _ECALL.imm0_11) {
                    return new instructions::ECALL(next_instruction);
                }
                if (func == _EBREAK.imm0_11) {
                    return new instructions::EBREAK(next_instruction);
                }
            }
            if (function == _CSRRW.funct3) {
                return new instructions::CSRRW(next_instruction);
            }
            if (function == _CSRRS.funct3) {
                return new instructions::CSRRS(next_instruction);
            }
            if (function == _CSRRC.funct3) {
                return new instructions::CSRRC(next_instruction);
            }
            if (function == _CSRRWI.funct3) {
                return new instructions::CSRRWI(next_instruction);
            }
            if (function == _CSRRSI.funct3) {
                return new instructions::CSRRSI(next_instruction);
            }
            if (function == _CSRRCI.funct3) {
                return new instructions::CSRRCI(next_instruction);
            }
        }
        //M Extension
        if (next_opcode == _MUL.opcode && next_instruction.R.funct7 == _MUL.funct7) {
            uint8_t function = next_instruction.R.funct3;
            if (function == _MUL.funct3) {
                return new instructions::MUL(next_instruction);
            }
            if (function == _MULH.funct3) {
                return new instructions::MULH(next_instruction);
            }
            if (function == _MULHSU.funct3) {
                return new instructions::MULHSU(next_instruction);
            }
            if (function == _MULHU.funct3) {
                return new instructions::MULHU(next_instruction);
            }
            if (function == _DIV.funct3) {
                return new instructions::DIV(next_instruction);
            }
            if (function == _DIVU.funct3) {
                return new instructions::DIVU(next_instruction);
            }
            if (function == _REM.funct3) {
                return new instructions::REM(next_instruction);
            }
            if (function == _REMU.funct3) {
                return new instructions::REMU(next_instruction);
            }
        }
        return new instructions::Instruction(next_instruction);
    }
}