#ifndef GPIO_H_
#define GPIO_H_

#include "macros_types.h"
#include <avr/io.h>

/* Function Prototypes */
void PinDirection(uint8_t PortNum, uint8_t PinNum, uint8_t Direction);
void WritePin(uint8_t PortNum, uint8_t PinNum, uint8_t value);
uint8_t ReadPin(uint8_t PortNum, uint8_t PinNum);
void SetPortDirection(uint8 PortNum, uint8 PortDirection);
void WritePort(uint8 portNum, uint8 Value);
uint8_t ReadPort(uint8 PortNum);

#endif 
