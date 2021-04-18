#include <16f887.h>
#fuses INTRC_IO
#use delay(clock=4MHZ)

#define VELOCIDADE 10

void main(){
 
    while(1){
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
   }

