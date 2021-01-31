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
			//PA_0, PA_1
enum States{Start, init, incr, decr, Reset}state;

unsigned char A0;
unsigned char A1;
unsigned char tempC;

void Tick(){
	switch(state){
		case Start:
			tempC = 7;
			state = init;
			break;
		case init:
			if(A0 & (!A1)){
				state = incr;
				if(tempC < 9){
					tempC = tempC + 1;
				}
			}
			else if(A0 & A1){
				state = Reset;
				tempC = 0;
			}
			else if((!A0) & A1){
				state = decr;
				if(tempC > 0){
					tempC = tempC - 1;
				}
			}
			else
				state = init;
			break;
		case incr:
			if(A0 & (!A1)){
				state = incr;
			}
			else if((!A0) & (!A1)){
				state = init;
			}
			else if(A0 & A1){
				state = Reset;
				tempC = 0;
			}
			break;
		case decr:
			if(A1 & (!A0)){
				state = decr;
			}
			else if((!A0) & (!A1)){
				state = init;
			}
			else if(A0 & A1){
				state = Reset;
				tempC = 0;
			}
			break;
		case Reset:
			if(!A1 & !A0){
				state = init;
			}
			else
				state = Reset;
			break;
		default:
			break;
	}
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    
    state = Start;

    while (1) {
	    A0 =~ PINA & 0x01;
	    A1 = (~PINA >> 1) & 0x01;
	    Tick();
	    PORTC = tempC;
    }
    return 1;
}
