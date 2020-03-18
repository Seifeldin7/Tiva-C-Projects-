#include "btn.h"

void BTN_init(void)
{
  SYSCTL_RCGCGPIO_R  |=  (1<<5);
  GPIO_PORTF_DEN_R   |=   (1<<0) | (1<<4) | (1 << 1);
  GPIO_PORTF_DIR_R   &= ~(1<<4);
  GPIO_PORTF_DIR_R   &= ~(1<<0);
  GPIO_PORTF_DIR_R   |= (1<<1);
  GPIO_PORTF_LOCK_R = 0x4c4f434b;
  GPIO_PORTF_CR_R = 0x01f;
  GPIO_PORTF_PUR_R |= (1<<4) | (1<<0);
}

bool BTN_isPressed(unsigned char btn)
{
  return (!(GPIO_PORTF_DATA_R & (1<<btn)));
}
