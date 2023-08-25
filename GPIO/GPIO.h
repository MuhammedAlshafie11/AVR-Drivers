#include "Std Types.h"
#include "Common Macros.h"

#ifndef GPIO_H_
#define GPIO_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define NUM_OF_PORTS           4
#define NUM_OF_PINS_PER_PORT   8

#define GPIO_PORTA	               0
#define GPIO_PORTB	               1
#define GPIO_PORTC	               2
#define GPIO_PORTD	               3

#define PIN0	               0
#define PIN1	               1
#define PIN2	               2
#define PIN3	               3
#define PIN4	               4
#define PIN5	               5
#define PIN6	               6
#define PIN7	               7

 /*******************************************************************************
  *                               Types Declaration                             *
  *******************************************************************************/
typedef enum
{
	PIN_INPUT, PIN_OUTPUT
}GPIO_PinDirectionType;

typedef enum
{
	PORT_INPUT, PORT_OUTPUT = 0xFF
}GPIO_PortDirectionType;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

 /*
  * Description :
  * Setup the direction of the required pin input/output.
  * If the input port number or pin number are not correct, The function will not handle the request.
  */
void GPIO_SetupPinDirectionType(uint8 PortNum, uint8 PinNum, GPIO_PinDirectionType Direction);

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_WritePin(uint8 PortNum, uint8 PinNum, uint8 value);


/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8 GPIO_ReadPin(uint8 PortNum, uint8 PinNum);


/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_SetupPortDirectionType(uint8 PortNum, GPIO_PortDirectionType Direction);



/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_WritePort(uint8 PortNum, uint8 value);

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
uint8 GPIO_ReadPort(uint8 PortNum);




#endif 