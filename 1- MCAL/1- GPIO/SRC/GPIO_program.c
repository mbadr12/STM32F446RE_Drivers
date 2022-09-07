/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL 			    *************************/
/*************************		SWC: 	GPIO				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#include "STD_TYPES.h"
#include "STM32F446xx.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"

/*Array of Pointers With The GPIO Ports*/
static GPIO_RegDef_t *GPIOPortArr[PORT_NUM]={GPIOA , GPIOB , GPIOC , GPIOD , GPIOE, GPIOF , GPIOG , GPIOH};

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

u8 GPIO_u8PinInit(const PinConfig_t *Copy_PinConfig)
{
	u8 Local_u8ErrorState=OK;
	/*Check For the Pointer*/
	if(Copy_PinConfig != NULL)
	{
		if(Copy_PinConfig->Port < PORT_NUM && Copy_PinConfig->PinNum <= GPIO_PIN15)
		{
			/*1- Set Pin Mode Configuration*/
			GPIOPortArr[Copy_PinConfig->Port]->MODER &= ~(MODE_BIT_MASK << (2*Copy_PinConfig->PinNum));
			GPIOPortArr[Copy_PinConfig->Port]->MODER |= Copy_PinConfig->Mode <<(2*Copy_PinConfig->PinNum);
			/*2- Set Pin Pull Up / Down Configuration*/
			GPIOPortArr[Copy_PinConfig->Port]->PUPDR &= ~(PUD_BIT_MASK<<(2*Copy_PinConfig->PinNum));
			GPIOPortArr[Copy_PinConfig->Port]->PUPDR |= Copy_PinConfig->PullUpDown <<(2*Copy_PinConfig->PinNum);
			if(Copy_PinConfig->Mode == PIN_OUTPUT)
			{
				/*3- Set The Output Type ConfigurationIf the Pin Mode OutPut*/
				switch(Copy_PinConfig->OutputType)
				{
				case OUTPUT_PUSH_PULL: CLR_BIT(GPIOPortArr[Copy_PinConfig->Port]->OTYPER,Copy_PinConfig->PinNum); break;
				case OUTPUT_OPEN_DRAIN: SET_BIT(GPIOPortArr[Copy_PinConfig->Port]->OTYPER,Copy_PinConfig->PinNum); break;
				default: Local_u8ErrorState=NOK;
				}
				/*- Set The Output Speed Configuration If the Pin Mode OutPut*/
				GPIOPortArr[Copy_PinConfig->Port]->OSPEEDER &= ~(SPEED_BIT_MASK<<(2*Copy_PinConfig->PinNum));
				GPIOPortArr[Copy_PinConfig->Port]->OSPEEDER |= Copy_PinConfig->OutputSpeed <<(2*Copy_PinConfig->PinNum);
			}
			if(Copy_PinConfig->Mode == PIN_ALTFunc)
			{
				/*4- Set The Alternative Function Option If the Pin Mode Alternative Function*/
				if(Copy_PinConfig->AlternateFuncOption<8 && Copy_PinConfig->AlternateFuncOption>=0)
				{
					GPIOPortArr[Copy_PinConfig->Port]->AFR[0] &= ~(ALT_FUNC_BIT_MASK << (4*Copy_PinConfig->PinNum));
					GPIOPortArr[Copy_PinConfig->Port]->AFR[0] |= Copy_PinConfig->AlternateFuncOption<<(4*Copy_PinConfig->PinNum);
				}
				else if(Copy_PinConfig->AlternateFuncOption<16 && Copy_PinConfig->AlternateFuncOption>7)
				{
					GPIOPortArr[Copy_PinConfig->Port]->AFR[1] &= ~(ALT_FUNC_BIT_MASK << (4*Copy_PinConfig->PinNum));
					GPIOPortArr[Copy_PinConfig->Port]->AFR[1] |= (Copy_PinConfig->AlternateFuncOption-8)<<(4*Copy_PinConfig->PinNum);
				}
				else
				{
					Local_u8ErrorState=NOK;
				}
			}
		}
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}

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
u8 GPIO_u8SetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8PinValue)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8Port < PORT_NUM && Copy_u8Pin <= GPIO_PIN15)
	{
		CLR_BIT(GPIOPortArr[Copy_u8Port]->ODR,Copy_u8Pin);
		GPIOPortArr[Copy_u8Port]->ODR |= Copy_u8PinValue<<Copy_u8Pin;
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}

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
u8 GPIO_u8SetPortValue(u8 Copy_u8Port,u16 Copy_u16Value)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8Port < PORT_NUM)
	{
		GPIOPortArr[Copy_u8Port]->ODR=Copy_u16Value;
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}

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
u8 GPIO_u8ReadPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8* Copy_pu8PinValue)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_pu8PinValue != NULL)
	{
		if(Copy_u8Port < PORT_NUM && Copy_u8Pin <= GPIO_PIN15)
		{
			*Copy_pu8PinValue = (u8)((GPIOPortArr[Copy_u8Port]->IDR>>Copy_u8Pin)&1);
		}
		else
		{
			Local_u8ErrorState=NOK;
		}
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}

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
u8 GPIO_u8TogglePinValue(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8Port < PORT_NUM && Copy_u8Pin <= GPIO_PIN15)
	{
		GPIOPortArr[Copy_u8Port]->ODR ^= (1<<Copy_u8Pin);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
