#include <16f887.h>
#fuses INTRC_IO
#use delay(clock=4MHZ)
#include <C_LCD.h>

#use I2C(master, sda=PIN_d0, scl=PIN_c3, slow)  //You can change, according your board ports
#include <adxl345.h>


#include "math.h"
int8  A_data[6]; //6 units 8 bit Accel datas
int16 Xa=0,Ya=0,Za=0;

#define VELOCIDADE 10

void bem_vindo(){
   lcd_putc('\f'); 
   lcd_gotoxy(1,1); 
   printf(lcd_putc,"   Bem vindo"); 
   delay_ms(700);
   lcd_putc('\f'); 
}

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

void main(){
   delay_ms(2);
   lcd_init();
   bem_vindo();
   adxl345_init();    
     
   printf(lcd_putc,"\f");
   lcd_gotoxy(1,1);
   printf(lcd_putc,"    ADXL345     ");
   lcd_gotoxy(1,2);
   printf(lcd_putc," Accelerometer  ");
   delay_ms(1000);
   printf(lcd_putc,"\f");
   
      while(TRUE)
      {
         A_data[0]=adxl345_read(0x32); //Read X axis(LSB)
         A_data[1]=adxl345_read(0x33); //Read X axis(MSB)
         A_data[2]=adxl345_read(0x34); //Read Y axis(LSB)
         A_data[3]=adxl345_read(0x35); //Read Y axis(MSB)
         A_data[4]=adxl345_read(0x36); //Read Z axis(LSB)
         A_data[5]=adxl345_read(0x37); //Read Z axis(MSB)
      
         Xa=make16(A_data[1],A_data[0]);//Converting two 8 bit integer to one 16 bit integer
         Ya=make16(A_data[3],A_data[2]);
         Za=make16(A_data[5],A_data[4]);
        
         float Heading = atan2((signed int16)Ya,(signed int16)Xa)* 180 / pi + 180;      
              
         lcd_gotoxy(1,1);
         printf(lcd_putc,"X=%ld  ",Xa);
         lcd_gotoxy(9,1);
         printf(lcd_putc,"Y=%ld  ",Ya);
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Z=%ld  ",Za);
         lcd_gotoxy(9,2);
         printf(lcd_putc,"H=%f  ",Heading);                   
         
         if(Ya > 150){
            anti_horario();
         }
         
         }
}

