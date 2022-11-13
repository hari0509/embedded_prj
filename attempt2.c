#include <16F877A.h>
#device ADC=10

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES PUT                      //Power Up Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20000000)
#include <lcd.c>
/////////////////////////////////////
void pwm(int16 x){
   output_high(pin_c2);
   delay_us((int16)x);
   output_low(pin_c2);
   delay_us((int16)20000-x);
   delay_ms(1000);
}
void main(){
   lcd_init();
   long int  ldr1,ldr2=0 ;
   int EC=0;int16 i=1150;
   setup_adc_ports(AN0_AN1_AN3);
   setup_adc(ADC_CLOCK_INTERNAL);
   output_b(0X00);
   output_high(pin_b0);
   pwm(1500);
  while(TRUE)
   {  output_high(pin_b2);
      delay_ms(2000);
      SET_ADC_CHANNEL(0);
      WHILE(!EC)
      { EC =adc_done(); } ldr1 = read_adc();
      SET_ADC_CHANNEL(1);
      WHILE(!EC)
      { EC =adc_done(); }
      ldr2 = read_adc(); //ldr2
      if (ldr1==0 || ldr2==0) {break;}
      output_low(pin_b2);
      if (i> 1900) {i=1150;}
      if (ldr2 > ldr1)
      {  output_high(pin_b3);
         pwm(i);
         i=i+60;  }
      else if(ldr1==ldr2 || ldr1>ldr2)   
      {  output_low(pin_b3);
         continue;   }
}
   while(ldr1==0 || ldr2==0){
     output_high(pin_b1);}   
}
