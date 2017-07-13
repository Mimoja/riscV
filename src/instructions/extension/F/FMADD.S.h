//
// Created by Mimoja on 13.07.2017.
//

#ifndef RISCV_FMADD_S_H
#define RISCV_FMADD_S_H

namespace instructions {
    class FMADD : public Instruction {
    public:
        FMADD(const decode::instruction_type &decoded, registers reg) : Instruction(decoded, reg) {
            sprintf(disas_buffer, "FMADD %s, %s, %s %s",
                    reg.gp.getRegisterName(instr.R4.rd),
                    reg.gp.getRegisterName(instr.R4.rs1),
                    reg.gp.getRegisterName(instr.R4.rs2),
                    reg.gp.getRegisterName(instr.R4.rs3));
        }
        void execute(registers* reg, memory* mem) {
           throw "unimplemented";
        }
    };

}

#endif //RISCV_FMADD_S_H
