// this is the code to answer Q1 for assignment06
// this is based on LED2 blinking example code shared during class
// it should be noted that I kept delay.h and delay.c as separate files
// which are not shown in this main.c file
// also the portion of the code that were still using the "old" way
// of blinking LED was removed for cleaner view

#include <stdint.h>
#include "delay.h"
//#include "stm32f401xe.h"    // CMSIS - Device Specific File
#include "system_stm32l4xx.h"
#include "stm32l475xx.h"

volatile int counter=0;

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
    
    // this step needs to be changed, as now LED1 is going though GPIOA
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // GPIOB Base Address: 0x48000400
    // Address offset: 0x00
    // Set bit[29:28] to 0x01  so --> 0x400 // To enable PB14 as output
    // GPIOB->MODER &= ~GPIO_MODER_MODE14_1;
    // GPIOB->MODER |= GPIO_MODER_MODE14_0;
    
    // as per documentation, LED1 is PA5
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // GPIOB Base Address: 0x48000400
    // Address offset: 0x14
    // Set bit[14] to 1 --> 0x4000; // Turn LED ON
    // Set bit[14] to 0 --> 0x0; // Turn LED OFF
    
    while(1)
    {
        // again, change the GPIOB to GPIOA to control LED1 instead
        // GPIOB->ODR |= GPIO_ODR_OD14;
        GPIOA->ODR |= GPIO_ODR_OD5;
        delay(500000);
        
        // GPIOB->ODR &= ~GPIO_ODR_OD14;
        GPIOA->ODR &= ~GPIO_ODR_OD5;
        delay(1000000);
    }
}