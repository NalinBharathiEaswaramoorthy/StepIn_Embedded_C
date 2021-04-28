#ifndef __ADC_H__
#define __ADC_H__

/**
 * @brief function to Initialize the ADC
 * 
 */
void InitADC();

/**
 * @brief Reads analog input from ADC channel and performs conversion 
 * 
 * @param ADC_channel 
 * @return uint16_t 
 */
uint16_t ReadADC(uint8_t ADC_channel);

#endif
