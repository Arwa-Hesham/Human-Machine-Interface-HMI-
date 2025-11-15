#include "gpio.h"
#include <avr/io.h>
#include "led.h"


/*
 * Description :
 * LED Initialization.
 */
void LedInit(void)
 {
   PinDirection(LEDPORT, LEDPIN, 1);         /* Set the LED pin as output */
   LedOff();                                 /* Turn OFF the LED at the beginning */
 }

/*
 * Description :
 * Function responsible for turning on the LED by putting 1 on the pin  .
 */
void LedOn(void)
 {
    WritePin(LEDPORT, LEDPIN, 1);
 }

/*
 * Description :
 * Function responsible for turning off the LED by putting 0 on the pin  .
 */
void LedOff(void)
 {
     WritePin(LEDPORT, LEDPIN, 0);
 }