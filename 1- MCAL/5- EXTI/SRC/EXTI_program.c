/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	EXTI 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/
#include "STD_TYPES.h"
#include "STM32F446xx.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"

/*Global Array of Pointers to function to take The CallBack Functions*/
static void (*CallBackFuncArr[EXTI_NUM])(void)={NULL};

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
u8 EXTI_u8PinInit(const EXTI_PinConfig_t* Copy_PinConfig)
{
	u8 Local_ErrorState=OK;
	if(Copy_PinConfig == NULL)
	{
		Local_ErrorState=NULL_POINTER;
	}
	else
	{
		/*Choose The Port to Have the EXTI*/
		u8 Local_u8IntCnfgReg = Copy_PinConfig->Pin / EXTI_REGISTER_SELECTOR;
		u8 Local_u8IntCnfgBit = (Copy_PinConfig->Pin % EXTI_Bit_SELECTOR);
		SYSCFG->EXTICR[Local_u8IntCnfgReg] &= ~(EXTI_PORT_MASK<<(Local_u8IntCnfgBit*4));
		SYSCFG->EXTICR[Local_u8IntCnfgReg] |= ((Copy_PinConfig->Port)<<(Local_u8IntCnfgBit*4));
		/*Choose Trigger Type*/
		switch(Copy_PinConfig->Trigger)
		{
		case EXTI_RAISING_TRIGGER: EXTI->RTSR |= 1<< Copy_PinConfig->Pin;
								   EXTI->FTSR &= ~(1<< Copy_PinConfig->Pin); break;
		case EXTI_FALLING_TRIGGER: EXTI->FTSR |= 1<< Copy_PinConfig->Pin;
								   EXTI->RTSR &= ~(1<< Copy_PinConfig->Pin); break;
		case EXTI_RIS_FALL_TRIGGER: EXTI->RTSR |= 1<< Copy_PinConfig->Pin;
									EXTI->FTSR |= 1<< Copy_PinConfig->Pin; break;
		default: Local_ErrorState = NOK;
		}
		/*Pass the CallBack Function to The Global Array*/
		CallBackFuncArr[Copy_PinConfig->Pin] = Copy_PinConfig->CallBackFunc;
		/*Enable EXTI Interrupt for the selected pin*/
		EXTI_voidIntEnable(Copy_PinConfig->Pin);
	}
	return Local_ErrorState;
}

/*****************************************************************************************
 * Function Name: EXTI_u8GetPendingFlag
 *
 * Description: The Function Get the pin of raised flag
 *
 * Parameters: No parametars
 *
 * Return:	Local_u8EXTIIterator , Type:u8
 *
 *****************************************************************************************/
u8 EXTI_u8GetPendingFlag(void)
{
	u8 Local_u8EXTIIterator=0;
	u8 Local_u8PendingState=0;
	for(Local_u8EXTIIterator=EXTI_PIN5 ; Local_u8EXTIIterator <= EXTI_PIN15 ; Local_u8EXTIIterator++)
	{
		Local_u8PendingState=(((EXTI->PR)>>Local_u8EXTIIterator) & 1);
		if(Local_u8PendingState == 1)
		{
			return Local_u8EXTIIterator;
		}
	}
	return -1;
}

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
void EXTI_voidClearPendingFlag(EXTI_Pin_t Copy_Pin)
{
	/*Clear Pending Flag*/
	EXTI->PR = 1<<Copy_Pin;
}

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
void EXTI_voidIntEnable(EXTI_Pin_t Copy_Pin)
{
	EXTI->IMR |= 1<<Copy_Pin;
}

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
void EXTI_voidIntDisable(EXTI_Pin_t Copy_Pin)
{
	EXTI->IMR &= ~(1<<Copy_Pin);
}

void EXTI0_IRQHandler (void)
{
	/*Make Sure That CallBack Function No Null*/
	if(CallBackFuncArr[EXTI_PIN0] !=NULL)
	{
		/*Call The Call Back Function*/
		CallBackFuncArr[EXTI_PIN0]();
		/*Clear Pending Flag*/
		EXTI_voidClearPendingFlag(EXTI_PIN0);
	}
	else
	{
		/*Do Nothing*/
	}
}

void EXTI1_IRQHandler (void)
{
	/*Make Sure That CallBack Function No Null*/
	if(CallBackFuncArr[EXTI_PIN1] !=NULL)
	{
		/*Call The Call Back Function*/
		CallBackFuncArr[EXTI_PIN1]();
		/*Clear Pending Flag*/
		EXTI_voidClearPendingFlag(EXTI_PIN1);
	}
	else
	{
		/*Do Nothing*/
	}
}

void EXTI2_IRQHandler (void)
{
	/*Make Sure That CallBack Function No Null*/
	if(CallBackFuncArr[EXTI_PIN2] !=NULL)
	{
		/*Call The Call Back Function*/
		CallBackFuncArr[EXTI_PIN2]();
		/*Clear Pending Flag*/
		EXTI_voidClearPendingFlag(EXTI_PIN2);
	}
	else
	{
		/*Do Nothing*/
	}
}

void EXTI3_IRQHandler (void)
{
	/*Make Sure That CallBack Function No Null*/
	if(CallBackFuncArr[EXTI_PIN3] !=NULL)
	{
		/*Call The Call Back Function*/
		CallBackFuncArr[EXTI_PIN3]();
		/*Clear Pending Flag*/
		EXTI_voidClearPendingFlag(EXTI_PIN3);
	}
	else
	{
		/*Do Nothing*/
	}
}

void EXTI4_IRQHandler (void)
{
	/*Make Sure That CallBack Function No Null*/
	if(CallBackFuncArr[EXTI_PIN4] !=NULL)
	{
		/*Call The Call Back Function*/
		CallBackFuncArr[EXTI_PIN4]();
		/*Clear Pending Flag*/
		EXTI_voidClearPendingFlag(EXTI_PIN4);
	}
	else
	{
		/*Do Nothing*/
	}
}

void EXTI9_5_IRQHandler (void)
{
	/*Get to Know the pin caused the handler*/
	u8 Local_u8EXTINum= EXTI_u8GetPendingFlag();
	/*Make Sure That CallBack Function No Null*/
	if(CallBackFuncArr[Local_u8EXTINum] !=NULL)
	{
		/*Call The Call Back Function*/
		CallBackFuncArr[Local_u8EXTINum]();
		/*Clear Pending Flag*/
		EXTI_voidClearPendingFlag(Local_u8EXTINum);
	}
	else
	{
		/*Do Nothing*/
	}
}

void EXTI15_10_IRQHandler(void)
{
	/*Get to Know the pin caused the handler*/
	u8 Local_u8EXTINum= EXTI_u8GetPendingFlag();
	/*Make Sure That CallBack Function No Null*/
	if(CallBackFuncArr[Local_u8EXTINum] !=NULL)
	{
		/*Call The Call Back Function*/
		CallBackFuncArr[Local_u8EXTINum]();
		/*Clear Pending Flag*/
		EXTI_voidClearPendingFlag(Local_u8EXTINum);
	}
	else
	{
		/*Do Nothing*/
	}
}
