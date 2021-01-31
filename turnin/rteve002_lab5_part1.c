/*	Author: lab
 *  Partner(s) Name: roz teves
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    
    unsigned char fuel = 0x00;
    unsigned char tempC = 0x00;
    
    while (1) {
	    fuel =~ PINA & 0x0F;

	    if(fuel == 0){
		    tempC = 0x40;
	    }

	    else if(fuel > 0 && fuel <= 2){
		    tempC = 0x60;
	    }

	    else if(fuel > 2 && fuel <= 4){
		    tempC = 0x70;
	    }

	    else if(fuel > 4 && fuel <= 6){
		    tempC = 0x38;
	    }

	    else if(fuel > 6 && fuel <= 9){
		    tempC = 0x3c;
	    }
	    
	    else if(fuel > 9 && fuel <= 12){
		    tempC = 0x3e;
	    }

	    else if(fuel > 12 && fuel <= 15){
		    tempC = 0x3f;
	    }
	    PORTC = tempC;
    }
    return 1;
}
