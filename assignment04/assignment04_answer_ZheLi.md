# This the answers to EMBSYS 310 - AU20 Assignment 04
# Author: Zhe Li, email: lizhe.uw@gmail.com

## Q1
### (a) the complier produced in assembly as three commands, when using bit-banding:  
```
MOVS    R0, #1
LDR.N   R1, [PC, #0x48]
STR     R0, [R1]
```

### (b) the complier produced in assembly as four commands, without using bit-banding:  
```
LDR.N   R0, [PC, #0x34]
LDR     R1, [R0]
ORRS.W  R1, R1, #1
STR     R1, [R0]
```


## Q2
### (a) for func2 to pass values to func1:
func2 first assigns values to the 5 declared variables var0-var4:
```
MOVS R4, #0
MOVS R5, #1
MOVS R6, #2
MOVS R7, #3
MOVS R8, #4
```
This means that now register R4-R8 are now stores the value for var0-var4 correspondingly

then, when func2 calls func1 and pass the variables in as arguments:
```
STR R8, [SP]
MOVS R3, R7
MOVS R2, R6
MOVS R1, R5
MOVS R0, R4
BL   func1
```
so R4(var0) is passed in as first argument, which is saved to R0, R5(var1) is passed in as second argument, which is saved to R5, until R8(var4), when it is passed in as the fifth argument, instead of storing it in register, it is a stack pointer.

### (b) the exact code has been presented above
the BL means brank link

### \(c\) the extra code in func1
this is at the begining of the code
```
PUSH.W  {R4-R8, LR}
MOVS    R4, R0
LDR     R5, [SP, #0x18]
```

### (d) other observations
at the of function 1, there is pop command
```
POP.W {R4-R8, PC}
```

at the end of function 2, there is pop command as well
```
POP.W {R0, R1, R4-R8, PC}
```