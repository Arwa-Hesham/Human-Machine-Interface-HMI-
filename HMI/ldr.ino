#include <avr/io.h>
#include "ldr.h"

/*
 * Description :
 * LDR Initialization by initializing the ADC.
 */

void LDRInit(void) {
    ADCInit();  
}

/*
 * Description :
 * Reads light intensity (0–100%) from LDR on channel 2
 */
uint16 LDRGetLightIntensity(void) {
    uint16 adcValue = ADCReadChannel(LDRChannel);

    /* Convert ADC value to voltage */
    float32 Voltage = ((float32)adcValue / 1023) * 5;

    /* Inverse relationship: higher voltage = lower light intensity */
    float32 Intens = (1.0 - (Voltage / 5 )) * 100;

    /* Clamp result between 0 and 100 */
    if (Intens < 0) Intens = 0;
    if (Intens > 100) Intens = 100;

    return (uint16)Intens;
}