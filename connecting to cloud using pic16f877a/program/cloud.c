#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES PUT                      //Power Up Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=4MHz)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,stream=PORT1,errors)


void main()
{

port_b_pullups(TRUE);
int j=0;
int enter= 0x0D;
   
   while(TRUE)
   {
 ///////////////////////////////  
   if(input(pin_b0)==0) //used as sensor
   {                    //noting down sensor value
      while(input(pin_b0)==0);
      j++; }
///////////////////////////////////
   if(input(pin_b1)==0)  //send data to cloud
   {  
      while(input(pin_b1)==0);
      printf("AT");
      printf("%c",enter);
      delay_ms(200);
      
      printf("AT+CGDCONT=1,\"IP\","",\"0.0.0.0\",0,0");
      printf("%c",enter);
      delay_ms(200);
      
      printf("AT+CGATT=0");
      printf("%c",enter);
      delay_ms(200);
      
      printf("AT+CGATT=1");
      printf("%c",enter);
      delay_ms(2000);
      
      printf("AT+CGACT=1,1");
      printf("%c",enter);
      delay_ms(200);
      
      printf("AT+CGPADDR=1");
      printf("%c",enter);
      delay_ms(200);
      
      printf("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");
      printf("%c",enter);
      delay_ms(200);
      
      printf("AT+SAPBR=3,1,\"APN\",\"www\"");
      printf("%c",enter);
      delay_ms(200);
      
      printf("AT+SAPBR=0,1");
      printf("%c",enter);
      delay_ms(200);
      
      printf("AT+SAPBR=1,1");
      printf("%c",enter);
      delay_ms(2000);
 
      printf("AT+SAPBR=2,1");
      printf("%c",enter);
      delay_ms(200);
      
      printf("AT+HTTPTERM");
      printf("%c",enter);
      delay_ms(200);
      
      printf("AT+HTTPTERM");
      printf("%c",enter);
      delay_ms(200);
      
      printf("AT+HTTPINIT");
      printf("%c",enter);
      delay_ms(200);
      
      printf("AT+HTTPSSL=1");
      printf("%c",enter);
      delay_ms(200);
      
      printf("AT+HTTPPARA=\"CID\",1");
      printf("%c",enter);
      delay_ms(200);
      
      printf("AT+HTTPPARA=\"URL\",\"https://api.thingspeak.com/update?");
      printf("api_key=PQ7N8OBPXJT5Q512&field2=count:%d\"",j);
      printf("%c",enter);
      delay_ms(200);
      
      printf("AT+HTTPACTION=0");
      printf("%c",enter);
      delay_ms(10000);     
   }
   }
}
