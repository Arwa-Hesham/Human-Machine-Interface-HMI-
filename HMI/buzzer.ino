#include <avr/io.h>
#include "buzzer.h"
#include "gpio.h"

/*
 * Description :
 * Function responsible for initializing the buzzer by making it output .
 */
void BuzzerInit(void)
 {
	PinDirection(BuzzerPort, BuzzerId, 1);
	BuzzerOff();
 }

/*
 * Description :
 * Function responsible for turning on the buzzer by putting 1 on the pin  .
 */
void BuzzerOn(void)
 {
	WritePin(BuzzerPort, BuzzerId, 1);
 }

/*
 * Description :
 * Function responsible for turning off the buzzer by putting 0 on the pin  .
 */
void BuzzerOff(void)
 {
	WritePin(BuzzerPort, BuzzerId, 0);
 }
