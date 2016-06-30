/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>

#define K1_SET      IOPORT_CREATE_PIN(PORTB, 0)
#define K1_RESET    IOPORT_CREATE_PIN(PORTB, 1)
#define K2_SET      IOPORT_CREATE_PIN(PORTD, 6)
#define K2_RESET    IOPORT_CREATE_PIN(PORTD, 7)
#define SW1         IOPORT_CREATE_PIN(PORTD, 3)
#define SW2         IOPORT_CREATE_PIN(PORTD, 2)

int main (void){
	
	sysclk_init();
	
	ioport_set_pin_dir(K1_SET, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(K1_RESET, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(K2_SET, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(K2_RESET, IOPORT_DIR_OUTPUT);
	ioport_set_pin_mode(SW1, IOPORT_MODE_PULLUP);
	ioport_set_pin_mode(SW2, IOPORT_MODE_PULLUP);
	ioport_init();
	
	delay_ms(100);
	
	bool sw1TurnedOn = false;
	bool sw2TurnedOn = false;
	
	
	while (true)
	{
		
		if (ioport_get_pin_level(SW1) == IOPORT_PIN_LEVEL_LOW) {
			
			if(sw1TurnedOn) {
				ioport_set_pin_level(K1_RESET,1);
				delay_ms(10);
				ioport_set_pin_level(K1_RESET,0);
				
				sw1TurnedOn = false;
			}
			else
			{
				ioport_set_pin_level(K1_SET,1);
				delay_ms(10);
				ioport_set_pin_level(K1_SET,0);
				
				sw1TurnedOn = true;
			}
			
			delay_ms(500);			
		}
		
		if (ioport_get_pin_level(SW2) == IOPORT_PIN_LEVEL_LOW) {
			
			if(sw2TurnedOn) {
				ioport_set_pin_level(K2_RESET,1);
				delay_ms(10);
				ioport_set_pin_level(K2_RESET,0);
				
				sw2TurnedOn = false;
			}
			else
			{
				ioport_set_pin_level(K2_SET,1);
				delay_ms(10);
				ioport_set_pin_level(K2_SET,0);
				
				sw2TurnedOn = true;
			}
			
			delay_ms(500);
		}
	}
	
}
