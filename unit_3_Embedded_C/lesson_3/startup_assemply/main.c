#include "stdint.h"
#include "platform_types.h"

#define RCC_BASE        0x40021000
#define PortA_BASE      0x40010800
#define RCC_APB2ENR     *((volatile uint32_t *)(RCC_BASE + 0x18))
#define GPIO_CRH        *((volatile uint32_t *)(PortA_BASE + 0x4))
#define GPIO_ODR        *((volatile uint32_t *)(PortA_BASE + 0x0c))
#define RCC_IOPAEN      (1<<2)

typedef union
{
   uint32_t all_pins;
   struct
   {
      uint32_t      : 13;
      uint32_t P_13 : 1;
   }        Pins;
} R_ODR_t;


volatile const char name[] = "LEARN IN DEPTH";
volatile int x[100];
volatile R_ODR_t *R_ODR = (volatile R_ODR_t *)(PortA_BASE + 0x0C);


int main(void)
{
   RCC_APB2ENR |= RCC_IOPAEN;
   GPIO_CRH    &= 0xff0fffff; // reset imp bits 20-23 and maintaining the rest (calibration)
   GPIO_CRH    |= 0x00200000;
   while (1)
   {
      R_ODR->Pins.P_13 = 1;
      for (int i = 0; i < 50000; ++i);
      R_ODR->Pins.P_13 = 0;
      for (int i = 0; i < 50000; ++i);
   }
   return 0 ;
}