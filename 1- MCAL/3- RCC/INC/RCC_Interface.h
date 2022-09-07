/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	RCC 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/*AHB1 Peripherals*/
#define GPIOA_PERIPHERAL		0
#define GPIOB_PERIPHERAL		1
#define GPIOC_PERIPHERAL		2
#define GPIOD_PERIPHERAL		3
#define GPIOE_PERIPHERAL		4
#define GPIOF_PERIPHERAL		5
#define GPIOG_PERIPHERAL		6
#define GPIOH_PERIPHERAL		7
#define CRC_PERIPHERAL			12
#define BKPSRAMEN_PERIPHERAL	18		/*Backup SRAM interface clock enable*/
#define DMA1_PERIPHERAL			21
#define DMA2_PERIPHERAL			22
#define OTGHS_PERIPHERAL		29		/*USB OTG HS clock enable*/
#define OTGHSULPI_PERIPHERAL	30		/*USB OTG HSULPI clock enable*/

/*AHB2 Peripherals*/
#define OTGFS_PERIPHERAL		7		/*Camera interface enable*/
#define DCMI_PERIPHERAL			0		/*USB OTG FS clock enable*/

/*APB1 Peripherals*/
#define TIM2_PERIPHERAL			0
#define TIM3_PERIPHERAL			1
#define TIM4_PERIPHERAL			2
#define TIM5_PERIPHERAL			3
#define TIM6_PERIPHERAL			4
#define TIM7_PERIPHERAL			5
#define TIM12_PERIPHERAL		6
#define TIM13_PERIPHERAL		7
#define TIM14_PERIPHERAL		8
#define WWDG_PERIPHERAL			11		/*Window watchdog clock enable*/
#define SPI2_PERIPHERAL			14
#define SPI3_PERIPHERAL			15
#define SPDIFRX_PERIPHERAL		16		/*SPDIF-Rx clock enable*/
#define USART2_PERIPHERAL		17
#define USART3_PERIPHERAL		18
#define UART4_PERIPHERAL		19
#define UART5_PERIPHERAL		20
#define I2C1_PERIPHERAL			21
#define I2C2_PERIPHERAL			22
#define I2C3_PERIPHERAL			23
#define FMPI2C1_PERIPHERAL		24
#define CAN1_PERIPHERAL			25
#define CAN2_PERIPHERAL			26
#define CEC_PERIPHERAL			27
#define PWR_PERIPHERAL			28
#define DAC_PERIPHERAL			29

/*APB2 Peripherals*/
#define TIM1_PERIPHERAL			0
#define TIM8_PERIPHERAL			1
#define USART1_PERIPHERAL		4
#define USART6_PERIPHERAL		5
#define ADC1_PERIPHERAL			8
#define ADC2_PERIPHERAL			9
#define ADC3_PERIPHERAL			10
#define SDIO_PERIPHERAL			11
#define SPI1_PERIPHERAL			12
#define SPI4_PERIPHERAL			13
#define SYSCFG_PERIPHERAL		14
#define TIM9_PERIPHERAL			16
#define TIM10_PERIPHERAL		17
#define TIM11_PERIPHERAL		18
#define SAI1_PERIPHERAL			22
#define SAI2_PERIPHERAL			23

/*Clock Types*/
#define HSI_CLK					0
#define HSE_CLK					16
#define PLL_CLK					24
#define PLLI2S_CLK				26
#define PLLSAI_CLK				28

/*System Clock*/
#define HSI_SYS_CLK				0
#define HSE_SYS_CLK				1
#define PLL_P_SYS_CLK			2
#define PLL_R_SYS_CLK			3

/*Clock Status*/
#define CLK_ON					0
#define CLK_OFF					1

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
u8 RCC_u8AHB1EnablePeripheralClock(u8 Copy_u8PeripheralId);

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
u8 RCC_u8AHB1DisablePeripheralClock(u8 Copy_u8PeripheralId);

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
u8 RCC_u8AHB2EnablePeripheralClock(u8 Copy_u8PeripheralId);

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
u8 RCC_u8AHB2DisablePeripheralClock(u8 Copy_u8PeripheralId);

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
u8 RCC_u8APB1EnablePeripheralClock(u8 Copy_u8PeripheralId);

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
u8 RCC_u8APB1DisablePeripheralClock(u8 Copy_u8PeripheralId);

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
u8 RCC_u8APB2EnablePeripheralClock(u8 Copy_u8PeripheralId);

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
u8 RCC_u8APB2DisablePeripheralClock(u8 Copy_u8PeripheralId);

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
u8 RCC_u8SetCLKStatus(u8 Copy_u8CLKType,u8 Copy_u8Status);

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
u8 RCC_u8SetSystemCLKSRC(u8 Copy_u8CLKType);


#endif /* RCC_INTERFACE_H_ */
