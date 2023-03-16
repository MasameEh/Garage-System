/*
 * Timer.c
 *
 *  Author: Mohamed Sameh
 */ 

#include "timer.h"
#include <avr/io.h>
#include <avr/interrupt.h>


#define PULSE_PORT_A DIO_PORTD
#define PULSE_PIN_A DIO_PIN5 

#define PULSE_PORT_B DIO_PORTD
#define PULSE_PIN_B DIO_PIN4

void timer0_normalmode_init()
{
	
	//PRESCALER -> 1024
	SET_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS02);
	//enable interrupt
	sei();
	SET_BIT(TIMSK,TOIE0);
}


void timer0_CTC_init()
{
	//select CTC mode
	SET_BIT(TCCR0,WGM01);
	//load a value in OCR0 
	OCR0=78;
	//PRESCALER -> 1024
	SET_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS02);
	//
	//enable interrupt
	sei();
	SET_BIT(TIMSK,OCIE0);
}

void timer0_deinit()
{
	//PRESCALER -> NOCLOCK SOURCE
	CLR_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
	//disable interrupt
	CLR_BIT(TIMSK, TOIE0);
}


void timer1_fastPWM_A(double v)
{
	//set OC1A as output pin 
	dio_set_pin_direction(PULSE_PORT_A,PULSE_PIN_A,DIO_DIRECTION_OUTPUT);
	//select fastPWM mode
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	//
	OCR1A = v*1000;
	ICR1 = 20000; 
	//select timer clock, no prescaling
	SET_BIT(TCCR1B,CS10);
	//clear OC1A on compare match, set OC1A at BOTTOM
	SET_BIT(TCCR1A,COM1A1);
}

void timer1_fastPWM_B(double v)
{
	//set OC1B as output pin
	dio_set_pin_direction(PULSE_PORT_B,PULSE_PIN_B,DIO_DIRECTION_OUTPUT);
	//select fastPWM mode
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	//
	OCR1B = v*1000;
	ICR1 = 20000;
	//select timer clock, no prescaling
	SET_BIT(TCCR1B,CS10);
	//clear OC1B on compare match, set OC1B at BOTTOM
	SET_BIT(TCCR1A,COM1B1);
}
