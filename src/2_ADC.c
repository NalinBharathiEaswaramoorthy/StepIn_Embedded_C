#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include "2_ADC.h"

void InitADC()
{
 //Set 10 bit resolution
 ADMUX = (1<<REFS0);
 // Enable ADC and set prescalar to 128
 ADCSRA = (1<<ADEN)|(7<<ADPS0);
}

uint16_t ReadADC(uint8_t ADC_channel) // ADC has 8 channels (0-7)
{
 ADMUX &= 0xf8;                       // 0b11111000 MUX is cleared
 ADC_channel = ADC_channel & 0b00000111;
 ADMUX |= ADC_channel;                // Channel number is passes to MUX
 // Start single conversion
 ADCSRA |= (1<<ADSC);
 // Wait for the conversion to complete
 while(!(ADCSRA&(1<<ADIF)));
 // Clear ADIF by writing 1 to it
 ADCSRA |= (1<<ADIF);
 return (ADC);
}