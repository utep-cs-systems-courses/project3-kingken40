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


int main(void) {
  configureClocks();/* setup master oscillator, CPU & peripheral clocks */

  led_init();
  //buzzer_init();
  switch_init();
  lcd_init();
 
  
  enableWDTInterrupts();/* enable periodic interrupt */
  or_sr(0x8);/* GIE on */
  

  P1DIR |= LED;
  P1OUT |= LED;
  //Reset redrawScreen after 125 interrupts, Draws the shape 
  while(1){ //  always true, if redraw is 0, screen is still clear, LED OFF, CPU OFF
    // after 125 interrupts, redraw is true hen resets. and shape is drawn
    if(redrawScreen){
      redrawScreen = 0;
      my_shape();
      // clearing shape once shape is drawn, comment to leave shape solid on screen
      // LED indicating cpu will sleep when clearing screen.
      // LED illuminates once redraw is true and screen is drawing
      clearScreen(COLOR_GREEN); 
    }
    P1OUT &= ~LED; //LED OFF
    or_sr(0x10); //CPU OFF
    P1OUT |= LED; //LED ON
  }
}
// redraws the screen at 125 interrupts, resets count after interrrupt occurs
void wdt_c_handler() {
  static int secCount = 0;
  secCount ++;
  if (secCount == 125) {
    redrawScreen = 1;
    secCount = 0;
  }
}
