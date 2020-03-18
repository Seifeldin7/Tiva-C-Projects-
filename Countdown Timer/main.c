#include "main.h"

int main()
{
  unsigned int result ;
  init();
  while(1){
    result = take_input();
    count_down(result);
  }
}

void init(){
  KEYPAD_init();
  LCD_init();
  BTN_init();
}
