#include <16F877A.h>
#device ADC=16
#FUSES NOWDT                    //No Watch Dog Timer
#FUSES PUT                      //Power Up Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#use delay(crystal=4MHz)
#use i2c(Master,Fast,sda=PIN_C4,scl=PIN_C3)
#define LCD_ENABLE_PIN PIN_D2
#define LCD_RS_PIN PIN_D0
#define LCD_RW_PIN PIN_D1
#define LCD_DATA4 PIN_D4
#define LCD_DATA5 PIN_D5
#define LCD_DATA6 PIN_D6
#define LCD_DATA7 PIN_D7

#include <lcd.c>
byte sec=0x00, min=0x00, hr=0x06;
byte read(byte address){
   byte a;
   i2c_start();
   i2c_write(0xd0);
   i2c_write(address);
   i2c_stop();
   i2c_start();
   i2c_write(0xd1);
   a = i2c_read(0);
   i2c_stop();
   return a;
}
void write(byte address,byte data){
   i2c_start();
   i2c_write(0xd0);
   i2c_write(address);
   i2c_write(data);
   i2c_stop();
}
void main()
{  lcd_init();
   write(0x00,sec);
   write(0x01,min);
   write(0x02,hr);
   int c=5,flag=0;
   while(TRUE)
   {  
      //TODO: User Code
     lcd_gotoxy(1,1);
     printf(lcd_putc,"%x-%x-%x",read(0x02),read(0x01),read(0x00));
     int h=read(0x00);
     if (h==0x05){output_high(pin_b0);
                  flag=1;}

                if(c==10 || input(pin_a0)==0){
                c=0;flag=0;
                output_low(pin_b0);
                }
                else if(flag==1){
                c++;
                }
                
     lcd_gotoxy(1,2);
      printf(lcd_putc,"%x-%x-%x",read(0x04),read(0x05),read(0x06));
     delay_ms(1000);
   }

}
