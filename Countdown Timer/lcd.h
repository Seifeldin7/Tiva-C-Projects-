#include "tm4c123gh6pm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "systick.h"

#define RS 3
#define RW 1
#define E  2
#define LCD_CTRL_PORT GPIO_PORTD_DATA_R
#define LCD_CTRL_PORT_DIR GPIO_PORTD_DIR_R

#define LCD_DATA_PORT GPIO_PORTB_DATA_R
#define LCD_DATA_PORT_DIR GPIO_PORTB_DIR_R

#define CLEAR_COMMAND 0x01
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80 
#define TURN_ON_DISPLAY 0x0F
#define CURSOR_RIGHT 0x06
#define WAKE_UP 0x30

void LCD_init(void);
void LCD_sendCommand(unsigned char command);
void LCD_data(unsigned char data);
void LCD_displayString( char *Str);
void LCD_clearScreen(void);
void delay(void);
void LCD_displayInt(unsigned char num);
char* itoa(int val, int base);