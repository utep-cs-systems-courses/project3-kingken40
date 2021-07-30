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
  switch_init();
  lcd_init();
 
  
  enableWDTInterrupts();/* enable periodic interrupt */
  or_sr(0x8);/* GIE on */
  

  P1DIR |= LED;
  P1OUT |= LED;

  while(1){
    if(redrawScreen){
      redrawScreen = 0;
      my_shape();
      clearScreen(COLOR_YELLOW);
      
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
  }
}
