#include <16F877A.h>
#device ADC=10

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES PUT                      //Power Up Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=4MHz)

void main()
{
   int done=0;
   long int end=0;
   setup_adc_ports(AN0);
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_ccp2(CCP_PWM);
   while(TRUE)
   
   {
    set_adc_channel(0); //channel set
    while(!done)  //start of conversion
    {
    done= adc_done();
    }
    end =  read_adc(); // end of coversion

       set_pwm2_duty(end);
       delay_ms(500); 
   }

}



