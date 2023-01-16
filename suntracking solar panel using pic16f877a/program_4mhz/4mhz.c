#include <16F877A.h>
#device ADC=10

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES PUT                      //Power Up Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=4000000)
#include <lcd.c>
/////////////////////////////////////
void main(){
   lcd_init();
   long int  ldr1,ldr2=0 ;
   int EC=0;int16 i=270;
   setup_adc_ports(AN0_AN1_AN3);
   setup_adc(ADC_CLOCK_INTERNAL);
   output_b(0X00);
   output_high(pin_b0);
   setup_ccp1(CCP_PWM);
   set_pwm1_duty((int16)290);
   setup_timer_2(T2_DIV_BY_16,255,1);
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
      delay_ms(2000);
      if (i> 470) {i=290;}
      if (ldr2 > ldr1)
      {  output_high(pin_b3);
         set_pwm1_duty((int16)i);
         i=i+10;  }
      else if(ldr1==ldr2 || ldr1>ldr2)   
      {  output_low(pin_b3);
         continue;   }
}
   while(1){
   output_high(pin_b1);}
   
}
