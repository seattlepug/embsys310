# This is the answers to EMBSYS 310 - AU20 Assignment 06
# Author: Zhe Li, email: lizhe.uw@gmail.com

## Q1 Notes
The implementation of the code is quite straightforward, especially thanks to the example (LED2 blinking) shared in Canvas. The key is to identify that LED1 are using GPIOA instead of GPIOB. 
This made me appreciate more the convenience of utilizing CMSIS. 

## Q2 Notes
I basically followed the hints provided. The starting code sets things up nicely and implementation is pretty straightforward. I submitted three files: main.c, delay.s, and user_led.s. 
It should be noted that in order to help me better understand how assembly code works, I created a main.c file, just to see how compiler translates C code into assembly language, I included the the screen shots for the assembly code, which I used as reference for my answer to Q2. The c-code for the trial run was included in user_led.s and delay.s files