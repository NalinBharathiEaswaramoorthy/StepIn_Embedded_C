#ifndef __USART_H__
#define __USART_H__

#define F_CPU 16000000UL // microcontroller frequency
#define BAUD 9600 // define baud rate 
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1) //set baud rate value for UBRR

/**
 * @brief Initialize USART as asynchronous 8 bit with baud rate 9600
 * 
 */
void USARTInit(void);

/**
 * @brief Read data from Serial Monitor
 * 
 * @return int 
 */
int USARTRead();

/**
 * @brief Print data(temperature) to the serial monitor
 * 
 */
void USARTWrite(int);

#endif