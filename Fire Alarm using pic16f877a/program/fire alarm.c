#include <16F877A.h>
#device ADC=10

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES PUT                      //Power Up Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=4MHz)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,stream=PORT1,errors)

void main()
{
int enter= 0x0D , ctrl = 0x1A, EOC=0;
long int temperature=0;
setup_adc_ports(AN0_AN1_AN3);
setup_adc(ADC_CLOCK_INTERNAL);
int flag=0;
while(TRUE)
{
    SET_ADC_CHANNEL(0);
      
      WHILE(EOC)
      {     EOC =adc_done();     }
      temperature = read_adc();
      temperature= temperature * 0.488;

if(temperature>35 && flag == 0)
{     flag = 1;
      printf("AT");
      printf("%c",enter);
      delay_ms(200);
      printf("AT+CMGF=1");
      printf("%c",enter);
      delay_ms(200);
      printf("AT+CMGS=\"1234567890\"");
      printf("%c",enter);
      delay_ms(200);
      printf("\rFIRE!! FIRE!!!");
      printf("%c",ctrl);
      delay_ms(2000);   
}
if(temperature>33)
   output_high(pin_b0);
else
   output_low(pin_b0);
}    

   }
