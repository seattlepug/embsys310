# This the answers to EMBSYS 310 - AU20 Assignment 02
# Author: Zhe Li, email: lizhe.uw@gmail.com

## Q1 Answer
a) -2147483647
b) (R1 value) 0x80000000
c) N flag is set, as currently counter is signed, so its value goes to negative; V flag is set also, as this value has exceeded the maximum "representable" positive number the system allows

## Q2 Answer
a) counter value in "local" windown is 0
b) Neither N nor V flags are set. First of all, when you set counter value to be all Fs (0XFFFFFFFF) in local window, R1 values becomes all Fs (0XFFFFFFFF), while the local value is shown as -1. This is because counter is set as signed variable. When we increment the value by 1, the local value becomes 0, and R1 value is all 0s as well. In this case, the counter value is considered as zero, and thus, negative flag N is not set. Also this operation brings value from -1 to 0, which does not exceed "allowable" value range for the signed variable. 

## Q3 Answer
a) 2147483648
b) Both N and V flags are set also. To tell the truth, I do not fully understand why. I suppose it is beacause how N and V flags are by default thinking the value is "signed"?

## Q4 Answer
a) counter value in "local" windown is 0
b) Neither N nor V flags are set. First of all, when you set counter value to be all Fs (0XFFFFFFFF) in local window, R1 values becomes all Fs (0XFFFFFFFF), while the local value is shown as 4294967295. This is because counter is set as unsigned variable, and this is the maximum value it can represent. When we increment the value by 1, the local value becomes 0, and R1 value is all 0s as well. 
To tell the truth, I am a bit confused about how N and V flags are set for Q3 and Q4.
I would imagine N flag would never be set for unsigned integers, while V flag would be set during Q4 situation. 
I did further testing, and found out that N and V are both set during Q3 situation, and then if you increment one more, V flag is set back to "0", while N flag keeps at "1". 

## Q5 Answer
a) counter becomes a global variable
b) it is no longer visible in "locals" view window
c) it is visible in "Watch" window
d) the address for counter in memory is 0x20000000

## Q6 Answer
a) counter value is 4
b) the purpose of this code is very similar of Q4/Q5. The only difference is that we introduced a pointer variable *p_int. This pointer variable is basically pointing to the memory location of global variable counter. In this case, the ++(*p_int); statement achieves the same result as counter ++; 

## Q7 Answer
a) the address for counter is 0x20000000
b) this counter value is stored in RAM
c) The value is 4

