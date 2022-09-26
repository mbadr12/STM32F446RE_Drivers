/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL 			    *************************/
/*************************		SWC: 	DMA 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

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
u8 DMA_u8Init(DMA_Config_t* Copy_pDMAconfig);

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
u8 DMA_u8StreamStart(u32* Copy_Pu32SourceAddress, u32* Copy_Pu32DistnationAddress, u16 Copy_u16BlockLength);

typedef enum
{
	DMA_1,
	DMA_2
}DMA_Num;

typedef enum
{
	DMA_DIRECT,
	DMA_FIFO
}DMA_Mode;

typedef enum
{
	DMA_STREAM_0,
	DMA_STREAM_1,
	DMA_STREAM_2,
	DMA_STREAM_3,
	DMA_STREAM_4,
	DMA_STREAM_5,
	DMA_STREAM_6,
	DMA_STREAM_7,
}DMA_Stream;

typedef enum
{
	DMA_CHANNEL_0,
	DMA_CHANNEL_1,
	DMA_CHANNEL_2,
	DMA_CHANNEL_3,
	DMA_CHANNEL_4,
	DMA_CHANNEL_5,
	DMA_CHANNEL_6,
	DMA_CHANNEL_7
}DMA_Channel;

typedef enum
{
	PERIPHERAL_TO_MEMORY,
	MEMORY_TO_PERIPHERAL,
	MEMORY_TO_MEMORY
}DMA_DataDir;

typedef enum
{
	DMA_LOW_PR,
	DMA_MEDIUM_PR,
	DMA_HIGH_PR,
	DMA_VERY_HIGH_PR,
}DMA_StreamPriority;

typedef enum
{
	SINGLE_TRANSFER,
	INCR4,
	INCR8,
	INCR16
}DMA_DataTransfer_t;

typedef enum
{
	BYTE,
	HALF_WORD,
	WORD,
}DMA_DataSize;

typedef enum
{
	MEM_FIXED_PRPH_FIXED,
	MEM_FIXED_INC_FIXED,
	MEM_INC_PRPH_FIXED,
	MEM_INC_PRPH_INC
}DMA_IncMode;

typedef enum
{
	ONE_TRANSFER,
	CIRCULAR_TRANSFER
}DMA_Transfer_t;

typedef enum
{
	FIFO_QUARTER_FULL,
	FIFO_HAF_FULL,
	FIFO_THREE_QUARTERs_FULL,
	FIFO_FULL,
}DMA_FifoSize;

typedef struct
{
	DMA_Num DMA_Number;
	DMA_Stream Stream;
	DMA_Channel Channel;
	DMA_Mode Mode;
	DMA_DataDir DataDirection;
	DMA_StreamPriority Priority;
	DMA_DataTransfer_t DataType;
	DMA_DataSize DataSize;
	DMA_IncMode MemPrphIncMode;
	DMA_Transfer_t TransferType;
	DMA_FifoSize FifoThreshold;
	void (* CallBackFunc)(void);
}DMA_Config_t;


#endif /* DMA_INTERFACE_H_ */
