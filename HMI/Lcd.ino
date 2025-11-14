#include <util/delay.h> 
#include "macros_types.h"
#include "lcd.h"
#include "gpio.h"
#include <avr/io.h>

/*
 * Description :
 * LCD Initialization
 */
void LCDInit(void)
 {
 	/* Configure the direction for RS and E pins as output pins */
 	PinDirection(LcdRSPort,LcdRSPin, 1);
 	PinDirection(LcdEPort,LcdEPin, 1);
 
 	_delay_ms(20);		                   /* LCD Power ON delay always > 15ms */
 
 	PinDirection(LcdDataPort,LCDDB4Pin,1);
 	PinDirection(LcdDataPort,LCDDB5Pin,1);
 	PinDirection(LcdDataPort,LCDDB6Pin,1);
 	PinDirection(LcdDataPort,LCDDB7Pin,1);
 
 	/* Send for 4 bit initialization of LCD  */
 	LCDSendCommand(LCDFourBitsModeInit1);
 	LCDSendCommand(LCDFourBitsModeInit2);
 
 	/* use 2-lines LCD + 4-bits Data Mode + 5*7 dot display Mode */
 	LCDSendCommand(LCDFourBitsMode);
 
 
 	LCDSendCommand(LCDCursorOff); 			/* cursor off */
 	LCDSendCommand(LCDClearCommand); 		/* clear LCD at the beginning */
 }

/*
 * Description :
 * Send the required Command to the screen
 */
void LCDSendCommand(uint8 Command)
 {
 	WritePin(LcdRSPort,LcdRSPin,0); 		/* Instruction Mode RS=0 */
 	_delay_ms(1); 							/* delay for processing Tas = 50ns */
 	WritePin(LcdEPort,LcdEPin,1);			/* Enable LCD E=1 */
 	_delay_ms(1); 							/* delay for processing Tpw - Tdws = 190ns */
 
 
 	WritePin(LcdDataPort,LCDDB4Pin,GETBIT(Command,4));
 	WritePin(LcdDataPort,LCDDB5Pin,GETBIT(Command,5));
 	WritePin(LcdDataPort,LCDDB6Pin,GETBIT(Command,6));
 	WritePin(LcdDataPort,LCDDB7Pin,GETBIT(Command,7));
 
 	_delay_ms(1);							/* delay for processing Tdsw = 100ns */
 	WritePin(LcdEPort,LcdEPin,0); 			/* Disable LCD E=0 */
 	_delay_ms(1); 							/* delay for processing Th = 13ns */
 	WritePin(LcdEPort,LcdEPin,1); 			/* Enable LCD E=1 */
 	_delay_ms(1); 							/* delay for processing Tpw - Tdws = 190ns */
 
 	WritePin(LcdDataPort,LCDDB4Pin,GETBIT(Command,0));
 	WritePin(LcdDataPort,LCDDB5Pin,GETBIT(Command,1));
 	WritePin(LcdDataPort,LCDDB6Pin,GETBIT(Command,2));
 	WritePin(LcdDataPort,LCDDB7Pin,GETBIT(Command,3));
 
 	_delay_ms(1);							/* delay for processing Tdsw = 100ns */
 	WritePin(LcdEPort,LcdEPin,0); 			/* Disable LCD E=0 */
 	_delay_ms(1); 							/* delay for processing Th = 13ns */
 
 }

/*
 * Description :
 * Display the required character on the screen
 */
void LCDDisplayCharacter(uint8 Data)
 {
 	WritePin(LcdRSPort,LcdRSPin,1); 		/* Data Mode RS=1 */
 	_delay_ms(1); 							/* delay for processing Tas = 50ns */
 	WritePin(LcdEPort,LcdEPin,1);			/* Enable LCD E=1 */
 	_delay_ms(1); 							/* delay for processing Tpw - Tdws = 190ns */
 
 
 	WritePin(LcdDataPort,LCDDB4Pin,GETBIT(Data,4));
 	WritePin(LcdDataPort,LCDDB5Pin,GETBIT(Data,5));
 	WritePin(LcdDataPort,LCDDB6Pin,GETBIT(Data,6));
 	WritePin(LcdDataPort,LCDDB7Pin,GETBIT(Data,7));
 
 	_delay_ms(1); 							/* delay for processing Tdsw = 100ns */
 	WritePin(LcdEPort,LcdEPin,0); 			/* Disable LCD E=0 */
 	_delay_ms(1); 							/* delay for processing Th = 13ns */
 	WritePin(LcdEPort,LcdEPin,1); 			/* Enable LCD E=1 */
 	_delay_ms(1); 							/* delay for processing Tpw - Tdws = 190ns */
 
 	WritePin(LcdDataPort, LCDDB4Pin , GETBIT(Data,0) );
 	WritePin(LcdDataPort, LCDDB5Pin , GETBIT(Data,1) );
 	WritePin(LcdDataPort, LCDDB6Pin , GETBIT(Data,2) );
 	WritePin(LcdDataPort, LCDDB7Pin , GETBIT(Data,3) );
 
 	_delay_ms(1);							/* delay for processing Tdsw = 100ns */
 	WritePin(LcdEPort,LcdEPin,0); 			/* Disable LCD E=0 */
 	_delay_ms(1); 							/* delay for processing Th = 13ns */
 
 }

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCDMoveCursor(uint8 row,uint8 col)
 {
 	uint8 LcdMemoryAddress;
 
 	/* Calculate the required address in the LCD DDRAM */
 	switch(row)
 	{
 		case 0:
 			LcdMemoryAddress=col;
 				break;
 		case 1:
 			LcdMemoryAddress=col+0x40;
 				break;
 		case 2:
 			LcdMemoryAddress=col+0x10;
 				break;
 		case 3:
 			LcdMemoryAddress=col+0x50;
 				break;
 	}
 	/* Move the LCD cursor to this specific address */
 	LCDSendCommand(LcdMemoryAddress | LCDSetCursorLocation);
 }

/*
 * Description :
 * Display the required string in a specified row and column index on the screen.
 */
void LCDDisplayStringRowColumn(uint8 row,uint8 col,const char *Str)
 {
	/*
	* Move cursor to the required row and column
	*/
 	LCDMoveCursor(row,col); 					
	/*
	*Display the string by passing each character to the display character function
	*/
 	while((*Str) != '\0')
 	{
 		LCDDisplayCharacter(*Str);
 		Str++;
 	}
 }

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCDIntgerToStringRawColumn(int Row,int Col,int Data)
 {
	char buff[16]; 								    /* String to hold the ascii result for the number */
	itoa(Data,buff,10); 							/* Use itoa C function to convert the Data to its corresponding ASCII value, 10 for decimal */
	LCDDisplayStringRowColumn(Row,Col,buff);					/* Display the string */
 }
/*
 * Description :
 * Send the clear screen Command
 */
void LCDClearScreen(void)
 {
 	LCDSendCommand(LCDClearCommand); /* Send clear display Command */
 }
