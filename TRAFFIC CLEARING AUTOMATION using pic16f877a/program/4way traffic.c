#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=4MHz)
#define LCD_ENABLE_PIN PIN_D0
#define LCD_RS_PIN PIN_D1
#define LCD_RW_PIN PIN_D2
#define LCD_DATA4 PIN_D4
#define LCD_DATA5 PIN_D5
#define LCD_DATA6 PIN_D6
#define LCD_DATA7 PIN_D7

#include <lcd.c>
/**
ARTHUR : HARI
COPYRIGHTS : FREE 
WORKING : WHENEVER THE TRAFFIC HIGH ON SPECIFIC SIDE..
          NOTED BY THE SENSOR..
          CLEARS THE SIDE FIRST.. BACK TO NORMAL*/
int count=0,count1=0,count2=0,count3=0;
void inn(){
 output_B(0x00);
 output_c(0x00);
 output_e(0x00);
}
void led_r(){
output_high(pin_b0);
output_high(pin_c3);
output_high(pin_c1);
output_high(pin_e2);
delay_ms(3000);
inn();
output_high(pin_b1);
output_high(pin_c3);
output_high(pin_c2);
output_high(pin_e0);
delay_ms(3000);
inn();
output_high(pin_b2);
output_high(pin_c4);
output_high(pin_c0);
output_high(pin_e0);
delay_ms(3000);
inn();
output_high(pin_b0);
output_high(pin_c5);
output_high(pin_c0);
output_high(pin_e1);
delay_ms(3000);
}
void call1(){
inn();      
output_high(pin_b0);
output_high(pin_c3);
output_high(pin_c1);
output_high(pin_e2);
      count=0;
}
void call2(){
      
inn();
output_high(pin_b1);
output_high(pin_c3);
output_high(pin_c2);
output_high(pin_e0);
      count1=0;
          
}
void call3(){

inn();
output_high(pin_c0);
output_high(pin_e1);
output_high(pin_c3);
output_high(pin_b2);
      count2=0;
}      
void call4(){
      
inn();
output_high(pin_b0);
output_high(pin_c5);
output_high(pin_c0);
output_high(pin_e1);
      count3=0;
          
}
void main()
{

   lcd_init();
   output_B(0xff);
   output_c(0xff);
   output_e(0xff);
   delay_ms(1000);

   while(TRUE)
   {
      if(input(PIN_A0))
      {
     
      count=count+1;
      }
     
      if(input(PIN_A1))
      {
     
      count1=count1+1;
      }
     
      if(input(PIN_A2))
      {
      count2=count2+1;
      
      }
      if(input(PIN_A3))
      {
      count3=count3+1;
      }
      lcd_gotoxy(1,1);
              printf(lcd_putc,"Cn 1,2=%d,%d",count,count1);
              lcd_gotoxy(1,2);
              printf(lcd_putc,"Cn 3,4=%d,%d",count2,count3);
     
      if(count>count1&& count>count2 && count>count3)
      {
     call1();      
      }
      else if(count1>count&& count1>count2 && count1>count3)
      {
     call2();
      }
      else if(count2>count&& count2>count1 && count2>count3)
      {
     call3();
      }
      else if(count3>count&& count3>count2 && count3>count1)
      {
     call4();
      }
      else
      {
      inn();
      led_r();
      }
   }
   }




