// This is the code that answers question Q1 and Q2 for Assignment03

// The following section is based on lecture example used for LED2
// it is modified so that it now blinks LED1 instead

// this is Base Address for RCC registers
// this does not change, regardless LED1 or LED2
// this RCC address information is found on Table 1, 
// from Reference manual
#define RCC_BASE 0x40021000 

// this is AHB2 peripheral clock enable register
// this does not change, regardless LED1 or LED2
// the offset value is found as per section 6.4.17 from ref manual
#define RCC_AHB2ENR ( *((unsigned int*)(RCC_BASE + 0x4C)) )

// these are GPIO offest values
// they do not change, regardless LED1 or LED2
// GPIO MODER offset value found as per section 8.5.1 from ref manual
// GPIO ORD offset value found as per section 8.5.6 from ref manual
#define GPIO_MODER_OFFSET 0x00
#define GPIO_ODR_OFFSET 0x14

// below is the section to setup LED2 GPIO info
// this is from lecture notes
// GPIOB base 0x48000400 is obtained from Table 1
#define GPIOB_BASE 0x48000400
#define GPIOB_MODER (*((unsigned int*)(GPIOB_BASE + GPIO_MODER_OFFSET)))
#define GPIOB_ODR (*((unsigned int*)(GPIOB_BASE + GPIO_ODR_OFFSET)))


// below is the section to setup LED1 GPIO info
// this is based on LED2 setup with LED1 specific information
// as per board user manual Table 2, LED1 is PA5, while PED2 is PB14
// as per Datasheet, Figure 1, block diagram, LED1 uses GPIOA
// while LED2 uses GPIOB
// so now need to setup GPIOA
// Base address for GPIOA registers, from Table 1 of ref manual
// again, MODER and ODR offset values do not change
#define GPIOA_BASE 0x48000000 
#define GPIOA_MODER ( *((unsigned int*)(GPIOA_BASE + GPIO_MODER_OFFSET)) )
#define GPIOA_ODR ( *((unsigned int*) (GPIOA_BASE + GPIO_ODR_OFFSET)) )


// below is about using XOR to toggle blinking LED
// this is borrowing ideas from Demo4
// this is for LED2
#define ORD14 (1<<14) // i.e., 0x4000
// this is for LED1
#define ORD5 (1<<5) // i.e., 0x5

// set a global variable counter
// volatile int counter=0;

// define a "delay" function
// this way, we only need to worry about turning LED ON and OFF
// in the main function
// this is borrowed from demo4 blinking LED example
void delay()
{
    volatile int counter=0;
    while (counter < 100000)
    {
      counter++;
    }    
}


int main()
{   
    
    // below is for LED2, based on lecture
    // RCC_AHB2ENR |= 0x2;
    // however, since we want to turn on LED1, it will be GPIO port A
    // Set bit[0] to enable I/O port A clock.
    RCC_AHB2ENR |= 0x1;
    
    // below is for LED2, based on lecture
    // GPIOB Base Address: 0x48000400
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[29:28] to 0x01  so --> 0x400 // To enable PB14 as output
    // GPIOB_MODER &= 0xDFFFFFFF;
    // GPIOB Base Address: 0x48000400
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Set bit[14] to 1 --> 0x4000; // Turn LED ON
    // Set bit[14] to 0 --> 0x0; // Turn LED OFF
    
    // since we want LED1 instead, need to set GPIOA_MODER accordingly
    // Clear bit[11] and set bit[10] --> enable PB5 GPIO as output mode.
    GPIOA_MODER &= 0xFFFFF7FF;
    
     while(1)
    {     
        // Set bit[14] to 1 --> 0x4000; // Turn on LED2
        // GPIOB_ODR |= ORD14;
        
        // Set bit[5] = 1 --> Turn on LED1.
        GPIOA_ODR |= ORD5;
        
        // use delay function
        delay();
        
        // Set bit[14] to 0 --> 0x0; // Turn off LED2
        // GPIOB_ODR &= ~ORD14;
        
        // Set bit[5] = 0 --> Turn off LED1.
        GPIOA_ODR &= ~ORD5;
        
        // use delay function
        delay();
    }
}

