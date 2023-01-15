#include <16F877A.h>
#device ADC=16
#FUSES NOWDT                    //No Watch Dog Timer
#FUSES PUT                      //Power Up Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
int h=0x01;
#use delay(crystal=4MHz)
#INT_TIMER1
void  TIMER1_isr(void) 
{  if (input(pin_a0) ==1){
   rotate_right( &h, 1);
   output_b(h);}
   else{
   rotate_left( &h, 1);
   output_b(h); }
   clear_interrupt(INT_TIMER1);
}
void main()
{  setup_timer_1(T1_INTERNAL|T1_DIV_BY_2);      //131 ms overflow
   enable_interrupts(INT_TIMER1);
   enable_interrupts(GLOBAL);
   while(TRUE)
   {
      //TODO: User Code
      
   }

}
