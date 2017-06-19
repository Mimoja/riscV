#include <iostream>
#include <stdint.h>

#include "decoder/opcodes.h"
#include "decoder/decoder.h"

uint32_t register32[32];
uint32_t pc32;

uint32_t bytecode[] = {
    0x00010537,          // lui     a0,0x10
    0xff010113,          // addi    sp,sp,-16
    0x39450513,          // addi    a0,a0,916 # 10394 <__libc_csu_fini+0x4>
    0x00112623,          // sw      ra,12(sp)
    0xfe1ff0ef,          // jal     ra,10260 <puts@plt>
    0x00c12083,          // lw      ra,12(sp)
    0x00000513,          // li      a0,0
    0x01010113,          // addi    sp,sp,16
    0x00008067,          // ret
};

int main() {
    uint32_t bytecode_length = sizeof(bytecode) / sizeof(decode::instruction_type);
    printf("%d opcodes\n", bytecode_length);
    for(int i = 0; i < bytecode_length; i++) {
        instructions::Instruction* instruction = decode::decode_instruction(bytecode[i]);
        printf("%s\n",instruction->to_string());
    }
    return 0;
}