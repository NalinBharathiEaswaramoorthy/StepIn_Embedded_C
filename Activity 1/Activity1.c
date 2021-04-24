/**
 * @file Activity1.c
 * @author Nalin Bharathi E (nalinbharathi@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2021-04-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include <util/delay.h>

/**
 * @brief 
 * 
 * @return int 
 */

int main()
{
    DDRB |= (1<<PB0);       // set B0 as output pin
    DDRD &=~(1<<PD0);      // clear bit PD0
    PORTD |=(1<<PD0);     // set bit PD0
    DDRD &=~(1<<PD1);    // clear bit PD1
    PORTD |= (1<<PD1);  // set bit PD1
    while(1)
    {
        if(!(PIND&(1<<PD0)))
        {
            if(!(PIND&(1<<PD1)))
            {
                PORTB|=(1<<PB0);     // Turn on led
                _delay_ms(50);
            }
            else
            {
                PORTB&=~(1<<PB0);    // Turn off led
                _delay_ms(50);
            }
        }
        else
        {
            PORTB&=~(1<<PB0);       // Turn off led
            _delay_ms(50);
        }
    }
return 0;
}
