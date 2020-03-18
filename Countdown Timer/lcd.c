#include "lcd.h"


char* itoa(int val, int base){
	
	static char buf[32] = {0};
	
	int i = 30;
	
	for(; val && i ; --i, val /= base)
	
		buf[i] = "0123456789abcdef"[val % base];
	
	return &buf[i+1];
	
}
void LCD_init(void)
{
        SYSCTL_RCGCGPIO_R  |=   (1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5);
        GPIO_PORTB_DEN_R  = 0xFF;
        GPIO_PORTE_DEN_R |=(1<<4)|(1<<5);
        LCD_DATA_PORT_DIR = 0xFF; 
	LCD_CTRL_PORT_DIR |= (1<<E) | (1<<RS) ; 
	
        delayMs(20); 
        LCD_sendCommand(WAKE_UP); 
        delayMs(5);
        LCD_sendCommand(WAKE_UP); 
        delayUs(100); 
        LCD_sendCommand(WAKE_UP); 
         delayUs(100);

	LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE); 
                
	LCD_sendCommand(CURSOR_RIGHT); 
	
	LCD_sendCommand(CLEAR_COMMAND); 
        
        LCD_sendCommand(TURN_ON_DISPLAY); 

}
void LCD_sendCommand(unsigned char command)
{
     LCD_CTRL_PORT = 0;
     LCD_DATA_PORT = command;
     LCD_CTRL_PORT =  (1<<E); 
     delayUs(1);
     LCD_CTRL_PORT = 0;
     if (command < 4)
        delayMs(2);     	/* command 1 and 2 needs up to 1.64ms */
     else
        delayUs(40);
}
void LCD_data(unsigned char command)
{
        LCD_CTRL_PORT =  (1<<RS); 
        //LCD_CTRL_PORT &= ~(1<<RW); 
        LCD_DATA_PORT = command; 
        LCD_CTRL_PORT |=  (1<<E); 
	delayUs(1);
        LCD_CTRL_PORT = 0;
        delayUs(40);
  
}
void LCD_displayString( char *Str)
{
	unsigned char i = 0;
	while(Str[i] != '\0')
	{
		LCD_data(Str[i]);
		i++;
	}
	
}
void LCD_displayInt(unsigned char num)
{
   char *buff; /* String to hold the ascii result */
   buff = itoa(num,10); /* 10 for decimal */
  
   LCD_displayString(buff);
}
void LCD_clearScreen(void)
{
    LCD_sendCommand(CLEAR_COMMAND); 
}