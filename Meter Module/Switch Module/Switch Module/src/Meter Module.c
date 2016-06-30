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

#define Pulse_cnt  IOPORT_CREATE_PIN(PORTD, 5)
#define Rev_pol    IOPORT_CREATE_PIN(PORTB, 0)
#define Rel_drive  IOPORT_CREATE_PIN(PORTB, 2)
#define Led_drive  IOPORT_CREATE_PIN(PORTC, 2)


unsigned int duration=0;

void init_timer1 (void){
	
	TCCR1A=0x00;
	TCCR1B=0x00;
	TCNT1H=0x00;
	TCNT1L=0x00;
	ICR1H=0x00;
	ICR1L=0x00;
	OCR1AH=0x00;
	OCR1AL=0x00;
	OCR1BH=0x00;
	OCR1BL=0x00;
	
	TIMSK1=0x04;
}

void count_frequency(void){
	
	 TIMSK1=0x04;  // enable overflow interrupt of timer1
	 TCCR1B=0x07;   /* start timer1 with external pulses (T1 rising edge) */
	 delay_ms(1000);    // wait for one second
	 TCCR1B=0x00;    //stop timer1
	 TIMSK1=0x00;     //disable interrupt
	 duration=TCNT1;
	
}


int main (void){
	
	sysclk_init();
	
	ioport_set_pin_dir(Pulse_cnt, IOPORT_DIR_INPUT);
	ioport_set_pin_dir(Rev_pol, IOPORT_DIR_INPUT);
	ioport_set_pin_dir(Rel_drive, IOPORT_DIR_INPUT);
	ioport_set_pin_dir(Led_drive, IOPORT_DIR_INPUT);
	
	ioport_init();
	
	delay_ms(200);
	
	//while(true) {
		
		//ioport_set_pin_level(Rel_drive,1);
		//ioport_set_pin_level(Led_drive,1);
		
		//delay_ms(5000);
		
		//ioport_set_pin_level(Rel_drive,0);
		//ioport_set_pin_level(Led_drive,0);
		
	//	delay_ms(5000);
		
//	}
	

}
