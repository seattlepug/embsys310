/*******************************************************************************
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    EXTERN delay                    // delay() is defined outside this file

    PUBLIC control_user_led1        // Exports symbols to other modules

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : control_user_led1
Description     : - Uses Peripheral registers at base 0x4800.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint8_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint8_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/  

GPIOA_BASE  EQU 0x48000000
GPIOA_ODR   EQU 0x14
GPIOA_BIT_5 EQU 0x20

/*
This code is based on implementation of cnotrol_user_led1 function
which is included in a trial code that I wrote:

void control_user_led1(int state, int duration)
{
    if (state == 1){
        (*((unsigned int*) (GPIOA_BASE + GPIO_ODR_OFFSET))) = GPIOA_BIT_5;
        delay(duration);
    } else {
        (*((unsigned int*) (GPIOA_BASE + GPIO_ODR_OFFSET))) = 0x0;
        delay(duration);
    }
    
}

*/

// the assembly code here is based on the assembly code I saw
// with some changes, as bitwise operation is not used here
control_user_led1
    PUSH {R3-R5,LR}     // PUSH R3-R5 and LR to Stack
    MOVS R4, R0         // MOVE the R0 into R4
    MOVS R5, R1         // MOVE the R1 into R5
    CMP R4, #1          // COMP R4 with #1, if the state will be ON
    BNE.N ledoff        // If R0 is not equal to 1, branch off to turn Off Led
    BEQ turnon          // If R0 is eqaul to 1, turn On Led this is NOT required, but added for cleaner presentation
turnon                  // if to turn on LED
    LDR R0, =GPIOA_BASE // Load GPIOA_BASE value into R0
    LDR R1, =GPIOA_ODR  // Load GPIOA_ODR Offset value into R0
    ADD R0, R0, R1      // Add GPIOA_BASE + GPIOA_ODR_OFFSET to generate the GPIOA_ODR adddress
    LDR R2, =GPIOA_BIT_5// Load GPIOA_BIT_5 value to R2
    STR R2, [R0]        // store R2 (GPIOA_BIT_5) to address GPIOA_ODR
    MOVS R0, R5         // move R0 value (GPIOA_ODR) to R5
    BL   delay          // go to delay function
    B.N  endAddress     // end, go to ending function
ledoff
    LDR R0, =GPIOA_BASE // Load GPIOA_BASE value into R0
    LDR R1, =GPIOA_ODR  // Load GPIOA_ODR Offset value into R0
    ADD R0, R0, R1      // Add GPIOA_BASE + GPIOA_ODR_OFFSET to generate the GPIOA_ODR adddress
    MOVS R2, #0          // #0 value to R2
    STR R2, [R0]        // store R2 (GPIOA_BIT_5) to address GPIOA_ODR
    MOVS R0, R5         // move R0 value (GPIOA_ODR) to R5
    BL   delay          // go to delay function
endAddress              // last operation
    POP {R0,R4,R5,PC}   // pop all the values out
    END
