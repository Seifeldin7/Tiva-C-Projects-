#include "keypad.h"
const unsigned int keymap[4][4] = 
{
  { 1, 2, 3, 'A'},
  { 4, 5, 6, 'B'},
  { 7, 8, 9, 'C'},
  { '*', 0, '#', 'D'},
};

void KEYPAD_init(void)
{
    SYSCTL_RCGCGPIO_R    |=  (1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5);
    GPIO_PORTC_DEN_R     |=  0xFF;
    GPIO_PORTE_DEN_R     |=  0xFF;
    GPIO_PORTC_DIR_R      =  0x00;
    GPIO_PORTE_ODR_R     |=  (1<<0) | (1<<1) | (1<<2) | (1<<3);
    GPIO_PORTC_PUR_R     |=  (1<<4) | (1<<5) | (1<<6) | (1<<7);

}
unsigned int KEYPAD_getNumPressed(void)
{
  int col,row;
  while(1)
  {
  for(col=0;col<4;col++)
  {
        GPIO_PORTE_DIR_R  = (0x01<<col);
        KEYPAD_PORT_OUT = (~(1<<col));
      for(row=0;row<4;row++)
      {
        if(!(KEYPAD_PORT_IN & ((0x10)<<row)))
        {
          return keymap[row][col];
        }
      
      }   
   }
  }
}