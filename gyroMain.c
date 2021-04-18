#include <16f887.h>
#fuses INTRC_IO
#use delay(clock=4MHZ)

#use I2C(master, sda=PIN_d0, scl=PIN_c3, slow)  //You can change, according your board ports
#include <adxl345.h>

#include "math.h"
int8  A_data[2]; //6 units 8 bit Accel datas
int16 Ya=0;

#define VELOCIDADE 10

void anti_horario(){
        output_high(PIN_D7); output_high(PIN_D6);
        output_low(PIN_D5); output_low(PIN_D4);
        delay_ms(VELOCIDADE);
        
        output_high(PIN_D5); output_high(PIN_D6);
        output_low(PIN_D7); output_low(PIN_D4);
        delay_ms(VELOCIDADE);
        
        output_high(PIN_D5); output_high(PIN_D4);
        output_low(PIN_D7); output_low(PIN_D6);
        delay_ms(VELOCIDADE);     
        
        output_high(PIN_D7); output_high(PIN_D4);
        output_low(PIN_D5); output_low(PIN_D6);
        delay_ms(VELOCIDADE);  
}
void horario(){
        output_high(PIN_D7); output_high(PIN_D6);
        output_low(PIN_D5); output_low(PIN_D4);
        delay_ms(VELOCIDADE);   
        
        output_high(PIN_D7); output_high(PIN_D5);
        output_low(PIN_D4); output_low(PIN_D6);
        delay_ms(VELOCIDADE);      

        output_high(PIN_D5); output_high(PIN_D4);
        output_low(PIN_D7); output_low(PIN_D6);
        delay_ms(VELOCIDADE);  
        
        output_high(PIN_D6); output_high(PIN_D4);
        output_low(PIN_D7); output_low(PIN_D5);
        delay_ms(VELOCIDADE);  
}

void main(){
   delay_ms(2);
   adxl345_init();    
   
      while(TRUE)
      {
         A_data[0]=adxl345_read(0x34); //Read Y axis(LSB)
         A_data[1]=adxl345_read(0x35); //Read Y axis(MSB)
      
         //Converting two 8 bit integer to one 16 bit integer
         Ya=make16(A_data[1],A_data[0]);
         Ya = Ya + 130;
          
         if(Ya > 160){
            horario();

         }
         if(Ya < 130){
            anti_horario();
         }        
       }
}

