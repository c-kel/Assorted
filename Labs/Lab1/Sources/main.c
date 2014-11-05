/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */



int main(void)
{
	// Enable the clock for the port control module
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTE_MASK; 
	
	// Initialise the red LED
	PORTC_PCR3 = 0x100; // Select GPIO mode
	GPIOC_PDDR = (1 << 3); // set PTC3 to output
	
	PORTD_PCR4 = 0x100; // green
	GPIOD_PDDR = (1 << 4);
	
	PORTA_PCR2 = 0x100; // blue
	GPIOA_PDDR = (1 << 2);
	
	// don't Disable the others
	//PORTD_PCR4 = 0; // green
	//PORTA_PCR2 = 0; // blue
	
	// Flash the LED
	GPIOD_PDOR=0x10;
	GPIOC_PDOR=0x8;
	int counter;
	for (;;) {
		GPIOA_PDOR = 0;
		for (counter = 0; counter < 1000000; counter++) {
			// spin
		}
		GPIOA_PDOR = (1 << 2);
		for (counter = 0; counter < 1000000; counter++) {
			// spin
			
		}
		GPIOD_PDOR=0;
		for (counter = 0; counter < 1000000; counter++) {
			// spin
		}
		GPIOD_PDOR = (1 << 4);
		for (counter = 0; counter < 1000000; counter++) {
			// spin

		}
		GPIOC_PDOR = 0;
		for (counter = 0; counter < 1000000; counter++) {
					// spin
				}
		GPIOC_PDOR = (1 << 3);
		for (counter = 0; counter < 1000000; counter++) {
			// spin

		}	
	}
	

	
	return 0;
}
