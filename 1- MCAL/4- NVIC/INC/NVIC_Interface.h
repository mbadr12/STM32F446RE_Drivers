/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	NVIC 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

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
u8 NVIC_u8EnableINT(u8 Copy_u8IRQ);

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
u8 NVIC_u8DisableINT(u8 Copy_u8IRQ);

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
u8 NVIC_u8SetPendingFlag(u8 Copy_u8IRQ);

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
u8 NVIC_u8ClearPendingFlag(u8 Copy_u8IRQ);

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
u8 NVIC_u8SetPriority(u8 Copy_u8IRQ, u8 Copy_u8GRPPriority, u8 Copy_u8SubPriority);

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
u8 NVIC_u8GetActiveFlag(u8 Copy_u8IRQ , u8* Copy_pu8ActiveFlag);

/*NVIC Group Priority Possible Values*/
#define NVIC_GPR_PR_0				0
#define NVIC_GPR_PR_1               1
#define NVIC_GPR_PR_2               2
#define NVIC_GPR_PR_3               3

/*NVIC Sub Priority Possible Values*/
#define NVIC_SUB_PR_0				0
#define NVIC_SUB_PR_1               1
#define NVIC_SUB_PR_2               2
#define NVIC_SUB_PR_3               3
/*IRQ Numbers*/
typedef enum
{
	WWDG_IRQ,							/*Window Watchdog interrupt*/
	PVD_IRQ,                            /*PVD through EXTI line detection interrupt*/
	TAMP_STAMP_IRQ,                     /*Tamper and TimeStamp interrupts through the EXTI line*/
	RTC_WKUP_IRQ,                       /*RTC Wake up interrupt through the EXTI line*/
	FLASH_IRQ,                          /*Flash global interrupt*/
	RCC_IRQ,                            /*RCC global interrupt*/
	EXTI0_IRQ,                          /*EXTI Line0 interrupt*/
	EXTI1_IRQ,                          /*EXTI Line1 interrupt*/
	EXTI2_IRQ,                          /*EXTI Line2 interrupt*/
	EXTI3_IRQ,                          /*EXTI Line3 interrupt*/
	EXTI4_IRQ,                          /*EXTI Line4 interrupt*/
	DMA1_Stream0_IRQ,                   /*DMA1 Stream0 global interrupt*/
	DMA1_Stream1_IRQ,                   /*DMA1 Stream1 global interrupt*/
	DMA1_Stream2_IRQ,                   /*DMA1 Stream2 global interrupt*/
	DMA1_Stream3_IRQ,                   /*DMA1 Stream3 global interrupt*/
	DMA1_Stream4_IRQ,                   /*DMA1 Stream4 global interrupt*/
	DMA1_Stream5_IRQ,                   /*DMA1 Stream5 global interrupt*/
	DMA1_Stream6_IRQ,                   /*DMA1 Stream6 global interrupt*/
	ADC_IRQ,                            /*ADC1, ADC2 and ADC3 global interrupts*/
	CAN1_TX_IRQ,                        /*CAN1 TX interrupts*/
	CAN1_RX0_IRQ,                       /*CAN1 RX0 interrupts*/
	CAN1_RX1_IRQ,                       /*CAN1 RX1 interrupts*/
	CAN1_SCE_IRQ,                       /*CAN1 SCE interrupt*/
	EXTI9_5_IRQ,                        /*EXTI Line[9:5] interrupts*/
	TIM1_BRK_TIM9_IRQ,                  /*TIM1 break interrupt and TIM9 global interrupt*/
	TIM1_UP_TIM10_IRQ,                  /*TIM1 Update interrupt and TIM10 global interrupt*/
	TIM1_TRG_COM_TIM11_IRQ,             /*TIM1 Trigger and Commutation interrupts and TIM11 global interrupt*/
	TIM1_CC_IRQ,                        /*TIM1 Capture compare interrupt*/
	TIM2_IRQ,                           /*TIM2 global interrupt*/
	TIM3_IRQ,                           /*TIM3 global interrupt*/
	TIM4_IRQ,                           /*TIM4 global interrupt*/
	I2C1_EV_IRQ,                        /*I2C1 error interrupt*/
	I2C1_ER_IRQ,                        /*I2C1 error interrupt*/
	I2C2_EV_IRQ,                        /*I2C2 error interrupt*/
	I2C2_ER_IRQ,                        /*I2C2 error interrupt*/
	SPI1_IRQ,                           /*SPI1 global interrupt*/
	SPI2_IRQ,                           /*SPI2 global interrupt*/
	USART1_IRQ,                         /*USART1 global interrupt*/
	USART2_IRQ,                         /*USART2 global interrupt*/
	USART3_IRQ,                         /*USART3 global interrupt*/
	EXTI15_10_IRQ,                      /*EXTI Line[15:10] interrupts*/
	RTC_Alarm_IRQ,                      /*RTC Alarms (A and B) through EXTI line interrupt*/
	OTG_FS_WKUP_IRQ,                    /*USB On-The-Go FS Wake up through EXTI line interrupt*/
	TIM8_BRK_TIM12_IRQ,                 /*TIM8 break interrupt and TIM12 global interrupt*/
	TIM8_UP_TIM13_IRQ,                  /*TIM8 Update interrupt and TIM13 global interrupt*/
	TIM8_TRG_COM_TIM14_IRQ,             /*TIM8 Trigger and Commutation interrupts and TIM14 global interrupt*/
	TIM8_CC_IRQ,                        /*TIM8 Capture compare interrupt*/
	DMA1_Stream7_IRQ,                   /*DMA1 Stream7 global interrupt*/
	FMC_IRQ,                            /*FMC global interrupt*/
	SDIO_IRQ,                           /*SDIO global interrupt*/
	TIM5_IRQ,                           /*TIM5 global interrupt*/
	SPI3_IRQ,                           /*SPI3 global interrupt*/
	UART4_IRQ,                          /*USART4 global interrupt*/
	UART5_IRQ,                          /*USART5 global interrupt*/
	TIM6_DAC_IRQ,                       /*TIM6 global interrupt, DAC1 and DAC2 under run error interrupts*/
	TIM7_IRQ,                           /*TIM7 global interrupt*/
	DMA2_Stream0_IRQ,                   /*DMA2 Stream0 global interrupt*/
	DMA2_Stream1_IRQ,                   /*DMA2 Stream1 global interrupt*/
	DMA2_Stream2_IRQ,                   /*DMA2 Stream2 global interrupt*/
	DMA2_Stream3_IRQ,                   /*DMA2 Stream3 global interrupt*/
	DMA2_Stream4_IRQ,                   /*DMA2 Stream4 global interrupt*/
	Reserved_IRQ,
	Reserved1_IRQ,
	CAN2_TX_IRQ,                        /*CAN2 TX interrupts*/
	CAN2_RX0_IRQ,                       /*CAN2 RX0 interrupts*/
	CAN2_RX1_IRQ,                       /*CAN2 RX1 interrupts*/
	CAN2_SCE_IRQ,                       /*CAN2 SCE interrupt*/
	OTG_FS_IRQ,                         /*USB On The Go FS global interrupt*/
	DMA2_Stream5_IRQ,                   /*DMA2 Stream5 global interrupt*/
	DMA2_Stream6_IRQ,                   /*DMA2 Stream6 global interrupt*/
	DMA2_Stream7_IRQ,                   /*DMA2 Stream7 global interrupt*/
	USART6_IRQ,                         /*USART6 global interrupt*/
	I2C3_EV_IRQ,                        /*I2C3 error interrupt*/
	I2C3_ER_IRQ,                        /*I2C3 error interrupt*/
	OTG_HS_EP1_OUT_IRQ,                 /*USB On The Go HS End Point 1 Out global interrupt*/
	OTG_HS_EP1_IN_IRQ,                  /*USB On The Go HS End Point 1 In global interrupt*/
	OTG_HS_WKUP_IRQ,                    /*USB On The Go HS Wake up through EXTI interrupt*/
	OTG_HS_IRQ,                         /*USB On The Go HS global interrupt*/
	DCMI_IRQ,                           /*DCMI global interrupt*/
	Reserved2_IRQ,
	Reserved3_IRQ,
	FPU_IRQ,                            /*FPU global interrupt*/
	Reserved4_IRQ,
	Reserved5_IRQ,
	SPI4_IRQ,                          	/*SPI 4 global interrupt*/
	Reserved6_IRQ,
	Reserved7_IRQ,
	SAI1_IRQ,                           /*SAI1 global interrupt*/
	Reserved8_IRQ,
	Reserved9_IRQ,
	Reserved10_IRQ,
	SAI2_IRQ,                           /*SAI2 global interrupt*/
	QuadSPI_IRQ,                        /*QuadSPI global interrupt*/
	HDMI_CEC_IRQ,                       /*HDMI-CEC global interrupt*/
	SPDIF_Rx_IRQ,                       /*SPDIF-Rx global interrupt*/
	FMPI2C1_IRQ,                        /*FMPI2C1 event interrupt*/
	FMPI2C1_ERROR_IRQ                   /*FMPI2C1 error interrupt*/
}IRQ_Num;

#endif /* NVIC_INTERFACE_H_ */
