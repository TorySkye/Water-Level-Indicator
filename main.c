/*
 * Water Level Indicator.c
 *
 * Created: 21-Jun-17 7:08:53 PM
 * Author : Viktorija Alilovic
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include <stdlib.h>

#define  F_CPU 8000000UL

int main(void)
{
	DDRB = 0x00;						// PORTB pins as input
	DDRD = 0x01;						// Pin PD7 for Buzzer as output
	
	PORTB = 0xff;						// Write HIGH value to PORTB
	PORTD = 0b01111111;					// Write LOW value to pin PD7, write HIGH value for other pins
	
    lcd_init(LCD_DISP_ON);					// LCD initialization
   
    while (1) 
    {
		if (!(PINB & (1<<PB0)))				// 6th probe, Tank full
		{
			lcd_gotoxy(0,0); 			// Pointer to 1. row and 1. character
			lcd_puts("Tank is full!");
			lcd_gotoxy(0,1); 			// Pointer to 2. row and 1. character
			lcd_puts("   ");
			PORTD = 0b11111111;			// Buzzer ON
		}
		else if (!(PINB & (1<<PB1)))			// 5th probe
		{
			lcd_gotoxy(0,0); 
			lcd_puts("Water level:");
			lcd_gotoxy(0,1); 
			lcd_puts("80%");
			PORTD = 0b01111111;			// Buzzer OFF
			
		}
		else if (!(PINB & (1<<PB2)))			// 4th probe
		{
			lcd_gotoxy(0,0); 
			lcd_puts("Water level:");
			lcd_gotoxy(0,1); 
			lcd_puts("60%");
			PORTD = 0b01111111;			
		}
		else if (!(PINB & (1<<PB3)))			// 3th probe
		{
			lcd_gotoxy(0,0); 
			lcd_puts("Water level:");
			lcd_gotoxy(0,1); 
			lcd_puts("40%");
			PORTD = 0b01111111;			
		}
		else if (!(PIND & (1<<PD5)))			// 2th probe
		{
			lcd_gotoxy(0,0); 
			lcd_puts("Water level:");
			lcd_gotoxy(0,1); 
			lcd_puts("20%");
			PORTD = 0b01111111;				
		}
		else if (!(PIND & (1<<PD6)))			// 1st probe
		{
			lcd_gotoxy(0,0); 
			lcd_puts("Water level:");
			lcd_gotoxy(0,1); 
			lcd_puts("10%");
			PORTD = 0b01111111;			
		}
		else                            		// Tank empty
		{	
			lcd_gotoxy(0,0); 
			lcd_puts("Tank is empty!");
			lcd_gotoxy(0,1); 
			lcd_puts("   ");
			PORTD = 0b01111111;	
		}
    }
	return 0;
}

