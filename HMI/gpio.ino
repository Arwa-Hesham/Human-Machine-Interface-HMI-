#include <avr/io.h>
#include "gpio.h"

/*
 * Description :
 * Setup the direction of the required pin .
 */
void PinDirection(uint8 PortNum, uint8 PinNum, uint8 Direction)
 {
 	if(Direction == 1)
 	{
 	  switch(PortNum)
 	  {
 	    case 1:
 	  	  SetBit(DDRB,PinNum);
 	  	  break;
   
 	    case 2:
 	  	  SetBit(DDRC,PinNum);
 	  	  break;
   
 	    case 3:
 	      SetBit(DDRD,PinNum);
 	  	  break;
 		}
 	}
 	else
 	{
 		switch(PortNum)
 	  {
 	  case 1:
 	  	ClearBit(DDRB,PinNum);
 	    break;
   
 	  case 2:
 	    ClearBit(DDRC,PinNum);
 	  	break;
   
 	  case 3:
 	    ClearBit(DDRD,PinNum);
 	  	break;
 		}
 	}
 }
 

 /*
 * Description :
 * Write the value on the required pin.
 */
void WritePin(uint8_t PortNum, uint8_t PinNum, uint8_t value)
 {
 
    	if(value == 1)
     {
     	switch(PortNum)
     	{
     	case 1:
     		SetBit(PORTB,PinNum);
     		break;
     	case 2:
     		SetBit(PORTC,PinNum);
     		break;
     	case 3:
     		SetBit(PORTD,PinNum);
     		break;
     	}
     }
     else
     {
     	switch(PortNum)
     	{
     	case 1:
     		ClearBit(PORTB,PinNum);
     		break;
     	case 2:
     		ClearBit(PORTC,PinNum);
     		break;
     	case 3:
     		ClearBit(PORTD,PinNum);
     		break;
     	}
     }
 }


 /*
 * Description :
 * Read and return the value of the required pin.
 */
uint8 ReadPin(uint8 PortNum, uint8 PinNum)
 {
   uint8 PinValue = 0;
 	switch(PortNum)
 	{
 	  case 1:
 		  if(BitIsSet(PINB,PinNum))
 	  	{
 	  		PinValue = 1;
 	  	}
 	  	else
 	  	{
 	  		PinValue = 0;
 	  	}
 	  	break;
 	  case 2:
 	  	if(BitIsSet(PINC,PinNum))
 	    	{
 	    		PinValue = 1;
 	    	}
 	    	else
 	    	{
 	    		PinValue = 0;
 	    	}
 	    	break;
 	    case 3:
 	    	if(BitIsSet(PIND,PinNum))
 	    	{
 	    		PinValue = 1;
 	    	}
 	    	else
 	    	{
 	    		PinValue = 0;
 	    	}
 	    	break;
 	}
     return PinValue;
 }


 /*
 * Description :
 * Setup the direction of the required port all pins input/output.
 */
void SetPortDirection(uint8 PortNum, uint8 PortDirection)
 {
 
 		/* Setup the port direction as required */
 		switch(PortNum)
 		{
 		case 1:
 			DDRB = PortDirection;
 			break;
 		case 2:
 			DDRC = PortDirection;
 			break;
 		case 3:
 			DDRD = PortDirection;
 			break;
 		}

 }
    

 /*
 * Description :
 * Write the value on the required port.
 */
void WritePort(uint8 PortNum, uint8 Value)
 {
 	
 		/* Write the port value as required */
 		switch(PortNum)
 		{
 		case 2:
 			PORTB = Value;
 			break;
 		case 3:
 			PORTC = Value;
 			break;
 		case 4:
 			PORTD = Value;
 			break;
 		}
 }


 /*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
uint8 ReadPort(uint8 PortNum)
 {
 	uint8 Value = 0;
 

 		/* Read the port value as required */
 		switch(PortNum)
 		{
 		case 1:
 			Value = PINB;
 			break;
 		case 2:
 			Value = PINC;
 			break;
 		case 3:
 			Value = PIND;
 			break;
 		}
 	
 
 	return Value;
 }