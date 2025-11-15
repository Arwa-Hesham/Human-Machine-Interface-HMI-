#include "macros_types.h"
#include <avr/io.h>
#include "ADC.h"


#ifndef LDR_H_
#define LDR_H_

#define LDRChannel               2

/* Functions Prototypes */
void LDRInit(void);
uint16 LDRGetLightIntensity(void);


#endif /* LDR_H_ */