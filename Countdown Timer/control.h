#include "tm4c123gh6pm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "keypad.h"
#include "lcd.h"
#include "systick.h"
#include "btn.h"


unsigned int take_input();
void count_down(unsigned int result);