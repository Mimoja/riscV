//
// Created by Mimoja on 13.07.2017.
//

#ifndef RISCV_FCSR_H
#define RISCV_FCSR_H

#include "csr_entry.h"
#include <float.h>

namespace CSR {
    class fcsr : public csr_entry {
    public:
        fcsr() : csr_entry("fcsr", 0) {
            //TODO implement correct rounding
            roundingmode mode = RNE;
            value = (mode << 5);
        };

        static const uint16_t NX = (1 << 0);
        static const uint16_t UF = (1 << 1);
        static const uint16_t OF = (1 << 2);
        static const uint16_t DZ = (1 << 3);
        static const uint16_t NV = (1 << 4);

        enum roundingmode {
            RNE = 0b000,
            RTZ = 0b001,
            RDN = 0b010,
            RUP = 0b011,
            RMM = 0b100,
            RESERVED1 = 0b101,
            RESERVED2 = 0b110,
            INVALID = 0b111,
        };


        virtual std::string toString() {
            std::stringstream ss;
            ss << name << ": " << read();
            return ss.str();
        }

        void write(uint32_t val) {
            // ignore writes to reserved bits
            value = val & 0x000000FF;

            uint16_t roundingmode = getRoundingMode();
            switch (roundingmode){
                case RNE:
                    printf("UIMPLEMENTED: Setting float roundmode to %s\n", "RNE");
                    break;
                case RTZ:
                    printf("UIMPLEMENTED: Setting float roundmode to %s\n", "RTZ");
                    break;
                case RDN:
                    printf("UIMPLEMENTED: Setting float roundmode to %s\n", "RDN");
                    break;
                case RUP:
                    printf("UIMPLEMENTED: Setting float roundmode to %s\n", "RUP");
                    break;
                case RMM:
                    printf("UIMPLEMENTED: Setting float roundmode to %s\n", "RMM");
                    break;
                default:
                    break;
            }
        };

        uint16_t getRoundingMode(){
            return (value  >> 5) & 0b111;
        }

        void clearStatusBits(){
            value ^= (value & 0b11111);
        }


    };
}

#endif //RISCV_FCSR_H
