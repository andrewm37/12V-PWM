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
#define F_CPU 1000000

#include <asf.h>
#include <util/delay.h>

#define SW1      IOPORT_CREATE_PIN(PORTD, 6)
#define SW2      IOPORT_CREATE_PIN(PORTD, 7)
#define LED_PWM  IOPORT_CREATE_PIN(PORTB, 1)
#define LED      IOPORT_CREATE_PIN(PORTC, 2)

#define BIT(x) (1 << (x))

uint8_t	g_duty = 50;

void init_pwm(void);
void set_duty_cycle(uint16_t duty);

int main (void){
	
	
	//sysclk_init();

	ioport_set_pin_dir(SW1, IOPORT_DIR_INPUT);
	ioport_set_pin_dir(SW2, IOPORT_DIR_INPUT);
	ioport_set_pin_dir(LED_PWM, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(LED, IOPORT_DIR_OUTPUT);
	
	ioport_set_pin_mode(SW1, IOPORT_MODE_PULLUP);
	ioport_set_pin_mode(SW2, IOPORT_MODE_PULLUP);
	
	ioport_init();
	
	ioport_set_pin_high(LED);
	
	init_pwm();

//	while(1);
	
	//ioport_set_pin_high(LED_PWM);
   

	while (1)
	{
		 for(uint16_t duty = 1024; duty > 0; --duty) {
			set_duty_cycle(duty-1);
			_delay_ms(100);
		 }
		 for(uint16_t duty = 0; duty < 1024; ++duty) {
			set_duty_cycle(duty);
			_delay_ms(100);
		 }
	}
	
	/*while(true){
	
	ioport_set_pin_level(LED_PWM,1);
	delay_ms(2000);
	ioport_set_pin_level(LED_PWM,0);
	delay_ms(2000);
	}
	
	init_pwm();
	
	delay_ms(100);
	
	set_duty_cycle(10);
	
	
	while (1) {
		
	} */

}

void init_pwm(void){
	
	//CLKPR  = 0b10000011; // Set I/O clock prescaler to Main Clock (Default 8 MHz/CLKDIV8 = 1MHz ) / 8 = 125 KHz
	
	TCCR1A |= _BV(COM1A1) | _BV(WGM10) | _BV(WGM11); 

	TCCR1B = _BV(WGM12) | _BV(CS11); // 10-bit Fast PWM, non-inverting mode, Clock source prescaler by 8

	ioport_set_pin_dir(LED_PWM, IOPORT_DIR_OUTPUT);
	
}

void set_duty_cycle(uint16_t duty)
{
	OCR1A = duty;
}

