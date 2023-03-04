/*
 * garage.c
 *
 * Created: 3/2/2023 6:14:09 PM
 * Author : Mohamed Sameh
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include "timer.h"
#include "LCD.h"

#define IR1_PORT DIO_PORTC
#define IR1_PIN DIO_PIN0

#define IR2_PORT DIO_PORTC
#define IR2_PIN DIO_PIN1


int main(void)
{
	dio_set_pin_direction(IR1_PORT,IR1_PIN,DIO_DIRECTION_INPUT);
	dio_set_pin_direction(IR2_PORT,IR2_PIN,DIO_DIRECTION_INPUT);
	LCD_init();
	LCD_move_curser(4,0);
	LCD_send_string("0 Cars");
	LCD_move_curser(0,1);
	LCD_send_string("Garage has space");
	char counter = 0,flag1 = 0,flag2 = 0;
	
    while (1) 
    {
		if (dio_get_pin(IR2_PORT,IR2_PIN) ==  DIO_LEVEL_HIGH && counter < 3 && flag1 == 0)
		{
			counter++;
			LCD_move_curser(4,0);
			//ASCII code for char "0" is 48
			LCD_send_char(counter+48);
			flag1 = 1;
			if (counter == 3)
			{
				LCD_clearscreen();
				LCD_move_curser(1,0);
				LCD_send_string("Garage is full");	
			}
			
			timer1_fastPWM_A(.999);
 			_delay_ms(500);
			timer1_fastPWM_A(1.499999);
 		}else if (dio_get_pin(IR2_PORT,IR2_PIN) ==  DIO_LEVEL_LOW)
 		{
			 flag1 = 0;
 		}
		 
		 if (dio_get_pin(IR1_PORT,IR1_PIN) ==  DIO_LEVEL_HIGH && counter > 0 && flag2 == 0)
		 {
			 counter--;
			 LCD_clearscreen();
			 LCD_move_curser(4,0);
			 LCD_send_char(counter+48);
			 LCD_move_curser(6,0);
			 LCD_send_string("Cars");
			 LCD_move_curser(0,1);
			 LCD_send_string("Garage has space");
			
			flag2 = 1;
			timer1_fastPWM_B(.999);
			_delay_ms(500);
			timer1_fastPWM_B(1.499999);
			
		 }else if (dio_get_pin(IR1_PORT,IR1_PIN) ==  DIO_LEVEL_LOW)
		 {
			 flag2 = 0;
		 }
	
    }
}

