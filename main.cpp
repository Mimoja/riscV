#include <iostream>
#include <stdint.h>

#include "decoder/opcodes.h"
#include "decoder/decoder.h"

uint32_t bytecode[] = {
        0x00001137,          // lui     sp, 1
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
    memory* mem = new memory(5000);
    registers* reg = new registers();
    mem->copyToMem((uint8_t*) bytecode, 0, sizeof(bytecode));
    instructions::Instruction* instruction;
    for(int i = 0; i< 10; i++){
        try {
            instruction = decode::decode_instruction(mem->getWord(reg->getPC32()));
            printf("0x%08X: %s\n",reg->getPC32(),instruction->to_string());
            instruction->execute(reg, mem);
        }catch( const std::out_of_range& e ) {
            printf("Expception: %s\n", e.what());
            printf("Instruction: %s\n",instruction->to_string());
            printf("Register dump:\n%s\n", reg->to_string().c_str());
            return 1;
        }
        delete instruction;
        reg->setPC32(reg->getPC32()+4);
    }
    return 0;
}