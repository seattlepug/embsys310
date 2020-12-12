# This is the answers to EMBSYS 310 - AU20 Assignment 07
# Author: Zhe Li, email: lizhe.uw@gmail.com

## Q1 Notes
* I started this assignment, using blinking LED code for assignment06 (utilizing CMSIS)
* I heavily reused the code from Demo19 for my own vector table definition, as well as SysTick Timer setup
    * For the startup_stm32l475xx.c file setup, it was basically a reuse of Demo19 example
    * For SysTick Timer setup, I started by using Demo19 code, but with necessary updates (please see my main.c file for more details)
    * I ended up using two versions: solution 0 and solution 1, solution 0 is almost mimicing demo19, solution 1 is more following hint listed from the assignment, I have more detailed comments in the main.c file

## Q2 Notes
First of all, I tried to enable codes for solution 0 and 1 separately, and see if there are any differences in the main.map file output, turns out, there are some differences, please find screenshots for your reference. 
* For Solution 0:
* (a) ROM: 64 bytes (data memory), 238 bytes (code memory), total: 302 bytes
* (b) RAM: 8192 bytes
* \(c\) startup_stm32l475xx.o takes all ROM space in data memory(64/64), while it also takes some code memory (18/238), but not nearly as much as main.o in code memory (100/238)
* (d) for RAM space, the linker created took all of the space.
* -------------------------------------------
* For Solution 1:
* (a) ROM: ROM: 82 bytes (data memory), 372 bytes (code memory), total: 454 bytes
* (b) RAM: 8192 bytes
* \(c\) similar story startup_stm32l475xx.o takes most ROM space in data memory(64/82), while it also takes some code memory (18/372), but not nearly as much as main.o in code memory (136/372)
* (d) for RAM space, the linker created took all of the space.