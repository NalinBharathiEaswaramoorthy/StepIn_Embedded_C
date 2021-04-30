#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include "4_USART.h"

void USARTInit(void)
{
    UBRR0H = (BAUDRATE>>8); //set as 0
    UBRR0L = BAUDRATE;     // set a 103d
    UCSR0C = (1<<UCSZ01)|(1<<UCSZ00); //8 bit size
    UCSR0B =(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0); // enable tx and rx    
}

char USARTRead(void)
{
    //Wait until data is available
    while(!(UCSR0A&(1<<RXC0)))
    { 
        // Wait
    }
    return UDR0;
}

void USARTWrite(int data)
{
    //Wait until transmitter is ready
    while(!(UCSR0A&(1<<UDRE0)))
    {
        // Wait
    }
    UDR0 = data;
}