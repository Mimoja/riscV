#include <stdio.h>
#include "decoder.h"
#include "../instructions/Instruction.h"
#include "../instructions/ADDI.h"
#include "../instructions/SLTI.h"
#include "../instructions/JAL.h"
#include "../instructions/LW.h"
#include "../instructions/LUI.h"
#include "../instructions/JALR.h"
#include "../instructions/SW.h"

namespace decode {
    instructions::Instruction* decode_instruction(uint32_t next) {
        instruction_type next_instruction = {.val = next};
        uint8_t next_opcode = next_instruction.unknown.opcode;
        if (next_opcode == _LUI.opcode) {
            return new instructions::LUI(next_instruction);
        } else if (next_opcode == _AUIPC.opcode) {
            printf("AUIPC\n");
        } else if (next_opcode == _JAL.opcode) {
            return new instructions::JAL(next_instruction);
        } else if (next_opcode == _JALR.opcode) {
            return new instructions::JALR(next_instruction);
        } else if (next_opcode == _BEQ.opcode) {
            uint8_t function = next_instruction.B.funct3;
            if (function == _BEQ.funct3) {
                printf("BEQ\n");
            } else if (function == _BNE.funct3) {
                printf("BNE\n");
            } else if (function == _BLT.funct3) {
                printf("BLT\n");
            } else if (function == _BGE.funct3) {
                printf("BGE\n");
            } else if (function == _BLTU.funct3) {
                printf("BLTU\n");
            } else if (function == _BGEU.funct3) {
                printf("BGEU\n");
            }
        } else if (next_opcode == _LB.opcode) {
            uint8_t function = next_instruction.I.funct3;
            if (function == _LB.funct3) {
                printf("LB\n");
            } else if (function == _LH.funct3) {
                printf("LH\n");
            } else if (function == _LW.funct3) {
                return new instructions::LW(next_instruction);
            } else if (function == _LBU.funct3) {
                printf("LBU\n");
            } else if (function == _LHU.funct3) {
                printf("LHU\n");
            }
        } else if (next_opcode == _SB.opcode) {
            uint8_t function = next_instruction.S.funct3;
            if (function == _SB.funct3) {
                printf("SB\n");
            } else if (function == _SH.funct3) {
                printf("SH\n");
            } else if (function == _SW.funct3) {
                return new instructions::SW(next_instruction);
            }
        } else if (next_opcode == _ADDI.opcode) {
            uint8_t function = next_instruction.I.funct3;
            if (function == _ADDI.funct3) {
                return new instructions::ADDI(next_instruction);
            } else if (function == _SLTI.funct3) {
               return new instructions::SLTI(next_instruction);
            } else if (function == _SLTIU.funct3) {
                printf("SLTIU\n");
            } else if (function == _XORI.funct3) {
                printf("XORI\n");
            } else if (function == _ORI.funct3) {
                printf("ORI\n");
            } else if (function == _ANDI.funct3) {
                printf("ANDI\n");
            } else if (function == _SLLI.funct3) {
                printf("SLLI\n");
            } else if (function == _SRLI.funct3) {
                uint8_t func = next_instruction.R.funct7;
                if (func == _SRLI.funct7) {
                    printf("SRLI\n");
                } else if (func == _SRAI.funct7) {
                    printf("SRAI\n");
                }
            }
        } else if (next_opcode == _ADD.opcode) {
            uint8_t function = next_instruction.R.funct3;
            if (function == _ADD.funct3) {
                uint8_t func = next_instruction.R.funct7;
                if (func == _ADD.funct7) {
                    printf("ADD\n");
                } else if (func == _SUB.funct7) {
                    printf("SUB\n");
                }
            } else if (function == _SLL.funct3) {
                printf("SLL\n");
            } else if (function == _SLT.funct3) {
                printf("SLT\n");
            } else if (function == _SLTU.funct3) {
                printf("SLTU\n");
            } else if (function == _XOR.funct3) {
                printf("XOR\n");
            } else if (function == _SRL.funct3) {
                uint8_t func = next_instruction.R.funct7;
                if (func == _SRL.funct7) {
                    printf("SRL\n");
                } else if (func == _SRA.funct7) {
                    printf("SRA\n");
                }
            } else if (function == _OR.funct3) {
                printf("SLT\n");
            } else if (function == _AND.funct3) {
                printf("SLT\n");
            }
        } else if (next_opcode == _FENCE.opcode) {
            uint8_t function = next_instruction.I.funct3;
            if (function == _FENCE.funct3) {
                printf("FENCE\n");
            } else if (function == _FENCE_I.funct3) {
                printf("FENCE.I\n");
            }
        } else if (next_opcode == _ECALL.opcode) {
            uint8_t function = next_instruction.I.funct3;
            if (function == _ECALL.funct3) {
                uint16_t func = next_instruction.I.imm0_11;
                if (func == _ECALL.imm0_11) {
                    printf("ECALL\n");
                } else if (func == _EBREAK.imm0_11) {
                    printf("EBREAK\n");
                }
            } else if (function == _CSRRW.funct3) {
                printf("CSRRW\n");
            } else if (function == _CSRRS.funct3) {
                printf("CSRRS\n");
            } else if (function == _CSRRC.funct3) {
                printf("CSRRC\n");
            } else if (function == _CSRRWI.funct3) {
                printf("CSRRWI\n");
            } else if (function == _CSRRSI.funct3) {
                printf("CSRRSI\n");
            } else if (function == _CSRRCI.funct3) {
                printf("CSRRCI\n");
            }
        }
        return new instructions::Instruction(next_instruction);
    }
}