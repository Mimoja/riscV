#include <iostream>

#include <elfio/elfio.hpp>

#include "decoder/opcodes.h"
#include "decoder/decoder.h"

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
        printf("Wrong ELF class\n");
        return 3;
    }
    if ( reader.get_encoding() != ELFDATA2LSB ){
        printf("Wrong ELF encoding: Not Little Endian\n");
        return 4;
    }
    if( reader.get_machine() != EM_RISCV){
        printf("Wrong machine in ELF!\n");
        return 5;
    }

    ELFIO::Elf_Half seg_num = reader.segments.size();
    memory* mem = new memory(50*1024*1024);
    for ( int i = 0; i < seg_num; ++i ) {
        const ELFIO::segment* pseg = reader.segments[i];

        if(pseg->get_type() == PT_LOAD){
            printf("Copying %d bytes from segment %d to 0x%08" PRIX64 "\n", (int)pseg->get_memory_size(),i , (uint64_t)pseg->get_physical_address());
            mem->copyToMem((uint8_t*)  reader.segments[i]->get_data(), pseg->get_physical_address(), pseg->get_memory_size());
        }
    }

    registers* reg = new registers();

    reg->setPC32(reader.get_entry()-4);
    reg->setReg32(2,mem->getSize());

    printf("Entry addr is 0x%08" PRIX64 ", offset: %ld bytes\n", (uint64_t) reader.get_entry(), (long)reader.get_entry());
    instructions::Instruction* instruction = nullptr;

    uint64_t simulated_return_address = mem->getSize()+4;
    reg->setReg32(1, simulated_return_address);

    while(reg->getPC32() < simulated_return_address){
        reg->setPC32(reg->getPC32()+4);
        try {
            instruction = decode::decode_instruction((uint32_t)mem->getWord(reg->getPC32()));
            printf("0x%08X: 0x%08" PRIX64 ": %s\n", reg->getPC32(), mem->getWord(reg->getPC32()), instruction->to_string());
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
    }
    printf("Return is %u\n", reg->getReg32(10));
    return 0;
}