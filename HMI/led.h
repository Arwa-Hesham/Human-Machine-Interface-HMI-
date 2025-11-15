#include <avr/io.h> 
#include "led.h"

//led_init
void led_init(){
    DDRD |= (1<<7);
}
//led_on
void led_on(){
    PORTD |= (1<<7);
}

//led_off
void led_off(){
    PORTD &= ~(1<<7);
}
