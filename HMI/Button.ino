#include <avr/io.h>
#include <util/delay.h>
#include "Button.h"
#include "adc.h"


char ButtonSelectVal(void)
 {
     uint16 Val =ADCReadChannel(ButtonChannel);  /*read the value on the Button Channel (0) for button press value*/
     _delay_ms(50); /* delay for the button press stabilization */
 
    /* 
    * Selecting the button according to the returned value from the ADC read
    */
     if (Val <= 50 && Val >= 0)
         return 'R'; /* Right */
     else if (Val <= 195 && Val > 50)
         return 'U'; /* Up */
     else if (Val <= 380 && Val > 195)
         return 'D'; /* Down */ 
     else if (Val <= 555 && Val > 380)
         return 'L'; /* Left */
     else if (Val <= 790 && Val > 555)
         return 'S'; /* Select */
     else
         return 0; /* None */
 }
