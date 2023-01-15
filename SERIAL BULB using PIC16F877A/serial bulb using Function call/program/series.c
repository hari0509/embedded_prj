#include <16F877A.h>
#device ADC=16
#FUSES NOWDT                    //No Watch Dog Timer
#FUSES PUT                      //Power Up Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
int h=0x01;
#use delay(crystal=4MHz)
void timer3(void){
for(int i=0;i<8;i++){
output_b(0xff);
delay_ms(100);
output_b(0x00);
delay_ms(100);
}
}
void  timer1(void) 
{ 
   for(int i=0;i<8;i++)
   {
   rotate_right( &h, 1);
   output_b(h);
   delay_ms(200);
   }   
}
void  timer2(void) 
{ 
   for(int i=0;i<8;i++)
   {
   rotate_left( &h, 1);
   output_b(h);
   delay_ms(200);
   }
    
}
void  timer4(void) 
{  int j=0x11;
   for(int i=0;i<8;i++)
   {
   rotate_left( &j, 1);
   output_b(j);
   delay_ms(200);
   } 
   for(i=0;i<8;i++)
   {
   rotate_right( &j, 1);
   output_b(j);
   delay_ms(200);
   }
}
void main()
{  
   while(TRUE)
   {
      //TODO: User Code
      timer1();
      delay_ms(200);
      timer2();
      delay_ms(200);
      timer3();
      delay_ms(200);
      timer4();
      delay_ms(200);
   }

}

