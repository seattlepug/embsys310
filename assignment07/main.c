// this is the code for assignment07
// the starting point is blinking LED code for assignment06, using CMSIS
// I removed all codes regarding LED2, to make this code cleaner
// I also used demo19 as baseline, especially around setting up
// sysTick timer


#if 1
/*
***********************Solution 0*****************************
In this implementation, I basically replaced the SysTick_Initialize()
function with delay() function, in order to achieve blinking
this is really a cheating way of implementing, which basically
copies the demo19 code, and I don't think it is reflecting the 
intent of this assignment, I only used this to get myself familiar
with how to setup SysTick interrupt handler
*************************************************************
*/


#include <stdint.h>
#include "stm32l4xx_it.h"
#include "stm32l475xx.h"

// define global variable, the default clock
#define SYS_CLOCK_HZ 4000000u 

// declare a global variable
// the SysTick interrupt handle decrement this variable
// while it is also used by delay() function
// uint32_t delayCounter = 1200000u; 
// 4000u is 1ms, for demonstration purposes, use 1,200,0000u
// which is about 300ms

void delay(uint32_t delayInMs);

void main(void)
{     
    // this step needs to be changed to enable GPIOA instead of GPIOB
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // RCC Base Address: 0x40021000
    // Address offset: 0x4C
    // Set bit[1] to 1
    // 1. Enable clock to Peripheral  
    // RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    
    // as per documentation, LED1 is PA5
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    delay(4000000); // call delay function
    // this delay function basically works like 
    // SysTick_Initialize()in demo19
    
    while(1)
    {
        // again, change the GPIOB to GPIOA to control LED1 instead
        // GPIOA->ODR |= GPIO_ODR_OD5;
        // toggle LED1 instead
        

        // GPIOA->ODR &= ~GPIO_ODR_OD5;
        // delay(1000000);
    }
}

void SysTick_Handler(void)
{
    __disable_irq();
    GPIOA->ODR ^= GPIO_ODR_OD5;
    __enable_irq();
}

void delay(uint32_t delayInMs)
{
    // uint32_t SysCounter =  delayInMs * SYS_CLOCK_HZ / 4000 - 1; 
    
    // 0xE000E014 - Counts down to 0.
    SysTick->LOAD = delayInMs;
    // 0xE000E018 - Clears initial value
    SysTick->VAL = 0x0;      
    // 0xE000E010 - Enable interrupts
    SysTick->CTRL = 0x7;
    
    // reset the delayCounter
    // delayCounter = 1200000u;
}

#endif

#if 0
/*
***********************Solution 1*****************************
In this implementation, I first setup the SysTick_Initialize()
function, such that it trggers an interrupt every 1ms
this is achieved by using a different load value for the SysTick
Then update delay function to "link" to the SysTick handler, through
globle variable delayCounter
To tell the truth, I had to play around on how to properly
setup the delayCounter in delay() function, so it "translates"
to desired delay timing in SysTick handler
Initially, my thought was to convert delayInMs back to "counts" for
the CPU, so each ms in delayInMs should translates to 4000 "counts"
however, when I used the math in delay()
delayCounter = delayInMs * 4000;
it translates to more than 10 times than desired delay duration
so I played around eventually found out that a conversion factor of
about 400 works just fine. 
*************************************************************
*/

#include <stdint.h>
#include "stm32l4xx_it.h"
#include "stm32l475xx.h"

// define global variable, the default clock
#define SYS_CLOCK_HZ 4000000u 

// declare a global variable
// it is the "link" between delay function and SysTick interrupt handler
uint32_t delayCounter;

// declare the function signature
void SysTick_Initialize(void);

// declare delay function signature
void delay(uint32_t delayInMs);

void main(void)
{     
    // 1. Enable clock to Peripheral
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    
    // as per documentation, LED1 is PA5
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    SysTick_Initialize();
    
    while(1)
    {
        GPIOA->ODR ^= GPIO_ODR_OD5;
        delay(1000);
        
    }
}


void SysTick_Initialize(void)
{
    // 0xE000E014 - Counts down to 0, value updated to make internal 
    // to be 1ms (clock is 4M Hz, thus, every 4000 "counts" equals to 1ms
    SysTick->LOAD = SYS_CLOCK_HZ / 4000 - 1;
    // 0xE000E018 - Clears initial value
    SysTick->VAL = 0x0;
    // 0xE000E010 - Enable interrupts
    SysTick->CTRL = 0x7;                    
}

void SysTick_Handler(void)
{
    __disable_irq();
    while (delayCounter)
    {
        delayCounter--;
    }
    __enable_irq();
}

void delay(uint32_t delayInMs)
{
    // GPIOA->ODR ^= GPIO_ODR_OD5;
    delayCounter = delayInMs * 400;
    // SysTick_Initialize();
}

#endif