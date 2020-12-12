// this is directly taken from Demo19 without change
// thanks for including step by step how this whole
// section of code came to be
// for cleaner presentation, I removed the portion of the code
// that was comment out

#if 1
#include "stm32l4xx_it.h"

extern int CSTACK$$Limit;
void __iar_program_start(void);

void Unused_Handler(void);

int const __vector_table[] @ ".intvec" = {
    (int)&CSTACK$$Limit,    // Pointer to Top of Stack
    (int)&__iar_program_start,                      // Pointer to Reset Handler
    (int)&NMI_Handler,
    (int)&HardFault_Handler,
    (int)&MemManage_Handler,
    (int)&BusFault_Handler,
    (int)&UsageFault_Handler,
    0,      // Reserved
    0,      // Reserved
    0,      // Reserved
    0,      // Reserved
    (int)&SVC_Handler,
    (int)&DebugMon_Handler,
    0,      // Reserved
    (int)&PendSV_Handler,
    (int)&SysTick_Handler
};

void NMI_Handler(void)
{
    while(1)
    {
    }
}

// When the SP register drops below the start of RAM,
// the processor enters the HardFault exception
void HardFault_Handler(void)
{
    Unused_Handler();
}

void MemManage_Handler(void)
{
    while(1)
    {
    }
}

void BusFault_Handler(void)
{
    while(1)
    {
    }
}

void UsageFault_Handler(void)
{
    while(1)
    {
    }
}

void Unused_Handler(void)
{
    while(1)
    {
    }
}

#pragma weak SVC_Handler = Unused_Handler
#pragma weak DebugMon_Handler = Unused_Handler
#pragma weak PendSV_Handler = Unused_Handler
#pragma weak SysTick_Handler = Unused_Handler

#endif