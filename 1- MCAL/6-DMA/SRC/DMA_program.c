/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL 			    *************************/
/*************************		SWC: 	DMA 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#include "STD_TYPES.h"
#include "STM32F446xx.h"

#include "DMA_interface.h"
#include "DMA_private.h"

/*Array of DMA Peripherals*/
static DMA_RegDef_t* DMAArr[DMA_NUM]={DMA1, DMA2};

/*Global Variables to take some Configurations*/
static u8 DMA_u8Number;
static u8 DMA_u8StreamNum;
static u8 DMA_u8TrnsDir;

/*Two Arrays of Global pointer to Functions*/
static void (* DMA1_pvCallBackFuncArr[STREAM_NUM])(void)={NULL};
static void (* DMA2_pvCallBackFuncArr[STREAM_NUM])(void)={NULL};

/*****************************************************************************************
 * Function Name: DMA_u8Init
 *
 * Description: The Function Set the Required configurations to use the DMA
 *
 * Parameters: 1- Copy_pDMAconfig: pointer to structure with the required configuration
 *
 * Return:	ErrorState , Type:u8
 *
 *****************************************************************************************/
u8 DMA_u8Init(DMA_Config_t* Copy_pDMAconfig)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_pDMAconfig == NULL)
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	else
	{
		/*Reset the control Register & disable Stream*/
		STREAM_CONTROL_REGISTER = 0;
		/*wait to make sure that stream is disabled*/
		while(GET_STREAM_STATE == 1);
		/*select the channel*/
		STREAM_CONTROL_REGISTER |= (Copy_pDMAconfig->Channel) << CHSEL_SHIFT;
		/*Configure the Stream priority*/
		STREAM_CONTROL_REGISTER |= (Copy_pDMAconfig->Priority) << PL_SHIFT;
		/*Choose mode of DMA*/
		switch(Copy_pDMAconfig->Mode)
		{
		case DMA_DIRECT: STREAM_FIFO_CONTROL_REGISTER &= ~(1<<DMDIS_SHIFT); break;
		case DMA_FIFO: STREAM_FIFO_CONTROL_REGISTER |= 1<<DMDIS_SHIFT;
		/*choose the FIFO Threshold*/
		STREAM_FIFO_CONTROL_REGISTER &= FTH_MASK; STREAM_FIFO_CONTROL_REGISTER |= Copy_pDMAconfig->FifoThreshold;
		/*Choose data transfer type*/
		STREAM_CONTROL_REGISTER |= ((Copy_pDMAconfig->DataType)<<PBURST_SHIFT) | ((Copy_pDMAconfig->DataType)<<MBURST_SHIFT);
		break;
		default: Local_u8ErrorState = NOK;
		}
		/*Choose the data transfer Direction*/
		STREAM_CONTROL_REGISTER |= (Copy_pDMAconfig->DataDirection) << DIR_SHIFT;
		/*Choose transfer type*/
		STREAM_CONTROL_REGISTER |= (Copy_pDMAconfig->TransferType) << CIRC_SHIFT;
		/*Choose increment mode*/
		STREAM_CONTROL_REGISTER |= (Copy_pDMAconfig->MemPrphIncMode) << PINC_SHIFT;
		/*choose Data size*/
		STREAM_CONTROL_REGISTER |= ((Copy_pDMAconfig->DataSize)<<PSIZE_SHIFT) | ((Copy_pDMAconfig->DataSize)<<MSIZE_SHIFT);
		/*Enable Interrupt Transfer Complete*/
		STREAM_CONTROL_REGISTER |= 1 << TCIE_SHIFT;
		/*Pass the CallBack Function To Global Pointer To Function*/
		switch(Copy_pDMAconfig->DMA_Number)
		{
		case DMA_1: DMA1_pvCallBackFuncArr[STREAM_NUMBER] = Copy_pDMAconfig->CallBackFunc; break;
		case DMA_2: DMA2_pvCallBackFuncArr[STREAM_NUMBER] = Copy_pDMAconfig->CallBackFunc; break;
		}
		/*Pass DMA number and Stream Number and transfer Direction to Global Variables*/
		DMA_u8StreamNum = Copy_pDMAconfig->Stream;
		DMA_u8Number = Copy_pDMAconfig->DMA_Number;
		DMA_u8TrnsDir = Copy_pDMAconfig->DataDirection;
	}
	return Local_u8ErrorState;
}

/*****************************************************************************************
 * Function Name: DMA_u8StreamStart
 *
 * Description: The Function Starts the stream and Data sending
 *
 * Parameters: 1- Copy_Pu32SourceAddress: pointer to u32 takes the source address
 * 			   2- Copy_Pu32DistnationAddress: pointer to u32 takes the Destination address
 *			   3- Copy_u16BlockLength: The length of Data will be sent
 *
 * Return:	ErrorState , Type:u8
 *
 *****************************************************************************************/
u8 DMA_u8StreamStart(u32* Copy_Pu32SourceAddress, u32* Copy_Pu32DistnationAddress, u16 Copy_u16BlockLength)
{
	u8 Local_u8ErrorState;
	if(Copy_Pu32DistnationAddress == NULL || Copy_Pu32SourceAddress == NULL)
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	else
	{
		/*copy the source and destination addresses to M0AR & PAR according to data direction*/
		switch(DMA_u8TrnsDir)
		{
		case MEMORY_TO_MEMORY:
		case PERIPHERAL_TO_MEMORY: STREAM_PRPH_ADD_REGISTER = Copy_Pu32SourceAddress;
		STREAM_MEM0_ADD_REGISTER = Copy_Pu32DistnationAddress; break;
		case MEMORY_TO_PERIPHERAL: STREAM_MEM0_ADD_REGISTER = Copy_Pu32SourceAddress;
		STREAM_PRPH_ADD_REGISTER = Copy_Pu32DistnationAddress; break;
		}
		/*copy the Block length to NDTR*/
		STREAM_NUM_OF_DATA_REGISTER = Copy_u16BlockLength;
		/*Turn on Stream*/
		DMAArr[DMA_u8Number]->Stream[DMA_u8StreamNum].CR |= 1 << EN;
	}
	return Local_u8ErrorState;
}

/*DMA1 Streams IRQ handlers*/
void DMA1_Stream0_IRQHandler(void)
{
	/*Invoke The CallBack Function*/
	if(DMA1_pvCallBackFuncArr[DMA_STREAM_0] != NULL)
	{
		DMA1_pvCallBackFuncArr[DMA_STREAM_0]();
	}
	/*Clear the transfer complete Interrupt Flag*/
	DMA1->LIFCR = 1 << CTCIF0;
}

void DMA1_Stream1_IRQHandler(void)
{
	/*Invoke The CallBack Function*/
	if(DMA1_pvCallBackFuncArr[DMA_STREAM_1] != NULL)
	{
		DMA1_pvCallBackFuncArr[DMA_STREAM_1]();
	}
	/*Clear the transfer complete Interrupt Flag*/
	DMA1->LIFCR = 1 << CTCIF1;
}

void DMA1_Stream2_IRQHandler(void)
{
	/*Invoke The CallBack Function*/
	if(DMA1_pvCallBackFuncArr[DMA_STREAM_2] != NULL)
	{
		DMA1_pvCallBackFuncArr[DMA_STREAM_2]();
	}
	/*Clear the transfer complete Interrupt Flag*/
	DMA1->LIFCR = 1 << CTCIF2;
}

void DMA1_Stream3_IRQHandler(void)
{
	/*Invoke The CallBack Function*/
	if(DMA1_pvCallBackFuncArr[DMA_STREAM_3] != NULL)
	{
		DMA1_pvCallBackFuncArr[DMA_STREAM_3]();
	}
	/*Clear the transfer complete Interrupt Flag*/
	DMA1->LIFCR = 1 << CTCIF3;
}

void DMA1_Stream4_IRQHandler(void)
{
	/*Invoke The CallBack Function*/
	if(DMA1_pvCallBackFuncArr[DMA_STREAM_4] != NULL)
	{
		DMA1_pvCallBackFuncArr[DMA_STREAM_4]();
	}
	/*Clear the transfer complete Interrupt Flag*/
	DMA1->HIFCR = 1 << CTCIF4;
}

void DMA1_Stream5_IRQHandler(void)
{
	/*Invoke The CallBack Function*/
	if(DMA1_pvCallBackFuncArr[DMA_STREAM_5] != NULL)
	{
		DMA1_pvCallBackFuncArr[DMA_STREAM_5]();
	}
	/*Clear the transfer complete Interrupt Flag*/
	DMA1->HIFCR = 1 << CTCIF5;
}

void DMA1_Stream6_IRQHandler(void)
{
	/*Invoke The CallBack Function*/
	if(DMA1_pvCallBackFuncArr[DMA_STREAM_6] != NULL)
	{
		DMA1_pvCallBackFuncArr[DMA_STREAM_6]();
	}
	/*Clear the transfer complete Interrupt Flag*/
	DMA1->HIFCR = 1 << CTCIF6;
}

void DMA1_Stream7_IRQHandler(void)
{
	/*Invoke The CallBack Function*/
	if(DMA1_pvCallBackFuncArr[DMA_STREAM_7] != NULL)
	{
		DMA1_pvCallBackFuncArr[DMA_STREAM_7]();
	}
	/*Clear the transfer complete Interrupt Flag*/
	DMA1->HIFCR = 1 << CTCIF7;
}

/*DMA2 Streams IRQ handlers*/
void DMA2_Stream0_IRQHandler(void)
{
	/*Invoke The CallBack Function*/
	if(DMA2_pvCallBackFuncArr[DMA_STREAM_0] != NULL)
	{
		DMA2_pvCallBackFuncArr[DMA_STREAM_0]();
	}
	/*Clear the transfer complete Interrupt Flag*/
	DMA2->LIFCR = 1 << CTCIF0;
}

void DMA2_Stream1_IRQHandler(void)
{
	/*Invoke The CallBack Function*/
	if(DMA2_pvCallBackFuncArr[DMA_STREAM_1] != NULL)
	{
		DMA2_pvCallBackFuncArr[DMA_STREAM_1]();
	}
	/*Clear the transfer complete Interrupt Flag*/
	DMA2->LIFCR = 1 << CTCIF1;
}

void DMA2_Stream2_IRQHandler(void)
{
	/*Invoke The CallBack Function*/
	if(DMA2_pvCallBackFuncArr[DMA_STREAM_2] != NULL)
	{
		DMA2_pvCallBackFuncArr[DMA_STREAM_2]();
	}
	/*Clear the transfer complete Interrupt Flag*/
	DMA2->LIFCR = 1 << CTCIF2;
}

void DMA2_Stream3_IRQHandler(void)
{
	/*Invoke The CallBack Function*/
	if(DMA2_pvCallBackFuncArr[DMA_STREAM_3] != NULL)
	{
		DMA2_pvCallBackFuncArr[DMA_STREAM_3]();
	}
	/*Clear the transfer complete Interrupt Flag*/
	DMA2->LIFCR = 1 << CTCIF3;
}

void DMA2_Stream4_IRQHandler(void)
{
	/*Invoke The CallBack Function*/
	if(DMA2_pvCallBackFuncArr[DMA_STREAM_4] != NULL)
	{
		DMA2_pvCallBackFuncArr[DMA_STREAM_4]();
	}
	/*Clear the transfer complete Interrupt Flag*/
	DMA2->HIFCR = 1 << CTCIF4;
}

void DMA2_Stream5_IRQHandler(void)
{
	/*Invoke The CallBack Function*/
	if(DMA2_pvCallBackFuncArr[DMA_STREAM_5] != NULL)
	{
		DMA2_pvCallBackFuncArr[DMA_STREAM_5]();
	}
	/*Clear the transfer complete Interrupt Flag*/
	DMA2->HIFCR = 1 << CTCIF5;
}

void DMA2_Stream6_IRQHandler(void)
{
	/*Invoke The CallBack Function*/
	if(DMA2_pvCallBackFuncArr[DMA_STREAM_6] != NULL)
	{
		DMA2_pvCallBackFuncArr[DMA_STREAM_6]();
	}
	/*Clear the transfer complete Interrupt Flag*/
	DMA2->HIFCR = 1 << CTCIF6;
}

void DMA2_Stream7_IRQHandler(void)
{
	/*Invoke The CallBack Function*/
	if(DMA2_pvCallBackFuncArr[DMA_STREAM_7] != NULL)
	{
		DMA2_pvCallBackFuncArr[DMA_STREAM_7]();
	}
	/*Clear the transfer complete Interrupt Flag*/
	DMA2->HIFCR = 1 << CTCIF7;
}
