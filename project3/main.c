//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "../lcdLib/lcdutils.h" 
#include "../lcdLib/lcddraw.h"

#define LED BIT6
short redrawScreen = 1;
char state1 = 1;

int main(void) {
  configureClocks();/* setup master oscillator, CPU & peripheral clocks */
  led_init();
  buzzer_init();
  buzzer_set_period(0);
  switch_init();
  enableWDTInterrupts();/* enable periodic interrupt */
  or_sr(0x8);/* GIE on */
  clearScreen(COLOR_RED);

  P1DIR |= LED;
  P1OUT |= LED;

  while(1){
    if(redrawScreen){
      redrawScreen = 0;
      // my_shape(COLOR_BLUE);
      clearScreen(COLOR_GREEN);
      // or_sr(8); // Enabling GIE
    }
    P1OUT &= ~LED; //LED OFF
    or_sr(0x10); //CPU OFF
    P1OUT |= LED; //LED ON
  }
}

void wdt_c_handler() {

  static int secCount = 0;
  secCount ++;
  if (secCount == 75) {
    redrawScreen = 1;
    secCount = 0;
    switch(state1) {
    case 1: shape_red();
            state1++;
	    break;
    case 2: shape_blue();
            state1++;
	    break;
    case 3: shape_white();
            state1++;
	    break;
    default: state1 = 1;
             break;
    }
  }
}
