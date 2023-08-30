/*
 * LCD.h
 *
 * Created: 2/17/2023 10:15:30 AM
 *  Author: Mohamed Sameh
 */ 


#ifndef LCD_H_
#define LCD_H_
/* Section : Includes */

#include "LCD_config.h"
#include "dio.h"

/* Section : Macro Declarations */
#define EIGHT_BITS 0x38
#define CLEAR_SCREEN 0x01
#define CURSOR_ON_DISPLAY_ON 0x0e
#define CURSOR_OFF_DISPLAY_ON 0x0c
#define CURSOR_ON_DISPLAY_ON_BLINK_ON 0x0d
#define ENTRY_MODE 0x06

/* Section : Macro Functions Declarations */

/* Section : Data Types Declarations  */

/* Section : Functions Declarations */
void LCD_init(void);
void LCD_send_cmd(char cmd);
void LCD_send_falling_edge();
void LCD_send_char(char data);
void LCD_send_string(char *data);
void LCD_send_int(sint64 number);

void LCD_clearscreen();
void LCD_move_curser(uint8 x, uint8 y);



#endif /* LCD_H_ */