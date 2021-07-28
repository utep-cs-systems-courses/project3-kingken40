//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
short redrawscreen = 1;

int main(void) {
  configureClocks();/* setup master oscillator, CPU & peripheral clocks */
  led_init();
  buzzer_init();
  buzzer_set_period(0);
  switch_init();
  enableWDTInterrupts();/* enable periodic interrupt */

  or_sr(0x18);/* CPU off, GIE on */
}

void wdt_c_handler()
{
  static int secCount = 0;

  secCount ++;
  if (secCount >= 25) {/* 10/sec */
    secCount = 0;
    redrawScreen = 1;
  }
}

