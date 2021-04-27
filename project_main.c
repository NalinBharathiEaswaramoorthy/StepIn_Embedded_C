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
#include "1_HeaterLED.h"
#include <avr/io.h>
#include <util/delay.h>

/**
 * @brief 
 * 
 * @return int 
 */

int main()
{
short heater = heater_led();
return 0;
}
