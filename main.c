/************************************************
 * Author: Nikos Monios                         *
 *                                              *
 * You are free to use this code for your class *
 * projects.                                    *
 *                                              *
 * You can try this code yourself, play with    *
 * the values assigned to CCR1 & CCR2. You can  *
 * also add more complex logic. I just created  *
 * an eternal loop that will toggle the PWMs    *
 * between two values.                          *
 *                                              *
 * The code works perfectly with both TI CCS    *
 * and Energia IDEs.                            *
 *                                              *
 * Happy Tinkering    :)                        *
 * *********************************************/
 
#include <msp430.h>

#define one 1000000

void init(void);
void wait_a_bit(void);

int main (void)
{
  init();
  // Init clock abd PWMs
  
  while(1) //do forever
  {
    wait_a_bit();
    /* wait for a few seconds */
    TA1CCR1 = 256; // P2.1 to 50%
    TA1CCR2 = 1;  // P2.4 to 0%
    wait_a_bit();
    /* wait for a few  seconds */
    TA1CCR1 = 512; // P2.1 to 100%
    TA1CCR2 = 512; // P2.4 to 100%
  }
}

void init(void)
{
  WDTCTL = WDTPW + WDTHOLD; // Stop WDT
  P2DIR |= BIT1 + BIT4;  // P2.1 and P2.4 output
  P2SEL |= BIT1 + BIT4; // P2.1 and P2.4 TA1/2 options
  P2OUT &= 0x00; // Set P2.1 and P2.4 to off
  TA1CCR0 = 512-1;  // PWM Period
  TA1CCTL1 = OUTMOD_7; // CCR1 reset/set
  TA1CCR1 = 1; // CCR1 PWM duty cycle on P2.1 (0%) 
  TA1CCTL2 = OUTMOD_7;
  TA1CCR2 = 256; // CCR1 PWM duty cycle on P2.4 (50%)
  TA1CTL = TASSEL_2 + MC_1; // SMCLK, up mode
}

void wait_a_bit(void) // 3 seconds delay
{
  unsigned int i = 0;
  for(i = 0; i <= 3; i++)
  {
      __delay_cycles(one); 
      i++;
  }
}