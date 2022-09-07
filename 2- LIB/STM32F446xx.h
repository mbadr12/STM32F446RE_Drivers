/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  LIB 			    *************************/
/*************************		SWC: 	STM32F446xx device	*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef STM32F446XX_H_
#define STM32F446XX_H_

/***************************** 		Core Peripherals	*****************************/

/*****************************		Systick Registers	*****************************/

#define STK_CTRL		*((volatile u32*)(0xE000E010+0x00))
#define STK_LOAD		*((volatile u32*)(0xE000E010+0x04))
#define STK_VAL			*((volatile u32*)(0xE000E010+0x08))

/*************************** NVIC Peripheral Base Addresses *************************/

#define NVIC_BASE_ADDRESS		0xE000E100UL

/************************* NVIC Register Definition Structure ***********************/

typedef struct
{
	volatile u32 ISER[8];		/*Interrupt set-enable register*/
	u32 Reserved1[24];
	volatile u32 ICER[8];		/*Interrupt clear-enable register*/
	u32 Reserved[24];
	volatile u32 ISPR[8];		/*Interrupt set-pending register*/
	u32 Reserved2[24];
	volatile u32 ICPR[8];		/*Interrupt clear-pending register*/
	u32 Reserved4[24];
	volatile u32 IABR[8];		/*Interrupt active bit register*/
	u32 Reserved3[32];
	volatile u8 IPR[240];		/*Interrupt priority register*/
}NVIC_RegDef_t;

#define NVIC						((NVIC_RegDef_t*)NVIC_BASE_ADDRESS)

/*****************************		SCB Registers	*****************************/

#define SCB_BASE_ADDRESS		0xE000ED00UL

#define SCB_AIRCR				(SCB_BASE_ADDRESS+0x0C)

/***************************** Memories Base Addresses ******************************/
#define FLASH_BASE_ADDRESS		0x08000000UL
#define SRAM1_BASE_ADDRESS		0x20000000UL
#define SRAM2_BASE_ADDRESS		0x2001C000UL
#define ROM_BASE_ADDRESS		0x1FFF0000UL

/*************************** AHB1 Peripheral Base Addresses *************************/

#define GPIOA_BASE_ADDRESS		0X40020000UL
#define GPIOB_BASE_ADDRESS		0X40020400UL
#define GPIOC_BASE_ADDRESS		0X40020800UL
#define GPIOD_BASE_ADDRESS		0X40020C00UL
#define GPIOE_BASE_ADDRESS		0X40021000UL
#define GPIOF_BASE_ADDRESS		0X40021400UL
#define GPIOG_BASE_ADDRESS		0X40021800UL
#define GPIOH_BASE_ADDRESS		0X40021C00UL
#define RCC_BASE_ADDRESS		0x40023800UL

/*************************** AHB2 Peripheral Base Addresses *************************/

/*************************** APB1 Peripheral Base Addresses *************************/

#define I2C3_BASE_ADDRESS		0x40005C00UL
#define I2C2_BASE_ADDRESS		0x40005800UL
#define I2C1_BASE_ADDRESS		0x40005400UL
#define USART2_BASE_ADDRESS		0x40004400UL
#define USART3_BASE_ADDRESS		0x40004800UL
#define UART4_BASE_ADDRESS		0x40004C00UL
#define UART5_BASE_ADDRESS		0x40005000UL
#define SPI2_BASE_ADDRESS		0x40003800UL
#define SPI3_BASE_ADDRESS		0x40003C00UL

/*************************** APB2 Peripheral Base Addresses *************************/

#define USART1_BASE_ADDRESS		0x40011000UL
#define USART6_BASE_ADDRESS		0x40011400UL
#define SPI1_BASE_ADDRESS		0x40013000UL
#define SPI4_BASE_ADDRESS		0x40013400UL
#define SYSCFG_BASE_ADDRESS		0x40013800UL
#define EXTI_BASE_ADDRESS		0x40013C00UL

/************************* GPIO Register Definition Structure ***********************/

typedef struct
{
	volatile u32 MODER;     		/*GPIO port mode register*/
	volatile u32 OTYPER;    		/*GPIO port output type register*/
	volatile u32 OSPEEDER;  		/*GPIO port output speed register*/
	volatile u32 PUPDR;     		/*GPIO port pull-up/pull-down register*/
	volatile u32 IDR;       		/*GPIO port input data register*/
	volatile u32 ODR;       		/*GPIO port output data register*/
	volatile u32 BSRR;      		/*GPIO port bit set/reset register*/
	volatile u32 LCKR;      		/*GPIO port configuration lock register*/
	volatile u32 AFR[2];    		/*AFR[0] : GPIO alternate function low register
									 *AFR[1] : GPIO alternate function high register*/
}GPIO_RegDef_t;

/***************************** GPIO Peripheral Definitions **************************/

#define GPIOA			((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)
#define GPIOB			((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)
#define GPIOC			((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)
#define GPIOD			((GPIO_RegDef_t*)GPIOD_BASE_ADDRESS)
#define GPIOE			((GPIO_RegDef_t*)GPIOE_BASE_ADDRESS)
#define GPIOF			((GPIO_RegDef_t*)GPIOF_BASE_ADDRESS)
#define GPIOG			((GPIO_RegDef_t*)GPIOG_BASE_ADDRESS)
#define GPIOH			((GPIO_RegDef_t*)GPIOH_BASE_ADDRESS)

/************************* GPIO Register Definition Structure ***********************/

typedef struct
{
	volatile u32 CR; 				/*RCC clock control register*/				 
	volatile u32 PLLCFGR;           /*RCC PLL configuration register*/
	volatile u32 CFGR;              /*RCC clock configuration register*/
	volatile u32 CIR;               /*RCC clock interrupt register*/
	volatile u32 AHB1RSTR;          /*RCC AHB1 peripheral reset register*/
	volatile u32 AHB2RSTR;          /*RCC AHB2 peripheral reset register*/
	volatile u32 AHB3RSTR;          /*RCC AHB3 peripheral reset register*/
	volatile u32 Reserved;          /*Reserved*/
	volatile u32 APB1RSTR;          /*RCC APB1 peripheral reset register*/
	volatile u32 APB2RSTR;          /*RCC APB2 peripheral reset register*/
	volatile u32 Reserved1[2];      /*Reserved*/
	volatile u32 AHB1ENR;           /*RCC AHB1 peripheral clock enable register*/
	volatile u32 AHB2ENR;           /*RCC AHB2 peripheral clock enable register*/
	volatile u32 AHB3ENR;           /*RCC AHB3 peripheral clock enable register*/
	volatile u32 Reserved2;         /*Reserved*/
	volatile u32 APB1ENR;           /*RCC APB1 peripheral clock enable register*/
	volatile u32 APB2ENR;           /*RCC APB2 peripheral clock enable register*/
	volatile u32 Reserved3[2];      /*Reserved*/
	volatile u32 AHB1LPENR;         /*RCC AHB1 peripheral clock enable in low power mode register*/
	volatile u32 AHB2LPENR;         /*RCC AHB2 peripheral clock enable in low power mode register*/
	volatile u32 AHB3LPENR;         /*RCC AHB3 peripheral clock enable in low power mode register*/
	volatile u32 Reserved4;         /*Reserved*/
	volatile u32 APB1LPENR;         /*RCC APB1 peripheral clock enable in low power mode register*/
	volatile u32 APB2LPENR;         /*RCC APB2 peripheral clock enable in low power mode register*/
	volatile u32 Reserved5[2];      /*Reserved*/
	volatile u32 BDCR;              /*RCC Backup domain control register*/
	volatile u32 CSR;               /*RCC clock control & status register*/
	volatile u32 Reserved6[2];      /*Reserved*/
	volatile u32 SSCGR;             /*RCC spread spectrum clock generation register*/
	volatile u32 PLLI2SCFGR;        /*RCC PLLI2S configuration register*/
	volatile u32 PLLSAICFGR;        /*RCC PLLSAI configuration register*/
	volatile u32 DCKCFGR;           /*RCC dedicated clock configuration register*/
	volatile u32 CKGATENR;          /*RCC clocks gated enable register*/
	volatile u32 DCKCFGR2;          /*RCC dedicated clocks configuration register 2*/
}RCC_RegDef_t;

/***************************** RCC Peripheral Definitions **************************/

#define RCC				((RCC_RegDef_t*)RCC_BASE_ADDRESS)

#define RCC_CR_HSION		0		/*Enable High Speed External*/
#define RCC_CR_HSEON		16		/*Enable Internal High Speed*/
#define RCC_CR_HSEBYP		18		/*Enable High Speed External ByPass*/
#define RCC_CR_CSSON		19		/*Enable System Clock Security*/
#define RCC_CR_PLLON		24		/*Enable Main PLL*/
#define RCC_CR_PLLI2SON		26		/*Enable PLLI2S*/
#define RCC_CR_PLLSAION		28		/*Enable PLLSAI*/

#endif