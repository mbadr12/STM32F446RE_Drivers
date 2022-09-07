/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL 			    *************************/
/*************************		SWC: 	Systick				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#include "STD_TYPES.h"
#include "STM32F446xx.h"

#include "STK_Interface.h"


/*****************************************************************************************
 * Function Name:  STK_vDelayMS
 *
 * Description:	the function Makes A delay
 *
 * Parameters: 1- Copy_u32DelayMS: The required Delay Time in MS
 *
 * Return:	No Return
 *
 *****************************************************************************************/
void STK_vDelayMS(u32 Copy_u32DelayMS)
{
	/*1- Load the value of Delay*/
	STK_LOAD=Copy_u32DelayMS*2000UL;
	/*2- Clear current value.*/
	STK_VAL=0;
	/*3- Choose Clock Source*/
	STK_CTRL &= ~(1<<2);
	/*4- Enable Counter*/
	STK_CTRL |= 1;
	/*5- Busy waiting until Counter is zero*/
	while(((STK_CTRL>>16)&1) == 0);
}
