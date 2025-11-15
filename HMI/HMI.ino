#include <avr/io.h>
#include <util/delay.h>

/*
 * Sensor Drivers
*/
#include "lm35.h"
#include "ldr.h"
/*
 * Display Drivers.
*/
#include "lcd.h"
/*
 * Alerts Drivers.
*/
#include "led.h"
#include "buzzer.h"

/* 
* Button Mapping 
* pressing on select button on the lcd keypad to switch between sensors.
* pressing on UP button on the lcd keypad to switch between the upper and lower sensor limits.
* pressing on Right button on the lcd keypad to increase the selected limit.
* pressing on Left button on the lcd keypad to decrease the selected limit.
*/

/*
 * Fixed Strings that always displayed on the LCD.
*/
uint8 temperature = 0;                   /* variable to store temperature value */
uint8 LightIntensity = 0;                /* variable to store light intensity value */

char Ldr[] = "Intens: ";
char Temp[] = "Temp: ";
char C[]  =  "C";       /*CELSIUS*/
char Cd[]  =  "Cd";       /*Candella*/

char Lower[] = "LL:";
char Upper[] = "LH:";
char space[] = " ";
char NOK[] = "NOK";
char OK[] = "OK ";
/*
 * Temperature(LM35) boundaries.
 * Global variables that updates automatically if any change happend during the run time. 
 */

uint8 TempUpp = 60;
uint8 TempLow = 15;

/*
 * Light Dependent Resistor (LDR) boundaries.
 * Global variables that updates automatically if any change happend during the run time. 
 */

uint8 LdrUpp = 70;
uint8 LdrLow = 20;

/*
 * switching between which sensor will be displayed.
 * switching between which boundary will be modified.
 * Global variables that updates automatically if any change happend during the run time. 
 */

uint8 SensorSelect = 0; /* 0 for LM35, 1 for LDR */
uint8 BoundSelect = 0;  /* 0 for lower, 1 for upper */

uint8 ButtonSelect ;
uint8 ButtonValue; 

/*LM35 Display Function*/
void LM35Display(void)
{
	
/* Reading sensors values*/
	temperature = LM35GetTemperature();

/* Displaying Sensors Values on LCD */
	LCDDisplayStringRowColumn(0,0,Temp);
    LCDIntgerToStringRawColumn(0,6,temperature);
    LCDDisplayStringRowColumn(0,8,C);

/* Displaying boundary Values on LCD */
    /*Upper boundary*/
	LCDDisplayStringRowColumn(1,0,Upper);
	LCDIntgerToStringRawColumn(1,3,TempUpp);
	LCDDisplayStringRowColumn(1,6,C);

    /*Lower boundary*/
	LCDDisplayStringRowColumn(1,9,Lower);
	LCDIntgerToStringRawColumn(1,12,TempLow);
	LCDDisplayStringRowColumn(1,15,C);

/* Checking for button press to modify boundaries */
	ButtonValue = ButtonSelectVal();
	if(ButtonValue == 'U')
	 {
	 	BoundSelect = !BoundSelect;
	 	_delay_ms(20); /* delay for the button press stabilization */
	 }
	if (BoundSelect==0)
	 {
	 	ButtonValue = ButtonSelectVal();
	 	switch (ButtonValue)
	 	{
	 	case 'R':
	 		TempLow++;
	 		break;

	 	case 'L':
	 		TempLow--;
	 		break;

	 	default:
	 		break;
	 	}
	 }
	else if (BoundSelect==1)
	 {
	 	switch (ButtonValue)
	 	{
	 	case 'R':
		TempUpp++;
	 		break;

	 	case 'L':
		TempUpp--;
	 		break;
			
	 	default:
	 		break;
	 	}
	 }
	if(temperature < TempLow || temperature > TempUpp )
	 {
		  LedOn();
      BuzzerOn();
			LCDDisplayStringRowColumn(0,12,NOK);
	 }
   else
     {
       LedOff();
       BuzzerOff();
			 LCDDisplayStringRowColumn(0,12,OK);
     }
    
}

/*LDR Display Function*/
void LDRDisplay(void)
{
	uint8 LightIntensity = 0;                /* variable to store light intensity value */
	LightIntensity = LDRGetLightIntensity();

/* Displaying Sensors Values on LCD */
	LCDDisplayStringRowColumn(0,0,Ldr);
	LCDIntgerToStringRawColumn(0,7,LightIntensity);
	

/* Displaying boundary Values on LCD */
	/*Upper boundary*/
	LCDDisplayStringRowColumn(1,0,Upper);
	LCDIntgerToStringRawColumn(1,3,LdrUpp);
	

	/*Lower boundary*/
	LCDDisplayStringRowColumn(1,8,Lower);
	LCDIntgerToStringRawColumn(1,11,LdrLow);
	

/* Checking for button press to modify boundaries */
	ButtonValue = ButtonSelectVal();
	if(ButtonValue == 'U')
	{
		BoundSelect = !BoundSelect;
		_delay_ms(50); /* delay for the button press stabilization */
	}
	if (BoundSelect==0)
	{
		ButtonValue = ButtonSelectVal();
		switch (ButtonValue)
		{
		case 'R':
			LdrLow+=10;

			break;
		case 'L':
			LdrLow-=10;

			break;
		default:
			break;
		}
	}
	else if (BoundSelect==1)
	{
		switch (ButtonValue)
		{
		case 'R':
			LdrUpp+=10;
			break;
		case 'L':

			LdrUpp-=10;

			break;
		default:
			break;
		}
	}
	if(LightIntensity < LdrLow || LightIntensity > LdrUpp )
	 {
		LedOn();
        BuzzerOn();
		LCDDisplayStringRowColumn(0,12,NOK);
	 }
   else
     {
		LedOff();
        BuzzerOff();
	    LCDDisplayStringRowColumn(0,12,OK);
     }
	

}
/*
 * Application setup
 */

int main(void)
{
	/* Sensors Initialization
	* Calling the initialization for only one sensor cause both of them use the same ADC module to run.
	*/
	LM35Init();
	/*
	 * Display Initialization.
	 */
	LCDInit();
	/* 
	 * Alerts Initialization
	 */
    BuzzerInit();
    LedInit();


    uint8 temperature = 0;                   /* variable to store temperature value */
    uint8 LightIntensity = 0;                /* variable to store light intensity value */
	
	/*
	* Application loop
	*/
    for(;;)
    {
		 ButtonValue = ButtonSelectVal();    // Read analogue button value

        if (ButtonValue == 'S') // Select button to switch modes
        {
            SensorSelect = !SensorSelect; // Toggle mode between 0 and 1
            _delay_ms(50); // Debounce delay
            BuzzerOff(); // Turn off buzzer when mode is switched
            LedOff(); // Turn off LED when mode is switched
            LCDClearScreen(); // Clear LCD screen
        }

		if(SensorSelect == 0)
		{
			LM35Display();
		}
		else if(SensorSelect == 1)
		{
			LDRDisplay();
		}

	}
    return 0;
}