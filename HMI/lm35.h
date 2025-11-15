#ifndef MACROS
#define MACROS
#include "macros_types.h"
#endif

#ifndef LM35_H_
#define LM35_H_


#define LM35Channel               3

/* Functions Prototypes */
void LM35Init(void);
uint8 LM35GetTemperature(void);

#endif
