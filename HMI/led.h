#ifndef led_H_
#define led_H_

#include "macros_types.h"

#define LEDPORT                  1 
#define LEDPIN                   4 

/* Functions Prototypes */
void LedInit(void);
void LedOn(void);
void LedOff(void);

#endif /* led_H_ */