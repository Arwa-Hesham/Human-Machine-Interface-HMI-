#ifndef ADC_H_
#define ADC_H_

#include "macros_types.h"

/* Function Prototypes */

void ADCInit(void);
uint16 ADCReadChannel(uint8 Chnum);

#endif /* ADC_H_ */