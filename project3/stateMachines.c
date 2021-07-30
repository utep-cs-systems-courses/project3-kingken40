#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "../lcdLib/lcdutils.h"
#include "../lcdLib/lcddraw.h"

void state_advance(){

  
  if(state == 1){
    clearScreen(COLOR_GREEN);
    shape_red();
   
  }
  else if(state == 2){ 
    shape_blue();
  }
  else if(state == 3){ 
    shape_white();
  }
  else if(state == 4){ 
  }
}
