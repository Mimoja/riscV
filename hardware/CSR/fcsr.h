//
// Created by Mimoja on 13.07.2017.
//

#ifndef RISCV_FCSR_H
#define RISCV_FCSR_H

namespace CSR {
    class fcsr : public csr_register {
    public:
        fcsr() : csr_register("fcsr", 0) {
            int hardwareRound = fgetround();
            roundingmode mode = RNE;

            switch (hardwareRound){
                case FE_TONEAREST:
                    mode = RNE;
                    break;
                case FE_UPWARD:
                    mode = RUP;
                    break;
                case FE_DOWNWARD:
                    mode = RDN;
                    break;
                case FE_TOWARDZERO:
                    mode = RTZ;
                    break;
                default:
                    break;
            }
            value = (mode << 5);
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
                    fsetround(FE_TONEAREST);
                    break;
                case RTZ:
                    fsetround(FE_TOWARDZERO);
                    break;
                case RDN:
                    fsetround(FE_DOWNWARD);
                    break;
                case RUP:
                    fsetround(FE_UPWARD);
                    break;
                case RMM:
                    fsetround(FE_TONEAREST);
                    break;
                default:
                    break;
            }
        };

        roundingmode getRoundingMode(){
            return (value  >> 5) & 0b111;
        }

        void clearStatusBits(){
            value ^= (value & 0b11111);
        }

        uint16_t NX = (1 << 0);
        uint16_t UF = (1 << 1);
        uint16_t OF = (1 << 2);
        uint16_t DZ = (1 << 3);
        uint16_t NV = (1 << 4);

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
    };
}

#endif //RISCV_FCSR_H
