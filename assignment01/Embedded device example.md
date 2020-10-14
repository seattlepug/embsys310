# Fitbit 
I used to wear Fitbit, but stopped doing that. I think part of the reason for me stop wearing Fitbit are precisely related to the development challenges for embedded systems.

## Power Consumption:
Fitbit not only track my steps throughout the day, it also track my sleep. Theoretically I never need to remove it, well, with the exception when I need to re-charge it. Even though it does not take too long to recharge, it still proves to be a hassle for me to handle. How nice if Fitbit comes up with a version that can "recharge for itself". 

**In order for it to work:**
* First, the overall design should consume as little power as possible
* The design should incorporate a sub-system that can harness the energy around it: like light sources or kinetic energy (similar to some wrist watch designs)

## Besides power consumption, I can think of few more development challenges in the Fitbit design:
### Reliability:
Even the system does not need to be removed for recharge, it still needs to withstand common loads a typical wearable device would expect, mainly water exposure, and maybe cleaning agent exposure. 

### Memory space/program installation and upgrade:
The device needs to have enough memory space to store user data, assuming the user does not connect the device to the phone often. More importantly, the designer needs to be consider how about future upgrade of the software and memory space. 

### Debuggability:
The version of the Fitbit I am using have very simple UI, it only displays the time, date, and number of steps, that is it. However, it could pose some challenges during debugging phase because of the limit capability of its display. It would be even a bigger challenge to some of Fitbit’s early models which do not have display at all. One solution could be to have a custom-made APP “talking” to the unit through Bluetooth, where the APP can directly access and display the status and parameters of the unit.

### Security:
As more devices are connected, what security protocol the unit needs to implement to prevent unauthorized access of user data.
