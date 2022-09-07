/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	NVIC 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#include "STD_TYPES.h"
#include "STM32F446xx.h"

#include "NVIC_Interface.h"

/*****************************************************************************************
 * Function Name: NVIC_u8EnableINT
 *
 * Description: The Function Enable the required IRQ from the NVIC side
 *
 * Parameters: 1- Copy_u8IRQ: The Interrupt request number (Position in vector table)
 *
 * Return:	ErrorState , Type:u8
 *
 *****************************************************************************************/

u8 NVIC_u8EnableINT(u8 Copy_u8IRQ)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8IRQ > FMPI2C1_ERROR_IRQ)
	{
		Local_u8ErrorState=NOK;
	}
	else
	{
		u8 Local_u8RegisterNum = Copy_u8IRQ / 32;
		u8 Local_u8BitNum = (Copy_u8IRQ % 32);
		NVIC->ISER[Local_u8RegisterNum] = 1<<Local_u8BitNum;
	}
	return Local_u8ErrorState;
}

/*****************************************************************************************
 * Function Name: NVIC_u8DisableINT
 *
 * Description: The Function Disable the required IRQ from the NVIC side
 *
 * Parameters: 1- Copy_u8IRQ: The Interrupt request number (Position in vector table)
 *
 * Return:	ErrorState , Type:u8
 *
 *****************************************************************************************/

u8 NVIC_u8DisableINT(u8 Copy_u8IRQ)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8IRQ > FMPI2C1_ERROR_IRQ)
	{
		Local_u8ErrorState=NOK;
	}
	else
	{
		u8 Local_u8RegisterNum = Copy_u8IRQ / 32;
		u8 Local_u8BitNum = (Copy_u8IRQ % 32);
		NVIC->ICER[Local_u8RegisterNum] = 1<<Local_u8BitNum;
	}
	return Local_u8ErrorState;
}

/*****************************************************************************************
 * Function Name: NVIC_u8SetPendingFlag
 *
 * Description: The Function set the Pending flag of the required IRQ from the NVIC side
 *
 * Parameters: 1- Copy_u8IRQ: The Interrupt request number (Position in vector table)
 *
 * Return:	ErrorState , Type:u8
 *
 *****************************************************************************************/
u8 NVIC_u8SetPendingFlag(u8 Copy_u8IRQ)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8IRQ > FMPI2C1_ERROR_IRQ)
	{
		Local_u8ErrorState=NOK;
	}
	else
	{
		u8 Local_u8RegisterNum = Copy_u8IRQ/32;
		u8 Local_u8BitNum = Copy_u8IRQ%32;
		NVIC->ISPR[Local_u8RegisterNum] = 1<<Local_u8BitNum;
	}

	return Local_u8ErrorState;
}

/*****************************************************************************************
 * Function Name: NVIC_u8ClearPendingFlag
 *
 * Description: The Function Clear the Pending flag of the required IRQ from the NVIC side
 *
 * Parameters: 1- Copy_u8IRQ: The Interrupt request number (Position in vector table)
 *
 * Return:	ErrorState , Type:u8
 *
 *****************************************************************************************/
u8 NVIC_u8ClearPendingFlag(u8 Copy_u8IRQ)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8IRQ > FMPI2C1_ERROR_IRQ)
	{
		Local_u8ErrorState=NOK;
	}
	else
	{
		u8 Local_u8RegisterNum = Copy_u8IRQ/32;
		u8 Local_u8BitNum = Copy_u8IRQ%32;
		NVIC->ICPR[Local_u8RegisterNum] = 1<<Local_u8BitNum;
	}

	return Local_u8ErrorState;
}
/*****************************************************************************************
 * Function Name: NVIC_u8SetPriority
 *
 * Description: The Function sets the group and sub priority for the required IRQ
 *
 * Parameters: 1- Copy_u8IRQ: The Interrupt request number (Position in vector table)
 * 			   2- Copy_u8GRPPriority: The Group priority field ,refer to NVIC Group Priority Possible Values
 * 			   3- Copy_u8SubPriority: The Sub priority field ,refer to NVIC Sub Priority Possible Values
 *
 * Return:	ErrorState , Type:u8
 *
 *****************************************************************************************/
u8 NVIC_u8SetPriority(u8 Copy_u8IRQ, u8 Copy_u8GRPPriority, u8 Copy_u8SubPriority)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8IRQ > FMPI2C1_ERROR_IRQ || Copy_u8GRPPriority > NVIC_GPR_PR_3 || Copy_u8SubPriority >NVIC_SUB_PR_3)
	{
		Local_u8ErrorState=NOK;
	}
	else
	{
		u8 Local_u8Priority = (Copy_u8GRPPriority << 6) | (Copy_u8SubPriority << 4) ;
		NVIC->IPR[Copy_u8IRQ] = Local_u8Priority;
	}
	return Local_u8ErrorState;
}

/*****************************************************************************************
 * Function Name: NVIC_u8GetActiveFlag
 *
 * Description: The Function Read the Pending flag of the required IRQ from the NVIC side
 *
 * Parameters: 1- Copy_u8IRQ: The Interrupt request number (Position in vector table)
 * 			   2- Copy_pu8ActiveFlag: Pointer to variable that will hold the read of Active flag
 *
 * Return:	ErrorState , Type:u8
 *
 *****************************************************************************************/
u8 NVIC_u8GetActiveFlag(u8 Copy_u8IRQ , u8* Copy_pu8ActiveFlag)
{
	u8 Local_u8ErrorState=OK;
	if (Copy_pu8ActiveFlag == NULL)
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	else if(Copy_u8IRQ > FMPI2C1_ERROR_IRQ)
	{
		Local_u8ErrorState=NOK;
	}
	else
	{
		u8 Local_u8RegisterNum = Copy_u8IRQ/32;
		u8 Local_u8BitNum = Copy_u8IRQ%32;
		*Copy_pu8ActiveFlag= (NVIC->IABR[Local_u8RegisterNum] >> Local_u8BitNum) & 1;
	}
	return Local_u8ErrorState;
}
