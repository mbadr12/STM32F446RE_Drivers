/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	EXTI 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum
{
	EXTI_PORTA,
	EXTI_PORTB,
	EXTI_PORTC,
	EXTI_PORTD,
	EXTI_PORTE,
	EXTI_PORTF,
	EXTI_PORTG,
	EXTI_PORTH
}EXTI_Port_t;

typedef enum
{
	EXTI_PIN0,
	EXTI_PIN1,
	EXTI_PIN2,
	EXTI_PIN3,
	EXTI_PIN4,
	EXTI_PIN5,
	EXTI_PIN6,
	EXTI_PIN7,
	EXTI_PIN8,
	EXTI_PIN9,
	EXTI_PIN10,
	EXTI_PIN11,
	EXTI_PIN12,
	EXTI_PIN13,
	EXTI_PIN14,
	EXTI_PIN15
}EXTI_Pin_t;

typedef enum
{
	EXTI_RAISING_TRIGGER,
	EXTI_FALLING_TRIGGER,
	EXTI_RIS_FALL_TRIGGER
}Trigger_t;

typedef struct
{
	EXTI_Port_t Port;
	EXTI_Pin_t Pin;
	Trigger_t Trigger;
	void(*CallBackFunc)(void);
}EXTI_PinConfig_t;

/*****************************************************************************************
 * Function Name: EXTI_u8PinInit
 *
 * Description: The Function Initializes the Required Pin Configuration options for EXTI
 *
 * Parameters: 1- Copy_PinConfig: const pointer to EXTI_PinConfig_t structure which holds the configurations
 *
 * Return:	ErrorState , Type:u8
 *
 *****************************************************************************************/
u8 EXTI_u8PinInit(const EXTI_PinConfig_t* Copy_PinConfig);

/*****************************************************************************************
 * Function Name: EXTI_voidClearPendingFlag
 *
 * Description: The Function clears the pending flag
 *
 * Parameters: 1- Copy_Pin: the required pin wanted to be clear its pending flag
 *
 * Return:	No return
 *
 *****************************************************************************************/
void EXTI_voidClearPendingFlag(EXTI_Pin_t Copy_Pin);

/*****************************************************************************************
 * Function Name: EXTI_voidIntEnable
 *
 * Description: The Function enables the PIE of the required pin
 *
 * Parameters: 1- Copy_Pin: the required pin wanted to set its PIE
 *
 * Return:	No return
 *
 *****************************************************************************************/
void EXTI_voidIntEnable(EXTI_Pin_t Copy_Pin);

/*****************************************************************************************
 * Function Name: EXTI_voidIntDisable
 *
 * Description: The Function disables the PIE of the required pin
 *
 * Parameters: 1- Copy_Pin: the required pin wanted to clear its PIE
 *
 * Return:	No return
 *
 *****************************************************************************************/
void EXTI_voidIntDisable(EXTI_Pin_t Copy_Pin);

#endif /* EXTI_INTERFACE_H_ */
