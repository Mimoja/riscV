//
// Created by mimoja on 19.06.17.
//

#ifndef RISCV_DECODER_H
#define RISCV_DECODER_H

#include "opcodes.h"
#include "../instructions/Instruction.h"

namespace decode {
    instructions::Instruction* decode_instruction(uint32_t next);
};

#endif //RISCV_DECODER_H
