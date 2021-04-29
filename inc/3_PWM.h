#ifndef __PWM_H__
#define __PWM_H__

/**
 * @brief Initialize Timer in 10 bit Non-Inverting Fast PWM with 64 prescalar
 * 
 */
void PWM_config();

/**
 * @brief Generates PWM output based on ADC value 
 * 
 * @param ADC_value 
 * @return int 
 */
int PWMoutput(uint16_t ADC_value);

#endif