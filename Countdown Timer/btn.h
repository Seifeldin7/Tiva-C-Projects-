#include "tm4c123gh6pm.h"
#include "stdbool.h"

#define DF GPIO_PORTF_DATA_R
void BTN_init(void);
bool BTN_isPressed(unsigned char btn);
