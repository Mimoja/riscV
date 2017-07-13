//
// Created by mimoja on 22.06.17.
//

#ifndef RISCV_ALL_H
#define RISCV_ALL_H

#include "Instruction.h"

#include "base_I/ADD.h"
#include "base_I/ADDI.h"
#include "base_I/AND.h"
#include "base_I/ANDI.h"
#include "base_I/AUIPC.h"
#include "base_I/BEQ.h"
#include "base_I/BGE.h"
#include "base_I/BGEU.h"
#include "base_I/BLT.h"
#include "base_I/BLTU.h"
#include "base_I/BNE.h"
#include "base_I/CSRRC.h"
#include "base_I/CSRRCI.h"
#include "base_I/CSRRS.h"
#include "base_I/CSRRSI.h"
#include "base_I/CSRRW.h"
#include "base_I/CSRRWI.h"
#include "base_I/EBREAK.h"
#include "base_I/ECALL.h"
#include "base_I/FENCE.h"
#include "base_I/FENCE.I.h"
#include "base_I/JAL.h"
#include "base_I/JALR.h"
#include "base_I/LB.h"
#include "base_I/LBU.h"
#include "base_I/LH.h"
#include "base_I/LHU.h"
#include "base_I/LUI.h"
#include "base_I/LW.h"
#include "base_I/OR.h"
#include "base_I/ORI.h"
#include "base_I/SB.h"
#include "base_I/SH.h"
#include "base_I/SLL.h"
#include "base_I/SLLI.h"
#include "base_I/SLT.h"
#include "base_I/SLTI.h"
#include "base_I/SLTIU.h"
#include "base_I/SLTU.h"
#include "base_I/SRA.h"
#include "base_I/SRAI.h"
#include "base_I/SRL.h"
#include "base_I/SRLI.h"
#include "base_I/SUB.h"
#include "base_I/SW.h"
#include "base_I/XOR.h"
#include "base_I/XORI.h"

#include "priviledged/MRET.h"
#include "priviledged/SRET.h"
#include "priviledged/URET.h"

#include "extension/M/DIV.h"
#include "extension/M/DIVU.h"
#include "extension/M/MUL.h"
#include "extension/M/MULH.h"
#include "extension/M/MULHSU.h"
#include "extension/M/MULHU.h"
#include "extension/M/REM.h"
#include "extension/M/REMU.h"

#include "extension/F/FLW.h"
#include "extension/F/FSW.h"
#include "extension/F/FADD.S.h"
#include "extension/F/FSUB.S.h"
#include "extension/F/FMUL.S.h"
#include "extension/F/FDIV.S.h"
#include "extension/F/FMAX.S.h"
#include "extension/F/FMIN.S.h"

#endif //RISCV_ALL_H