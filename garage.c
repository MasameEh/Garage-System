/*
 * garage.c
 *
 * Created: 3/2/2023 6:14:09 PM
 * Author : Mohamed Sameh
 */ 

#include "garage.h"


int main(void)
{
	dio_set_pin_direction(IR1_PORT, IR1_PIN, DIO_DIRECTION_INPUT);
	dio_set_pin_direction(IR2_PORT, IR2_PIN, DIO_DIRECTION_INPUT);
	LCD_init();
	LCD_move_cursor(4,0);
	LCD_send_string("0 Cars");
	LCD_move_cursor(0,1);
	LCD_send_string("Garage has space");
	uint8 counter = 0,flag1 = 0,flag2 = 0;
	
    while (1) 
    {
		//enter
		if (dio_get_pin(IR2_PORT, IR2_PIN) ==  DIO_LEVEL_HIGH && counter < 3 && flag1 == 0)
		{
			counter++;
			LCD_move_cursor(4,0);
			//ASCII code for char "0" is 48
			LCD_send_char(counter+48);
			flag1 = 1;
			if (counter == 3)
			{
				LCD_clearscreen();
				LCD_move_cursor(1,0);
				LCD_send_string("Garage is full");	
			}
			
			timer1_fastPWM_A(.999);
 			_delay_ms(500);
			timer1_fastPWM_A(1.499999);
 		}
		 else if (dio_get_pin(IR2_PORT, IR2_PIN) ==  DIO_LEVEL_LOW)
 		{
			 flag1 = 0;
 		}
		 //exit
		 if (dio_get_pin(IR1_PORT, IR1_PIN) ==  DIO_LEVEL_HIGH && counter > 0 && flag2 == 0)
		 {
			 counter--;
			LCD_clearscreen();
			LCD_move_cursor(4,0);
			LCD_send_char(counter+48);
			LCD_move_cursor(6,0);
			LCD_send_string("Cars");
			LCD_move_cursor(0,1);
			LCD_send_string("Garage has space");
			flag2 = 1;
			
			timer1_fastPWM_B(.999);
			_delay_ms(500);
			timer1_fastPWM_B(1.499999);
		 }
		 else if (dio_get_pin(IR1_PORT, IR1_PIN) ==  DIO_LEVEL_LOW)
		 {
			 flag2 = 0;
		 }
	
    }
	return 0;
}

