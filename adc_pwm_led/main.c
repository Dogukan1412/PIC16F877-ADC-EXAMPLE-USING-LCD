#include <main.h>
#include "lcd.c"

unsigned long int bilgi;
float power;
int duty = 0;

void main()
{
   set_tris_a(0x01);
   set_tris_d(0x00);
   set_tris_c(0x00);
   
   setup_adc(adc_clock_div_32);
   setup_adc_ports(all_analog);
   set_adc_channel(0);
   
   setup_timer_2(t2_div_by_16,249,1);
   setup_ccp1(ccp_pwm);
   set_pwm1_duty(duty);
   
   lcd_init();
   
   delay_us(30);
   
   while(TRUE)
   {
      bilgi = read_adc();
      lcd_gotoxy(1,1);
      printf ( lcd_putc , " ADC = %ld",bilgi);
      power = (float)(0.0015258789*bilgi);
      lcd_gotoxy(1,2);
      printf ( lcd_putc , "LED_Power= %f",power);
      //duty = (power/10);
      set_pwm1_duty(power); 

      
   }

}
