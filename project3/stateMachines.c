#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "../lcdLib/lcdutils.h"
#include "../lcdLib/lcddraw.h"
// Checks what state it is in, clears screen and changes shape to color
void state_advance(){

  
  if(state == 1){
    clearScreen(COLOR_GREEN);
    shape_red();
   
  }
  else if(state == 2){
    clearScreen(COLOR_GREEN);
    shape_blue();
  }
  else if(state == 3){
    clearScreen(COLOR_GREEN);
    shape_white();
  }
  else if(state == 4){
    clearScreen(COLOR_GREEN);
    shape_yellow();
  }
}
