//
// Created by Mimoja on 13.07.2017.
//

#ifndef RISCV_INTERRUPS_H
#define RISCV_INTERRUPS_H

class trap{
public:
    trap (bool interrupt, uint16_t trap_cause):cause(trap_cause), is_interrupt(interrupt){};

    uint16_t cause;
    bool is_interrupt;

    enum interrupt_cause {
        USER_SOFTWARE_INTERRUPT = 0,
        SUPERVISOR_SOFTWARE_INTERRUPT,
        I_RESERVED1,
        MACHINE_SOFTWARE_INTERRUPT,
        USER_TIMER_INTERRUPT,
        SUPERVISOR_TIMER_INTERRUPT,
        I_RESERVED2,
        MACHINE_TIMER_INTERRUPT,
        USER_EXTERMAL_INTERRUPT,
        SUPERVISOR_EXTERNAL_INTERRUPT,
        I_RESERVED3,
        MACHINE_EXTERNAL_INTERRUPT,
    };

    enum exception_cause{
        INSTRUCTION_ADDRESS_MISALIGNED = 0,
        INSTRUCTION_ACCESS_FAULT,
        ILLEGAL_INSTRUCTION,
        BREAKPOINT,
        LOAD_ADDRESS_MISALIGNED,
        LOAD_ACCESS_FAULT,
        STORE_ADDRESS_MISALIGNED,
        STORE_ACCESS_FAULT,
        USER_ENVIRONMENT_CALL,
        SUPERVISOR_ENVIRONMENT_CALL,
        E_RESERVED1,
        MACHINE_ENVIRONMENT_CALL,
        INSTRUCTION_PAGE_FAULT,
        LOAD_PAGE_FAULT,
        E_RESERVED2,
        STORE_PAGE_FAULT,
    };
};

#endif //RISCV_INTERRUPS_H
