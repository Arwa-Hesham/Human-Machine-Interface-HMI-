#ifndef LCD_H_
#define LCD_H_

#include "macros_types.h"


/* LCD HW Ports and Pins Ids */
#define LcdRSPort                 1
#define LcdRSPin                  0

#define LcdEPort                  1
#define LcdEPin                   1



#define LcdDataPort              3      

#define LCDDB4Pin                4
#define LCDDB5Pin                5
#define LCDDB6Pin                6
#define LCDDB7Pin                7


/* LCD Commands */
#define LCDClearCommand                   0x01
#define LCDGoToHome                       0x02
#define LCDFourBitsMode                   0x28
#define LCDFourBitsModeInit1              0x33
#define LCDFourBitsModeInit2              0x32
#define LCDCursorOff                      0x0C
#define LCDCursorOn                       0x0E
#define LCDSetCursorLocation              0x80

/* Functions Prototypes */

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCDInit(void);

/*
 * Description :
 * Send the required command to the screen
 */
void LCDSendCommand(uint8 Command);

/*
 * Description :
 * Display the required character on the screen
 */
void LCDDisplayCharacter(uint8 Data);

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCDMoveCursor(uint8 row,uint8 col);

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCDDisplayStringRowColumn(uint8 row,uint8 col,const char *Str);

/*
 * Description :
 * Display the required decimal value on the screen in the required row and column
 */
void LCDIntgerToStringRawColumn(int Row,int Col,int Data);

/*
 * Description :
 * Send the clear screen command
 */
void LCDClearScreen(void);

#endif /* LCD_H_ */
