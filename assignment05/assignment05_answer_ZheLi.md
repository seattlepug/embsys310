# This the answers to EMBSYS 310 - AU20 Assignment 05
# Author: Zhe Li, email: lizhe.uw@gmail.com

## Q1
### (a) what "main" function do prior to calling swapPtr function?
regardless of my implementation of swapPtr1 or swapPtr2 function, the IAR does the same thing:
during arrange step, the main functions pushs R0-R4 values, as well as LR value onto stack
```
PUSH    {R0-R4, LR}
```

### (b) What are the values in R0 & R1 when swapPtr is called?
When swapPtr is called, the dissaembly window shows the following three commands:
```
ADD     R1, SP, #0x8
ADD     R0, SP, #0xc
BL      swapPtr1
```
**Before** these three lines, R0 and R1 values are:
```
R0  0x20001FE8 --> this is the top of the stack
R1  0xE000ED88 --> not sure what this value is, this is actually the begining value of R1
```

**After** these three lines, R0 and R1 values are:
```
R0  0x20001FF4 --> this is the xPtr location in stack (current value is x address)
R1  0x20001FF0 --> this is the yPtr location in stack (current value is y address)
```

### \(c\) Share a screen shot of the local variables inside of “main” after the function swapPtr returns showing the values of the pointers
Please see the screen shots saved in the same folder. I included both the local window, as well as stack window

## Q2 Notes:
The implementation for disAsm is quite straightforward. Thanks for the sqrAsm provided, it is basically used as starting code with some small changes. The key is to recognize that divided by 2 can be achieved easily using arithmetic right shift. 
Please find screen shot saved in the same folder. 

## Q3 Notes:
First of all, my implementation actually requires the user to pass in the pointer, instead of char themselves:
```
void swapCharsAsm(char* c1, char* c2);
```
The actual assembly code is not complicated. 
I was having great difficulty playing with PrintString function. The final display was not user friendly at all, as the PrintString function prints the entire String, instead of one char at a time. 
My actual set up was to have:
```
char x = 'x'; 
char y = 'y';
```
but the display always prints the two chars together first time.
However, you can tell that the swap function indeed changes the values of the two char variables. 
I do wonder if I can actually take char variables as input (not pointers) and still achieve swapping results. 



