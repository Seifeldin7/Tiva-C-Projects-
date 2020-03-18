#include "control.h"


unsigned int take_input(){
  LCD_displayString("ENTER NUMBER\n");
  unsigned int result,midres = 0;
  unsigned int  num;
  for(int i=0;i< 4;i++){
    num  = KEYPAD_getNumPressed();
    LCD_clearScreen();
    if(num != '*'){
      result *= 10;
      result += num; 
      if(i == 3){
       LCD_displayInt(result/100);
        LCD_displayInt(result&100);
      }
      else{
        LCD_displayInt(result/100);
        LCD_displayInt(result%100);
      }
  
      
      delayMs(5000);
    }
    else{
      break;
    }
  }
  LCD_clearScreen(); 
  LCD_displayInt(result/100);
  LCD_displayInt(result%100);
  LCD_displayString(".00");
  delayMs(500);
  return result;

}
void count_down(unsigned int result){
  int seta = 1;
  while(seta){
    if(BTN_isPressed(4))
    {
      while(result !=0 && seta != 0)
      {
        result--;
        for(int i=99; i>=0;i--){
          if(BTN_isPressed(0)){ 
            seta = 0;
            LCD_clearScreen(); 
            LCD_displayString("COUNTDOWN ENDED");
            DF |= 0x02;
            int counter = 0;
            while(counter++ < 5){ delayS();}
            DF &= ~0x02;
            break;
          }
          LCD_clearScreen(); 
          LCD_displayInt(result/100);
          LCD_displayInt(result%100);
          LCD_displayString(".");
          LCD_displayInt(i);
          delayMs(10);
        }

    }
        seta = 0;
        LCD_clearScreen(); 
        LCD_displayString("COUNTDOWN ENDED");
        DF |= 0x02;
        int counter = 0;
        while(counter++ < 5){ delayS();}
        DF &= ~0x02;
        LCD_clearScreen(); 
  } 
}
}