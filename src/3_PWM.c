#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include "2_ADC.h"
#include "3_PWM.h"

void PWM_config()
{
    TCCR1A|=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10); 
    TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10);
    DDRB|=(1<<PB1);
}

int PWMoutput(uint16_t ADC_value)
{
    int temp_buffer;
    if((ADC_value>=0) && (ADC_value<210))
    {
    OCR1A = 205; // 20% duty cycle
    temp_buffer = 20;
    _delay_ms(50);
    }
    else if((ADC_value>=210) && (ADC_value<510))
    {
    OCR1A = 410; // 40% duty cycle
    temp_buffer = 25;
    _delay_ms(50);
    }
    else if((ADC_value>=510) && (ADC_value<700))
    {
    OCR1A = 717; // 70% duty cycle
    temp_buffer = 29;
    _delay_ms(50);
    }
    else if((ADC_value>=700) && (ADC_value<1024))
    {
    OCR1A = 973; // 70% duty cycle
    temp_buffer = 33;
    _delay_ms(50);
    }
    else
    {
    OCR1A = 0;
    temp_buffer = 0;
    _delay_ms(50);
    }
    return temp_buffer;
}