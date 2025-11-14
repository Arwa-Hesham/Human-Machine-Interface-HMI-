#include "ADC.h"
#include <avr/io.h>


/*
 * Description :
 * ADC Initialization.
 */
void ADCInit(void)
 {
     ADMUX = (1 << REFS0); // AVCC with external capacitor at AREF pin 
     ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // ADC interrupt flag / Prescalar = 128
 }
 
/*
 * Description :
 * Read and return the value of the required Channel.
 */
uint16 ADCReadChannel(uint8 ChNum)
 {
 	 ADMUX &= 0xE0;
 	 ADMUX |= (ChNum &(0x07));
 	 ADCSRA |= (1<<ADSC); /*start conversion*/
 	 while (!(ADCSRA & (1<<ADIF))){} /*clear interrupt flag*/
 	 ADCSRA |=(1<<4); /*ADC Interrupt flag*/
 	 return ADC;
 }
