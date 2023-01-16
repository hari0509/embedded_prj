#include <16F877A.h>
#device ADC=10

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES PUT                      //Power Up Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=4MHz)

void main()
{
   setup_adc_ports(ALL_ANALOG);
   setup_adc(ADC_CLOCK_INTERNAL);
   int EOC =0;
   long int  value=0;
   while(TRUE)
   {
      //TODO: User Code
      SET_ADC_CHANNEL(0);
      WHILE(!EOC)
      {      EOC =adc_done();    }
      value = read_adc();
      if(value <= 2){
      output_high(pin_b0);
      }
      else output_low(pin_b0);

}
}

