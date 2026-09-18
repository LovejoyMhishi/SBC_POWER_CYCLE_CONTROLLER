
/* ******************* ──────────────────────────────────────────────────────────────── ******************* */
/*                                                                                                          *
 *              ╔═════════════════════════════════════════════════════════════════════════╗                 *
 *               ║                            FILE: gpio.c                               ║                  *
 *               ║                            AUTHOR: LOVEJOY MHISHI                     ║                  *
 *               ║                            DATE: MAY 18, 2025                         ║                  *
 *              ╠═════════════════════════════════════════════════════════════════════════╣                 *
 *               ║       STM32 GPIO DRIVER - FUNCTION IMPLEMENTATIONS                    ║                  *
 *              ╚═════════════════════════════════════════════════════════════════════════╝                 *
 * THIS SOURCE FILE CONTAINS BARE-METAL IMPLEMENTATIONS OF GPIO FUNCTIONS FOR STM32G030XX.                  *
 *                                                                                                          *
 * CONTENTS:                                                                                                *
 *   - GPIO INITIALIZATION                                                                                  *
 *   - GPIO READ/WRITE OPERATIONS                                                                           *
 *   - GPIO TOGGLE FUNCTION                                                                                 *
 *                                                                                                          *
 * INTENDED USE:                                                                                            *
 *   - INCLUDE GPIO.H IN APPLICATION FILES (E.G., MAIN.C, APP.C) TO ACCESS GPIO APIS.                       *
 *                                                                                                          *
 * DEPENDENCIES:                                                                                            *
 *   - GPIO.H HEADER FILE FOR FUNCTION PROTOTYPES AND DATA STRUCTURES.                                      *
 *   - CMSIS DEVICE HEADERS (E.G., STM32G030XX.H) FOR REGISTER DEFINITIONS.                                 *
 *                                                                                                          *
 * NOTES:                                                                                                   *
 *   - ENABLE GPIO PERIPHERAL CLOCKS  (REF. RM0444, P. 106-107).                                            *
 *   - GPIO MODES, OUTPUT TYPE, PULL-UP/PULL-DOWN, AND SPEED REGISTERS (REF. RM0444, P. 221-225).           *
 *   - ALTERNATE FUNCTION CONFIGURATION (AFR REGISTERS) (REF. RM0444, P. 226-227).                          *
 *   - POLLING OR INTERRUPT-DRIVEN GPIO CAN BE IMPLEMENTED AS NEEDED.                                       *
 *                                                                                                          */
/* ******************* ──────────────────────────────────────────────────────────────── ******************* */


#include "gpio.h"

/* ────────────────────────────────────────────────────────────── /
 * Function : GPIO_Init()
 * Purpose  : Initialize GPIO Pins for use
 * Details  : Configures GPIO Pins
 * Runtime  : ~X.Xxx
 * ────────────────────────────────────────────────────────────── */
void GPIO_Init(void)
{
	/*
	 * GPIO CLK EN
	 */
	SET_BIT(RCC->IOPENR, RCC_IOPENR_GPIOAEN);                      //I/O PORT A CLK EN
	SET_BIT(RCC->IOPENR, RCC_IOPENR_GPIOBEN);                      //I/O PORT B CLK EN

	/*
	 * GPIO PA3: SBC_PWR_CTRL
	 */
	CLEAR_BIT(GPIOA->MODER, GPIO_MODER_MODE3);                     // 00: CLEAR MODE3[1:0]
	SET_BIT(GPIOA->MODER, GPIO_MODER_MODE3_0);                     // 01: GENERAL PURPOSE OUTPUT MODE
	CLEAR_BIT(GPIOA->OTYPER, GPIO_OTYPER_OT3);                     // 00: OUTPUT PUSH PULL
	CLEAR_BIT(GPIOA->OSPEEDR, GPIO_OSPEEDR_OSPEED3);               // 00: VERY LOW SPEED
	CLEAR_BIT(GPIOA->PUPDR, GPIO_PUPDR_PUPD3);                     // 00: NO PULL-UP, PULL DOWN

	/*
	 * GPIO PA4: INTERVAL_12H_SEL
	 */
	CLEAR_BIT(GPIOA->MODER, GPIO_MODER_MODE4);                     // 00: GENERAL PURPOSE INPUT MODE

	/*
	 * GPIO PA5: INTERVAL_01H_SEL
	 */
	CLEAR_BIT(GPIOA->MODER, GPIO_MODER_MODE5);                     // 00: GENERAL PURPOSE INPUT MODE

	/*
	 * GPIO PA6: INTERVAL_06H_SEL
	 */
	CLEAR_BIT(GPIOA->MODER, GPIO_MODER_MODE6);                     // 00: GENERAL PURPOSE INPUT MODE

	/*
	 * GPIO PB0: INTERVAL_24H_SEL
	 */
	CLEAR_BIT(GPIOB->MODER, GPIO_MODER_MODE0);                     // 00: GENERAL PURPOSE INPUT MODE

	/*
	 * GPIO PB7: LED_GREEN
	 */
	CLEAR_BIT(GPIOB->MODER, GPIO_MODER_MODE7);                     // 00: CLEAR MODE7[1:0]
	SET_BIT(GPIOB->MODER, GPIO_MODER_MODE7_0);                     // 01: GENERAL PURPOSE OUTPUT MODE
	CLEAR_BIT(GPIOB->OTYPER, GPIO_OTYPER_OT7);                     // 00: OUTPUT PUSH PULL
	CLEAR_BIT(GPIOB->OSPEEDR, GPIO_OSPEEDR_OSPEED7);               // 00: VERY LOW SPEED
	CLEAR_BIT(GPIOB->PUPDR, GPIO_PUPDR_PUPD7);                     // 00: NO PULL-UP, PULL DOWN

}

/* ──────────────────────────────────────────────────────────────
 * FUNCTION : GPIO_WritePin()
 * PURPOSE  : WRITES A 1 OR 0 TO A GPIO PIN
 * DETAILS  : CHANGES PIN OUTPUT STATE
 * RUNTIME  : ~X.x
 * ────────────────────────────────────────────────────────────── */
void GPIO_Writepin(GPIO_TypeDef *GPIOx, uint16_t Pin, GPIO_PinState State)
{
	if(State == GPIO_PIN_SET)
	{
		WRITE_REG(GPIOx->BSRR, Pin);                                //1: SET
	}
	else
	{
		WRITE_REG(GPIOx->BSRR, (uint32_t)Pin << 16);                //0: RESET
	}
}

/* ──────────────────────────────────────────────────────────────
 * FUNCTION : GPIO_TogglePin()
 * PURPOSE  : TOGGLES THE OUTPUT STATE OF A GPIO PIN
 * DETAILS  : WRITES TO THE BSRR REGISTER TO SET OR RESET THE PIN
 * RUNTIME  : ~X.x
 * ────────────────────────────────────────────────────────────── */
void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t Pin)
{
	if (READ_BIT(GPIOx->ODR, Pin))
	{
		WRITE_REG(GPIOx->BSRR, (uint32_t)Pin << 16);               //0: RESET
	}
	else
	{
		WRITE_REG(GPIOx->BSRR, Pin);                               //1: SET
	}
}
