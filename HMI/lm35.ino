#include "lm35.h"
#include "ADC.h"
#include <avr/io.h>


/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
void LM35Init(void){
	ADCInit();
}
uint8 LM35GetTemperature(void)
 {
 	uint8 TempValue = 0;
 
 	uint16 ADCValue = 0;
 
 	/* Read ADC channel where the temperature sensor is connected */
 	ADCValue = ADCReadChannel(LM35Channel);
 
 	/* Calculate the temperature from the ADC value*/
 	TempValue = (uint8)(((uint32)ADCValue*150*5)/(1023*1.5));
 
 	return TempValue;
 }

