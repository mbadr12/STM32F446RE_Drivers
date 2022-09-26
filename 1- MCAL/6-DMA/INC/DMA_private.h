/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL 			    *************************/
/*************************		SWC: 	DMA 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

#define DMA_NUM								2

#define STREAM_NUM							8

#define EN									0

#define PL_SHIFT							16

#define DMDIS_SHIFT							2

#define PBURST_SHIFT						21

#define MBURST_SHIFT						23

#define DIR_SHIFT							6

#define PINC_SHIFT							9

#define PSIZE_SHIFT							11

#define MSIZE_SHIFT							13

#define CIRC_SHIFT							8

#define TCIE_SHIFT							4

#define FTH_MASK							(u32)(~(11))

#define CHSEL_SHIFT							25

#define CTCIF0								5

#define CTCIF1								11

#define CTCIF2								21

#define CTCIF3								27

#define CTCIF4								5

#define CTCIF5								11

#define CTCIF6								21

#define CTCIF7								27

#define	DMA_NUMBER							Copy_pDMAconfig->DMA_Number

#define STREAM_NUMBER						Copy_pDMAconfig->Stream

#define GET_STREAM_STATE					((DMAArr[DMA_NUMBER]->Stream[STREAM_NUMBER].CR)&1)

#define STREAM_CONTROL_REGISTER				DMAArr[DMA_NUMBER]->Stream[STREAM_NUMBER].CR

#define STREAM_FIFO_CONTROL_REGISTER		DMAArr[DMA_NUMBER]->Stream[STREAM_NUMBER].FCR

#define STREAM_PRPH_ADD_REGISTER			DMAArr[DMA_u8Number]->Stream[DMA_u8StreamNum].PAR

#define STREAM_MEM0_ADD_REGISTER			DMAArr[DMA_u8Number]->Stream[DMA_u8StreamNum].M0AR

#define STREAM_NUM_OF_DATA_REGISTER			DMAArr[DMA_u8Number]->Stream[DMA_u8StreamNum].NDTR

#endif /* DMA_PRIVATE_H_ */
