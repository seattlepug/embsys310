// This is the code that answers question Q1 Assignment04
// this is based on blinking LED code for Assignment03
// but use bit-banding instead

// instead of using RCC register
// use bit banding for peripheral alias intead
// this is found in table 15 as per programing manual
#define PERIPHERAL_BIT_BAND_ALIAS 0x42000000
// define an offset, whcih is the byte_offset
#define RCC_AHB2ENR_OFFSET 0x2104C

// these are GPIO offest values
// they do not change, regardless LED1 or LED2
// GPIO MODER offset value found as per section 8.5.1 from ref manual
// GPIO ORD offset value found as per section 8.5.6 from ref manual
#define GPIO_MODER_OFFSET 0x00
#define GPIO_ODR_OFFSET 0x14

// below is the section to setup LED1 GPIO info
// this is based on assignment03
#define GPIOA_BASE 0x48000000 
#define GPIOA_MODER ( *((unsigned int*)(GPIOA_BASE + GPIO_MODER_OFFSET)) )
#define GPIOA_ODR ( *((unsigned int*) (GPIOA_BASE + GPIO_ODR_OFFSET)) )

// below is about using XOR to toggle blinking LED
// this is for LED1
#define ORD5 (1<<5) // i.e., 0x5

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
    // Set bit[0] to enable I/O port A clock. using formula
    *((unsigned int*)(PERIPHERAL_BIT_BAND_ALIAS + (RCC_AHB2ENR_OFFSET * 32) + (0 * 4))) = 1;
    
    // since we want LED1 instead, need to set GPIOA_MODER accordingly
    // Clear bit[11] and set bit[10] --> enable PB5 GPIO as output mode.
    GPIOA_MODER &= 0xFFFFF7FF;
    
    // the rest is the same as assignment03
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
