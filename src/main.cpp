#include <iostream>

#include <elfio/elfio.hpp>

#include "decoder/decoder.h"
#include "hardware/interrups.h"
#include "hardware/cpu.h"

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

    memory* mem = new memory(UINT32_MAX);

    ELFIO::Elf_Half seg_num = reader.segments.size();
    for ( int i = 0; i < seg_num; ++i ) {
        const ELFIO::segment* pseg = reader.segments[i];

        if(pseg->get_type() == PT_LOAD){
            printf("Copying %d bytes from segment %d to 0x%08" PRIX64 "\n", (int)pseg->get_memory_size(),i , (uint64_t)pseg->get_physical_address());
            mem->copyToMem((uint8_t*)  reader.segments[i]->get_data(), pseg->get_physical_address(), pseg->get_memory_size());
        }
    }

    uint32_t start_pc = reader.get_entry();
    uint64_t simulated_return_address = 0x500;

    cpu c(mem, start_pc, simulated_return_address);
    printf("Entry addr is 0x%08" PRIX64 ", offset: %ld bytes\n", (uint64_t) reader.get_entry(), (long)reader.get_entry());

    return c.run();

}
