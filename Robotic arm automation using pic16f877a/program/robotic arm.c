#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES PUT                      //Power Up Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=4MHz)
void down(){
for(int i=0;i<5;i++){
output_high(pin_b0);
delay_us(1000);
output_low(pin_b0);
delay_us(19000); }
}
void mid(){
for(int i=0;i<5;i++){
output_high(pin_b0);
delay_us(1500);
output_low(pin_b0);
delay_us(18500);  }
}
void up(){
for(int i=0;i<5;i++){
output_high(pin_b0);
delay_us(2000);
output_low(pin_b0);
delay_us(18000);}
}
void main()
{
   while(1)
   {
      //TODO: User Code
      down(); //-90 degree
      delay_ms(1000);
      mid();   // +0 degree
      delay_ms(1000);
      up(); //+90 degree
      delay_ms(1000);
   }

}

