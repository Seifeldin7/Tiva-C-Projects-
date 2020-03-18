#include "tm4c123gh6pm.h"
#include "stdbool.h"

#define KEYPAD_PORT_OUT GPIO_PORTE_DATA_R //D
#define KEYPAD_PORT_IN GPIO_PORTC_DATA_R //c

void KEYPAD_init(void);
unsigned int KEYPAD_getNumPressed(void);