/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL 			    *************************/
/*************************		SWC: 	GPIO				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

/*Preprocessor File Guard*/
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_


typedef enum
{
	GPIO_PORTA,
	GPIO_PORTB,
	GPIO_PORTC,
	GPIO_PORTD,
	GPIO_PORTE,
	GPIO_PORTF,
	GPIO_PORTG,
	GPIO_PORTH
}GPIO_Port;

typedef enum
{
	GPIO_PIN0,
	GPIO_PIN1,
	GPIO_PIN2,
	GPIO_PIN3,
	GPIO_PIN4,
	GPIO_PIN5,
	GPIO_PIN6,
	GPIO_PIN7,
	GPIO_PIN8,
	GPIO_PIN9,
	GPIO_PIN10,
	GPIO_PIN11,
	GPIO_PIN12,
	GPIO_PIN13,
	GPIO_PIN14,
	GPIO_PIN15
}GPIO_PIN;

typedef enum
{
	PIN_INPUT,
	PIN_OUTPUT,
	PIN_ALTFunc,
	PIN_Analog
}PIN_Mode;

typedef enum
{
	OUTPUT_PUSH_PULL,
	OUTPUT_OPEN_DRAIN
}Output_t;

typedef enum
{
	LOW_SPEED,
	MEDIUM_SPEED,
	FAST_SPEED,
	HIGH_SPEED
}OutputSpeed;

typedef enum
{
	FLOATING,
	PULL_UP,
	PULL_DOWN
}PullUpDown;

typedef enum
{
	AF0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15,
}AltFunOption;

typedef enum
{
	PIN_LOW,
	PIN_HIGH
}PIN_Sate;

typedef struct
{
	u8 Port;                           /*Refer to Port Possible values*/
	u8 PinNum;                         /*Refer to Pin Number Possible values*/
	u8 Mode;                           /*Refer to Mode Possible values*/
	u8 OutputType;                     /*Refer to Output Type Possible values*/
	u8 OutputSpeed;                    /*Refer to Output Speed Possible values*/
	u8 PullUpDown;                     /*Refer to Pull Up / Down Possible values*/
	u8 AlternateFuncOption;            /*Refer to Alternate FuncOption Possible values*/
}PinConfig_t;

/*Common Port Value Possible Options*/
#define Port_LOW	0
#define Port_HigH	0xFFFF

#define NON			50
#define PORT_NUM	8

/*****************************************************************************************
 * Function Name: GPIO_u8PinInit
 *
 * Description: The Function Initializes the Required Pin Configuration options
 *
 * Parameters: 1- PinConfig: const pointer to GPIO_PinConfig_t structure which holds the configurations
 *
 * Return:	ErrorState , Type:u8
 *
 *****************************************************************************************/
u8 GPIO_u8PinInit(const PinConfig_t *Copy_PinConfig);
/*****************************************************************************************/

/*****************************************************************************************
 * Function Name:  GPIO_voidSetPinValue
 *
 * Description:	the function sets an output values on the output pin
 *
 * Parameters: 1- Copy_u8Port : the port of the required output pin, refer to port possible options
 * 			   2- Copy_u8pin  : the pin number of the required output pin, refer to pin number possible options
 * 			   3- Copy_u8value: the required pin state, refer to pin value possible options
 *
 * Return:	ErrorState , Type:u8
 *
 *****************************************************************************************/
u8 GPIO_u8SetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8PinValue);
/****************************************************************************************/

/*****************************************************************************************
 * Function Name:  GPIO_u8SetPortValue
 *
 * Description:	the function sets an output values on the output port
 *
 * Parameters: 1- Copy_u8Port : the the required output port, refer to port possible options
 * 			   3- Copy_u8value: the required pin state, refer to Port value possible options
 *
 * Return:	ErrorState , Type:u8
 *
 *****************************************************************************************/
u8 GPIO_u8SetPortValue(u8 Copy_u8Port,u16 Copy_u16Value);
/****************************************************************************************/

/*****************************************************************************************
 * Function Name:  GPIO_voidReadPinValue
 *
 * Description:	the function Reads an Input value from the input pin
 *
 * Parameters: 1- Copy_u8Port : the port of the required Input pin, refer to port possible options
 * 			   2- Copy_u8pin  : the pin number of the required Input pin, refer to pin number possible options
 * 			   3- Copy_pu8PinValue: pointer to required pin state
 *
 * Return:	ErrorState , Type:u8
 *
 *****************************************************************************************/
u8 GPIO_u8ReadPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8* Copy_pu8PinValue);
/****************************************************************************************/

/*****************************************************************************************
 * Function Name:  GPIO_u8TogglePinValue
 *
 * Description:	the function Toggle an output values on the output pin
 *
 * Parameters: 1- Copy_u8Port : the port of the required output pin, refer to port possible options
 * 			   2- Copy_u8pin  : the pin number of the required output pin, refer to pin number possible options
 *
 * Return:	ErrorState , Type:u8
 *
 *****************************************************************************************/
u8 GPIO_u8TogglePinValue(u8 Copy_u8Port,u8 Copy_u8Pin);
/****************************************************************************************/

#endif
