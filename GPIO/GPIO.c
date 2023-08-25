#include "GPIO.h"
#include "avr/io.h" /* To use the IO Ports Registers */

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_SetupPinDirectionType(uint8 PortNum, uint8 PinNum, GPIO_PinDirectionType Direction) {

	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if ((PinNum >= NUM_OF_PINS_PER_PORT) || (PortNum >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the pin direction as required */
		switch (PortNum)
		{
		case GPIO_PORTA:
			if (Direction == PIN_OUTPUT)
			{
				SET_BIT(DDRA, PinNum);
			}
			else
			{
				CLEAR_BIT(DDRA, PinNum);
			}
			break;

		case GPIO_PORTB:
			if (Direction == PIN_OUTPUT)
			{
				SET_BIT(DDRB, PinNum);
			}
			else
			{
				CLEAR_BIT(DDRB, PinNum);
			}
			break;

		case GPIO_PORTC:
			if (Direction == PIN_OUTPUT)
			{
				SET_BIT(DDRC, PinNum);
			}
			else
			{
				CLEAR_BIT(DDRC, PinNum);
			}
			break;

		case GPIO_PORTD:
			if (Direction == PIN_OUTPUT)
			{
				SET_BIT(DDRD, PinNum);
			}
			else
			{
				CLEAR_BIT(DDRD, PinNum);
			}
			break;
		}
	}

}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_WritePin(uint8 PortNum, uint8 PinNum, uint8 value) {

	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if ((PinNum >= NUM_OF_PINS_PER_PORT) || (PortNum >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the pin direction as required */
		switch (PortNum)
		{
		case GPIO_PORTA:
			if (value == LOGIC_HIGH)
			{
				SET_BIT(PORTA, PinNum);
			}
			else
			{
				CLEAR_BIT(PORTA, PinNum);
			}
			break;

		case GPIO_PORTB:
			if (value == LOGIC_HIGH)
			{
				SET_BIT(PORTB, PinNum);
			}
			else
			{
				CLEAR_BIT(PORTB, PinNum);
			}
			break;

		case GPIO_PORTC:
			if (value == PIN_OUTPUT)
			{
				SET_BIT(PORTC, PinNum);
			}
			else
			{
				CLEAR_BIT(PORTC, PinNum);
			}
			break;

		case GPIO_PORTD:
			if (value == PIN_OUTPUT)
			{
				SET_BIT(PORTD, PinNum);
			}
			else
			{
				CLEAR_BIT(PORTD, PinNum);
			}
			break;
		}
	}

}




/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8 GPIO_ReadPin(uint8 PortNum, uint8 PinNum) {

	uint8 PinValue = LOGIC_LOW;
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if ((PinNum >= NUM_OF_PINS_PER_PORT) || (PortNum >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		switch (PortNum) {

		case GPIO_PORTA:
			if (READ_BIT(PINA, PinNum)) {
				PinValue = LOGIC_HIGH;
			}
			else {
				PinValue = LOGIC_LOW;
			}
			break;

		case GPIO_PORTB:
			if (READ_BIT(PINB, PinNum)) {
				PinValue = LOGIC_HIGH;
			}
			else {
				PinValue = LOGIC_LOW;
			}
			break;

		case GPIO_PORTC:
			if (READ_BIT(PINA, PinNum)) {
				PinValue = LOGIC_HIGH;
			}
			else {
				PinValue = LOGIC_LOW;
			}
			break;

		case GPIO_PORTD:
			if (READ_BIT(PINA, PinNum)) {
				PinValue = LOGIC_HIGH;
			}
			else {
				PinValue = LOGIC_LOW;
			}
			break;
		}
	}

	return PinValue;

}

/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_SetupPortDirectionType(uint8 PortNum, GPIO_PortDirectionType Direction)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if (PortNum >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the port direction as required */
		switch (PortNum)
		{
		case GPIO_PORTA:
			DDRA = Direction;
			break;
		case GPIO_PORTB:
			DDRB = Direction;
			break;
		case GPIO_PORTC:
			DDRC = Direction;
			break;
		case GPIO_PORTD:
			DDRD = Direction;
			break;
		}
	}
}


/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_WritePort(uint8 PortNum, uint8 value)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if (PortNum >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Write the port value as required */
		switch (PortNum)
		{
		case GPIO_PORTA:
			PORTA = value;
			break;
		case GPIO_PORTB:
			PORTB = value;
			break;
		case GPIO_PORTC:
			PORTC = value;
			break;
		case GPIO_PORTD:
			PORTD = value;
			break;
		}
	}
}

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
uint8 GPIO_ReadPort(uint8 port_num)
{
	uint8 value = LOGIC_LOW;

	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if (port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Read the port value as required */
		switch (port_num)
		{
		case PORTA_ID:
			value = PINA;
			break;
		case PORTB_ID:
			value = PINB;
			break;
		case PORTC_ID:
			value = PINC;
			break;
		case PORTD_ID:
			value = PIND;
			break;
		}
	}

	return value;
}
