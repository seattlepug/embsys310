// This is the code that answers question Q4 for Assignment03

// The following section is based on my code to answer Q1 and Q2
// since I have included lots of explanations in my LED1 blinking code
// I will not repeat these explanations here, to make the code more lean
// again, full details about where I found the reference values can be
// found in my LED1 code

// this is Base Address for RCC registers
#define RCC_BASE 0x40021000 

// this is AHB2 peripheral clock enable register
#define RCC_AHB2ENR ( *((unsigned int*)(RCC_BASE + 0x4C)) )

// these are GPIO offest values
#define GPIO_MODER_OFFSET 0x00
#define GPIO_ODR_OFFSET 0x14


// below is the section to setup LED1 GPIOA info
#define GPIOA_BASE 0x48000000 
#define GPIOA_MODER ( *((unsigned int*)(GPIOA_BASE + GPIO_MODER_OFFSET)) )
#define GPIOA_ODR ( *((unsigned int*) (GPIOA_BASE + GPIO_ODR_OFFSET)) )


// below is about using XOR to toggle blinking LED
// this is for LED1
#define ORD5 (1<<5) // i.e., 0x5

// define two "delay" function
// delay1 function equals to one "dit" duration
void delay1()
{
    volatile int counter=0;
    while (counter < 100000)
    {
      counter++;
    }    
}

// define two "delay" function
// delay2 function equals to three "dit" durations
void delay2()
{
    volatile int counter=0;
    while (counter < 300000)
    {
      counter++;
    }    
}


int main()
{   
    

    // Set bit[0] to enable I/O port A clock.
    RCC_AHB2ENR |= 0x1;
    
    // Clear bit[11] and set bit[10] --> enable PB5 GPIO as output mode.
    GPIOA_MODER &= 0xFFFFF7FF;
    
     while(1)
    {     
        
        // first the letter "Z"
        // (dah-dah-di-dit)
        // first dah
        // Set bit[5] = 1 --> Turn on LED1.
        GPIOA_ODR |= ORD5;
        // use delay2 function
        delay2();
        
        // brief pause
        // Set bit[5] = 0 --> Turn off LED1.
        GPIOA_ODR &= ~ORD5;
        delay1();
        
        // second dah
        // Set bit[5] = 1 --> Turn on LED1.
        GPIOA_ODR |= ORD5;
        // use delay2 function
        delay2();
        
        // brief pause
        // Set bit[5] = 0 --> Turn off LED1.
        GPIOA_ODR &= ~ORD5;
        delay1();
        
        // followed by dit
        // Set bit[5] = 1 --> Turn on LED1.
        GPIOA_ODR |= ORD5;
        // use delay1 function
        delay1();
        
        // brief pause
        // Set bit[5] = 0 --> Turn off LED1.
        GPIOA_ODR &= ~ORD5;
        delay1();
        
        // final dit for letter "Z"
        // Set bit[5] = 1 --> Turn on LED1.
        GPIOA_ODR |= ORD5;
        // use delay1 function
        delay1();
        
        // brief pause, this time longer
        // Set bit[5] = 0 --> Turn off LED1.
        GPIOA_ODR &= ~ORD5;
        delay2();
        
        // --------------------------------------------------------
        // then the letter "h"
        // ((di-di-di-dit)
        // 1st dit
        // Set bit[5] = 1 --> Turn on LED1.
        GPIOA_ODR |= ORD5;
        // use delay1 function
        delay1();
        
        // brief pause
        // Set bit[5] = 0 --> Turn off LED1.
        GPIOA_ODR &= ~ORD5;
        delay1();
        
        // 2nd dit
        // Set bit[5] = 1 --> Turn on LED1.
        GPIOA_ODR |= ORD5;
        // use delay1 function
        delay1();
        
        // brief pause
        // Set bit[5] = 0 --> Turn off LED1.
        GPIOA_ODR &= ~ORD5;
        delay1();

        // 3rd dit
        // Set bit[5] = 1 --> Turn on LED1.
        GPIOA_ODR |= ORD5;
        // use delay1 function
        delay1();
        
        // brief pause
        // Set bit[5] = 0 --> Turn off LED1.
        GPIOA_ODR &= ~ORD5;
        delay1();

        // last dit for "h"
        // Set bit[5] = 1 --> Turn on LED1.
        GPIOA_ODR |= ORD5;
        // use delay1 function
        delay1();
        
        // brief pause, this time longer
        // Set bit[5] = 0 --> Turn off LED1.
        GPIOA_ODR &= ~ORD5;
        delay2();          
        
        // -------------------------------------------
        // then letter "e"
        // (dit)
        
        // the one and only dit for "e"
        // Set bit[5] = 1 --> Turn on LED1.
        GPIOA_ODR |= ORD5;
        // use delay1 function
        delay1();           
        
        // done! ends with word break
        GPIOA_ODR &= ~ORD5;
        delay2();
        delay2();
    }
}

