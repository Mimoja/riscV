#include <iostream>

#include <elfio/elfio.hpp>
#include <fcntl.h>
#include <sys/stat.h>

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

int main(int argc, char** argv) {

    if ( argc == 1 || argc > 2) {
        printf("Usage: %s <elf_file>\n", argv[0]);
        return 1;
    }
    ELFIO::elfio reader;

    if ( !reader.load( argv[1] ) ) {
        printf("Can't find or process ELF file %s\n", argv[1]);
        return 2;
    }
    if ( reader.get_class() != ELFCLASS32){
        printf("Wrong ELF class: %s\n", reader.get_class());
        return 3;
    }
    if ( reader.get_encoding() != ELFDATA2LSB ){
        printf("Wrong ELF encoding: Not Little Endian\n");
        return 4;
    }

    std::ifstream file(argv[1], std::ios::binary | std::ios::ate);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<char> elf_buffer(size);
    if (!file.read(elf_buffer.data(), size))
    {
        printf("File read failed");
        return 5;
    }
    printf("ELF Size is %d bytes\n", elf_buffer.size());

    memory* mem = new memory(500000+size+0x00010000);
    registers* reg = new registers();

    mem->copyToMem((uint8_t*) &elf_buffer[0], 0x00010000, elf_buffer.size());
    reg->setPC32(reader.get_entry());
    reg->setReg32(2,mem->getSize());

    printf("Entry addr is 0x%08X, offset: %d bytes\n", reader.get_entry(),reader.get_entry());
    instructions::Instruction* instruction = nullptr;

    while(true){
        try {
            instruction = decode::decode_instruction(mem->getWord(reg->getPC32()));
            printf("0x%08X: %s\n",reg->getPC32(),instruction->to_string());
            instruction->execute(reg, mem);
        }catch( const std::out_of_range& e ) {
            printf("Expception: %s\n", e.what());
            if (instruction)
                printf("Instruction: %s\n",instruction->to_string());
            printf("Register dump:\n%s\n", reg->to_string().c_str());
            return 6;
        }
        catch(const char* c){
            printf("%s \n", c);
            return 7;
        }
        reg->setPC32(reg->getPC32()+4);
    }
    return 0;
}