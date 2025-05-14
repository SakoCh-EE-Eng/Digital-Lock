/*
 * @file main.c
 *
 * @brief Main source code for the Digital Lock project.
 * 
 * @author Sako Chekerjian
 */

#include "TM4C123GH6PM.h"
#include "GPIO.h"
#include "PMOD_BTN_Interrupt.h"
#include "Seven_Segment_Display.h"
#include "SysTick_Delay.h"

// Declare the user-defined function prototype for PMOD_BTN_Interrupt
void PMOD_BTN_Handler(uint8_t pmod_btn_status);

// Functions that are dedicated to displaying on specific segment displays
void Write_To_DISP1(uint8_t value);
void Write_To_DISP2(uint8_t value);
void Write_To_DISP3(uint8_t value);
void Write_To_DISP4(uint8_t value);

// Global variables that will keep track of values for each display
static int Disp1_Count = 0;
static int Disp2_Count = 0;
static int Disp3_Count = 0;
static int Disp4_Count = 0;

static int Digital_Code = 4826;


int main(void)
{
	
	// Initialize the LEDs on the EduBase board (Port B)
	EduBase_LEDs_Init();
	
	// Initialize the RGB leds (Port F)
	RGB_LED_Init();

	// Initialize the push buttons on the PMOD BTN module (Port A)
	PMOD_BTN_Interrupt_Init(&PMOD_BTN_Handler);
	SysTick_Delay_Init();
	
	// Initialize Seven Segment
	Seven_Segment_Display_Init();
	
	// Calculates digit value for their respective Displays
	int d1 = (Digital_Code / 1000) % 10;    // Extracts value of 4 from 4826
	int d2 = (Digital_Code / 100) % 10;			// Extracts value of 8 from 4826
	int d3 = (Digital_Code / 10) % 10;			// Extracts value of 2 from 4826
	int d4 = Digital_Code % 10;							// Extracts value of 6 from 4826
	uint8_t led_output = 0;

	while(1)
	{
		// If Display 1 count is 4, turn the led under Diplay 1 on, if not turn it off
		if (Disp1_Count == d1)
		{
			led_output |= 0x08;
		}
		else
		{
			led_output &= ~0x08;
		}
		
		// If Display 2 count is 8, turn the led under Diplay 2 on, if not turn it off
		if (Disp2_Count == d2)
		{
			led_output |= 0x04;
		}
		else
		{
			led_output &= ~0x04;
		}
		
		// If Display 3 count is 2, turn the led under Diplay 3 on, if not turn it off
		if (Disp3_Count == d3)
		{
			led_output |= 0x02;
		}
		else
		{
			led_output &= ~0x02;
		}
		
		// If Display 4 count is 6, turn the led under Diplay 4 on, if not turn it off
		if (Disp4_Count == d4)
		{
			led_output |= 0x01;
		}
		else
		{
			led_output &= ~0x01;
		}
		
		EduBase_LEDs_Output(led_output);
		
		if(Are_All_LEDs_On())
		{
			RGB_LED_Output(RGB_LED_GREEN);
		}
		else
		{
			RGB_LED_Output(RGB_LED_RED);
		}
	}
}



void PMOD_BTN_Handler(uint8_t pmod_btn_status)
{
	switch(pmod_btn_status)
	{
		//BTN0 (PA2) is pressed
		case 0x04:
		{
			Disp1_Count = Disp1_Count + 1;
			if( Disp1_Count >=0 && Disp1_Count < 10 )
			{
				Write_To_DISP1(number_pattern[Disp1_Count]);
			}
			else if (Disp1_Count >= 10)
			{
				Disp1_Count = 0;
			}
			
			break;
		}
		
		// BTN1 (PA3) is pressed
		case 0x08:
		{
			Disp2_Count = Disp2_Count + 1;
			if( Disp2_Count >= 0 && Disp2_Count < 10 )
			{
				Write_To_DISP2(number_pattern[Disp2_Count]);
			}
			else if (Disp2_Count >= 10)
			{
				Disp2_Count = 0;
			}
					
			
			break;
		}
		
		// BTN2 (PA4) is pressed
		case 0x10:
		{
			Disp3_Count = Disp3_Count + 1;
			if( Disp3_Count >= 0 && Disp3_Count < 10 )
			{
				Write_To_DISP3(number_pattern[Disp3_Count]);
			}
			else if (Disp3_Count >= 10)
			{
				Disp3_Count = 0;
			}
						
			
			break;
		}
		
		// BTN3 (PA5) is pressed
		case 0x20:
		{
			Disp4_Count = Disp4_Count + 1;
			if( Disp4_Count >= 0 && Disp4_Count < 10 )
			{
				Write_To_DISP4(number_pattern[Disp4_Count]);
			}
			else if (Disp4_Count >= 10)
			{
				Disp4_Count = 0;
			}
						
			break;
		}
		
		default:
		{
			break;
		}
		
	}
}

void Write_To_DISP1(uint8_t value)
{
	SSI2_Write(value);
	SysTick_Delay1ms(5);
	SSI2_Write(0x08);
}

void Write_To_DISP2(uint8_t value)
{
	SSI2_Write(value);
	SysTick_Delay1ms(5);
	SSI2_Write(0x04);
}

void Write_To_DISP3(uint8_t value)
{
	SSI2_Write(value);
	SysTick_Delay1ms(5);
	SSI2_Write(0x02);
}

void Write_To_DISP4(uint8_t value)
{
	SSI2_Write(value);
	SysTick_Delay1ms(5);
	SSI2_Write(0x01);
}