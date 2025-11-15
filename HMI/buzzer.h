#ifndef BUZZER_H_
#define BUZZER_H_

#include "macros_types.h"

#define BuzzerPort                1
#define BuzzerId                  5

/* Functions Prototypes */
void BuzzerInit(void);
void BuzzerOn(void);
void BuzzerOff(void);

#endif 
