# msp430_2_pwm_outputs
2 PWM outputs with different frequency, with an MSP430G2 launchpad



Here is a simple code to produce two PWM outputs on an MSP430G2 launchpad.

You can change the values of registers TA1CCR1 & TA1CCR2 to get different
duty cycles. A register value close to 1 means low duty cycle while a 
register value close to 512 means a duty cycle close to 100%.

The next step after this code is to change the registers using interrupts,
for example when a button is pressed then the duty cyclegoes to 100% and 
when you release it, the duty cycle drops to 50% etc.


Feel free to use this code for your projects, and do not hesitate to contact
me if you have any questions or comments.


Nikos Monios
