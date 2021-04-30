/**
 * @file project_main.c
 * @author Nalin Bharathi E (nalinbharathi@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2021-04-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdint.h>
#include "1_HeaterLED.h"
#include "2_ADC.h"
#include "3_PWM.h"
#include "4_USART.h"
#include <avr/io.h>
#include <util/delay.h>

/**
 * @brief 
 * 
 * @return int 
 */

int main()
{
    while(1)
    {
        int temperature = 0;
        short heater = 0;
        heater = heater_led();
        uint16_t ADC_value = 0;
        if(heater == 1)             // Read ADC value if both switches are turned on
        {
            InitADC();
            ADC_value = ReadADC(0);  //Read from ADC channel 0
            _delay_ms(200);
            PWM_config();
            temperature = PWMoutput(ADC_value);
            USARTInit();             //Initialize USART
            USARTWrite(temperature); // Print temperature on Serial Monitor
            char input = USARTRead(); // Read a value from Serial Monitor
            if(input == 'N'|| input == 'n')
            break;
        }
        else
        {
            ADC_value=0;
            temperature=0;
        }
    }
    return 0;
}
