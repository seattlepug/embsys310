# This is the answers to EMBSYS 310 - AU20 Assignment 08
# Author: Zhe Li, email: lizhe.uw@gmail.com

## notes for this assignment (only LED1 blinking)
* As you pointed out, this is an example where we pretty much "reverse engineer" a solution, out of existing solution. 
The tutorial from waveshare wiki is very helpful. It pretty much setup 95% of the code.

* I just need to recognize a few details about the proper timer parameters, as well as prescaler and counter period value. 
I used prescaler value of 4000, and counter period of 500, based on my understanding, this should translate to a PWM period of 500ms: system clock is 4MHz, pre-scaler of 4000 divided it down to 1000Hz. Then, counter of 500 results of 500ms (half a second).

* In addition, I need to acknowledge the help provided by my classmates from the discussion board. Especially the fact that HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1) should be included in the void user_pwm_setvalue(uint16_t value) function. 