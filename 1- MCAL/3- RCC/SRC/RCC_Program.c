/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	RCC 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#include "STD_TYPES.h"
#include "STM32F446xx.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "RCC_private.h"
#include "RCC_Config.h"

/*****************************************************************************************
 * Function Name:  RCC_u8AHB1EnablePeripheralClock
 *
 * Description:	the function Enables peripheral clock connected to AHB1
 *
 * Parameters: 1- Copy_u8PeripheralId: The required peripheral wanted to be Enabled
 *
 * Return:	ErrorState , Type:u8
 *
 *****************************************************************************************/
u8 RCC_u8AHB1EnablePeripheralClock(u8 Copy_u8PeripheralId)
{
	u8 Local_u8StateError=OK;
	if((Copy_u8PeripheralId>31) || (Copy_u8PeripheralId<0))
	{
		Local_u8StateError=NOK;
	}
	else
	{
		SET_BIT(RCC->AHB1ENR,Copy_u8PeripheralId);
	}
	return Local_u8StateError;
}

/*****************************************************************************************
 * Function Name:  RCC_u8AHB1DisablePeripheralClock
 *
 * Description:	the function Disables peripheral clock connected to AHB1
 *
 * Parameters: 1- Copy_u8PeripheralId: The required peripheral wanted to be Disabled
 *
 * Return:	ErrorState , Type:u8
 *
 *****************************************************************************************/
u8 RCC_u8AHB1DisablePeripheralClock(u8 Copy_u8PeripheralId)
{
	u8 Local_u8StateError=OK;
	if((Copy_u8PeripheralId>31) || (Copy_u8PeripheralId<0))
	{
		Local_u8StateError=NOK;
	}
	else
	{
		CLR_BIT(RCC->AHB1ENR,Copy_u8PeripheralId);
	}
	return Local_u8StateError;
}

/*****************************************************************************************
 * Function Name:  RCC_u8AHB2EnablePeripheralClock
 *
 * Description:	the function Enables peripheral clock connected to AHB2
 *
 * Parameters: 1- Copy_u8PeripheralId: The required peripheral wanted to be Enabled
 *
 * Return:	ErrorState , Type:u8
 *
 *****************************************************************************************/
u8 RCC_u8AHB2EnablePeripheralClock(u8 Copy_u8PeripheralId)
{
	u8 Local_u8StateError=OK;
	if((Copy_u8PeripheralId>31) || (Copy_u8PeripheralId<0))
	{
		Local_u8StateError=NOK;
	}
	else
	{
		SET_BIT(RCC->AHB2ENR,Copy_u8PeripheralId);
	}
	return Local_u8StateError;
}

/*****************************************************************************************
 * Function Name:  RCC_u8AHB1DisablePeripheralClock
 *
 * Description:	the function Disables peripheral clock connected to AHB2
 *
 * Parameters: 1- Copy_u8PeripheralId: The required peripheral wanted to be Disabled
 *
 * Return:	ErrorState , Type:u8
 *
 *****************************************************************************************/
u8 RCC_u8AHB2DisablePeripheralClock(u8 Copy_u8PeripheralId)
{
	u8 Local_u8StateError=OK;
	if((Copy_u8PeripheralId>31) || (Copy_u8PeripheralId<0))
	{
		Local_u8StateError=NOK;
	}
	else
	{
		CLR_BIT(RCC->AHB2ENR,Copy_u8PeripheralId);
	}
	return Local_u8StateError;
}

/*****************************************************************************************
 * Function Name:  RCC_u8APB1EnablePeripheralClock
 *
 * Description:	the function Enables peripheral clock connected to APB1
 *
 * Parameters: 1- Copy_u8PeripheralId: The required peripheral wanted to be Enabled
 *
 * Return:	ErrorState , Type:u8
 *
 *****************************************************************************************/
u8 RCC_u8APB1EnablePeripheralClock(u8 Copy_u8PeripheralId)
{
	u8 Local_u8StateError=OK;
	if((Copy_u8PeripheralId>31) || (Copy_u8PeripheralId<0))
	{
		Local_u8StateError=NOK;
	}
	else
	{
		SET_BIT(RCC->APB1ENR,Copy_u8PeripheralId);
	}
	return Local_u8StateError;
}

/*****************************************************************************************
 * Function Name:  RCC_u8APB1DisablePeripheralClock
 *
 * Description:	the function Disables peripheral clock connected to APB1
 *
 * Parameters: 1- Copy_u8PeripheralId: The required peripheral wanted to be Disabled
 *
 * Return:	ErrorState , Type:u8
 *
 *****************************************************************************************/
u8 RCC_u8APB1DisablePeripheralClock(u8 Copy_u8PeripheralId)
{
	u8 Local_u8StateError=OK;
	if((Copy_u8PeripheralId>31) || (Copy_u8PeripheralId<0))
	{
		Local_u8StateError=NOK;
	}
	else
	{
		CLR_BIT(RCC->APB1ENR,Copy_u8PeripheralId);
	}
	return Local_u8StateError;
}

/*****************************************************************************************
 * Function Name:  RCC_u8APB2EnablePeripheralClock
 *
 * Description:	the function Enables peripheral clock connected to APB2
 *
 * Parameters: 1- Copy_u8PeripheralId: The required peripheral wanted to be Enabled
 *
 * Return:	ErrorState , Type:u8
 *
 *****************************************************************************************/
u8 RCC_u8APB2EnablePeripheralClock(u8 Copy_u8PeripheralId)
{
	u8 Local_u8StateError=OK;
	if((Copy_u8PeripheralId>31) || (Copy_u8PeripheralId<0))
	{
		Local_u8StateError=NOK;
	}
	else
	{
		SET_BIT(RCC->APB2ENR,Copy_u8PeripheralId);
	}
	return Local_u8StateError;
}

/*****************************************************************************************
 * Function Name:  RCC_u8APB2DisablePeripheralClock
 *
 * Description:	the function Disables peripheral clock connected to APB2
 *
 * Parameters: 1- Copy_u8PeripheralId: The required peripheral wanted to be Disabled
 *
 * Return:	ErrorState , Type:u8
 *
 *****************************************************************************************/
u8 RCC_u8APB2DisablePeripheralClock(u8 Copy_u8PeripheralId)
{
	u8 Local_u8StateError=OK;
	if((Copy_u8PeripheralId>31) || (Copy_u8PeripheralId<0))
	{
		Local_u8StateError=NOK;
	}
	else
	{
		CLR_BIT(RCC->APB2ENR,Copy_u8PeripheralId);
	}
	return Local_u8StateError;
}

/*****************************************************************************************
 * Function Name:  RCC_u8SetCLKStatus
 *
 * Description:	the function Set the required state of the required Clock
 *
 * Parameters: 	1- Copy_u8CLKType: The required clock wanted to be set its state
 * 				2- Copy_u8Status: The state of required Clock (enable / disable)
 *
 * Return:	ErrorState , Type:u8
 *
 *****************************************************************************************/
u8 RCC_u8SetCLKStatus(u8 Copy_u8CLKType,u8 Copy_u8Status)
{
	u8 Local_u8StateError=OK;

	switch(Copy_u8Status)
	{
	case CLK_ON: SET_BIT(RCC->CR,Copy_u8CLKType); while(GET_BIT(RCC->CR,(Copy_u8CLKType+1))==0); break;
	case CLK_OFF: CLR_BIT(RCC->CR,Copy_u8CLKType); while(GET_BIT(RCC->CR,(Copy_u8CLKType+1))==1); break;
	default: Local_u8StateError=NOK; break;
	}
	if(Copy_u8CLKType==HSE_CLK && HSE_Type == HSE_RC)
	{
		SET_BIT(RCC->CR,RCC_CR_HSEBYP);
	}
	return Local_u8StateError;
}

/*****************************************************************************************
 * Function Name:  RCC_u8SetSystemCLKSRC
 *
 * Description:	the function Set the system clock source
 *
 * Parameters: 	1- Copy_u8CLKType: The required clock wanted to be set as system clock
 *
 * Return:	ErrorState , Type:u8
 *
 *****************************************************************************************/
u8 RCC_u8SetSystemCLKSRC(u8 Copy_u8CLKType)
{
	u8 Local_u8StateError=OK;
	if(Copy_u8CLKType>PLL_R_SYS_CLK)
	{
		Local_u8StateError=NOK;
	}
	else
	{
		/*Mask for clearing SW pins*/
		RCC->CFGR &= SYS_CLK_MASK;
		RCC->CFGR |= Copy_u8CLKType;
	}
	return Local_u8StateError;
}
