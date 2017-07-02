//
// Created by mimoja on 02.07.17.
//

#ifndef RISCV_CSR_REGISTER_H
#define RISCV_CSR_REGISTER_H

#include <sstream>
#include <string>

namespace CSR {
    class csr_register {
    public:
        csr_register(const char *n, uint32_t v) : name(n), value(v) {}

        const char *name;
        uint32_t value;

        virtual std::string toString() {
            std::stringstream ss;
            ss << name << ": " << value;
            return ss.str();
        }

        virtual uint32_t read() { return value; };

        virtual void write(uint32_t val) { value = val; };

    };
}
#endif //RISCV_CSR_REGISTER_H
