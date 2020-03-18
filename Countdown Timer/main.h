#include "tm4c123gh6pm.h"
#include "stdio.h"
#include "stdlib.h"
#include "keypad.h"
#include "lcd.h"
#include "systick.h"
#include "btn.h"
#include "control.h"

#define DA GPIO_PORTA_DATA_R
#define DB GPIO_PORTB_DATA_R
#define DD GPIO_PORTD_DATA_R
#define DE GPIO_PORTE_DATA_R

#define ZERO 0xC0
#define ONE  0xF9
#define TWO  0xA4
#define THREE 0xB0
#define FOUR 0x99
#define FIVE 0x92
#define SIX  0x82
#define SEVEN 0xF8
#define EIGHT 0x80
#define NINE 0x90
#define HEXA 0x88
#define HEXB 0x83
#define HEXC 0xC6
#define HEXD 0xA1
#define HEXE 0x86
#define HEXF 0x8E


void init();
