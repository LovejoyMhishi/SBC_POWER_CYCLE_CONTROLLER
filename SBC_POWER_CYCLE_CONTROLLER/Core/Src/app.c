
/* ******************* ──────────────────────────────────────────────────────────────── ******************* */
/*                                                                                                          *
 *              ╔═════════════════════════════════════════════════════════════════════════╗                 *
 *              ║                            FILE: app.c                                 ║                  *
 *              ║                       AUTHOR: LOVEJOY MHISHI                           ║                  *
 *              ║                        DATE: SEPT 17, 2026                             ║                  *
 *              ╠═════════════════════════════════════════════════════════════════════════╣                 *
 *              ║                   MAIN APPLICATION LOGIC FOR SBC                       ║                  *
 *              ╚═════════════════════════════════════════════════════════════════════════╝                 *
 *                                                                                                          *
 * SBC POWER CYCLE CONTROL AND INTERVAL MANAGEMENT FUNCTION BODIES                                          *
 *                                                                                                          *
 * CONTENTS:                                                                                                *
 *   - INTERVAL SELECTION AND CONFIGURATION                                                                 *
 *   - SBC POWER CONTROL INITIALIZATION                                                                     *
 *   - PERIODIC SBC POWER CYCLE CONTROL                                                                     *
 *   - CONFIGURABLE 1H, 6H, 12H, 18H AND 24H POWER CYCLE INTERVALS                                          *
 *                                                                                                          *
 * INTENDED USE:                                                                                            *
 *   - PROVIDES THE MAIN APPLICATION LOGIC FOR SBC POWER CYCLE CONTROL.                                     *
 *   - SELECTS THE SBC POWER CYCLE INTERVAL USING HARDWARE GPIO INPUTS.                                     *
 *   - CONTROLS SBC POWER USING THE CONFIGURED INTERVAL AND SYSTEM ELAPSED TIME.                            *
 *   - USED WITH THE STM32G030K8T6 MCU.                                                                     *
 *                                                                                                          *
 * DEPENDENCIES:                                                                                            *
 *   - APP.H HEADER FILE FOR APPLICATION DEFINITIONS AND DATA TYPES.                                        *
 *   - GPIO.H FOR GPIO CONTROL AND INTERVAL SELECTION INPUTS.                                               *
 *   - UTILS.H FOR TIMEOUT AND UTILITY FUNCTIONS.                                                           *
 *   - TIM.H FOR SYSTEM TIMING AND ELAPSED TIME MANAGEMENT.                                                 *
 *                                                                                                          *
 * NOTES:                                                                                                   *
 *   - GPIO AND SYSTEM TIMER PERIPHERALS MUST BE INITIALIZED BEFORE USE.                                    *
 *   - INTERVAL SELECTION INPUTS MUST BE CONFIGURED BEFORE CALLING SBC_PWR_CYCLE_CTRLER_INIT().             *
 *   - IF NO INTERVAL SELECTION INPUT IS ACTIVE, THE DEFAULT INTERVAL IS 24 HOURS.                          *
 *   - SBC POWER IS ENABLED DURING INITIALIZATION.                                                          *
 *   - EACH POWER CYCLE DISABLES SBC POWER FOR 10 SECONDS BEFORE RESTORING POWER.                           *
 *                                                                                                          *
 * COPYRIGHT:                                                                                               *
 *   - COPYRIGHT (C) 2026 IOTECH MANUFACTURING PTY LTD. ALL RIGHTS RESERVED.                                *
 *                                                                                                          *
 *                                                                                                          */
/* ******************* ──────────────────────────────────────────────────────────────── ******************* */

/* ──────────────────────────────────────────────────────────────────────────────────────────────────────── */
/* 																											*/
/*                                           INCLUDES                                                       */
/*                                                                                  						*/
/* ──────────────────────────────────────────────────────────────────────────────────────────────────────── */
#include <app.h>


#include "gpio.h"
#include "utils.h"
#include "tim.h"


INTERVAL_SELECT GetInterval(void);
void SBC_PWR_CYCLE_CTRLER_Init(void);
void SBC_PWR_CYCLE_CTRLER(void);


static INTERVAL_SELECT IntervalSelect;

INTERVAL_SELECT GetInterval(void)
{
	if (READ_BIT(GPIOA->IDR, INTERVAL_01H_SEL))
	{
		return INTERVAL_SEL_01H;
	}
	else if (READ_BIT(GPIOA->IDR, INTERVAL_06H_SEL))
	{
		return INTERVAL_SEL_06H;
	}
	else if (READ_BIT(GPIOA->IDR, INTERVAL_12H_SEL))
	{
		return INTERVAL_SEL_12H;
	}
	else if (READ_BIT(GPIOB->IDR, INTERVAL_18H_SEL ))
	{
		return INTERVAL_SEL_18H;
	}

	/*
	 * NO JUMPER SELECTED
	 * DEFAULT TO 24 HOUR INTERVAL
	 */
	return INTERVAL_SEL_24H;
}


void SBC_PWR_CYCLE_CTRLER_Init(void)
{
	IntervalSelect = GetInterval();                                        //GET INTERVAL SELECTION
	GPIO_Writepin(GPIOA, SBC_PWR_CTRL, GPIO_PIN_SBC_PWR_CTRL_SET);         //SBC POWER ON
}


void SBC_PWR_CYCLE_CTRLER(void)
{
	switch (IntervalSelect)
	{
		case INTERVAL_SEL_01H:
			if (ElapsedSec >= INTERVAL_01H_SEC)
			{
				GPIO_Writepin(GPIOA, SBC_PWR_CTRL, GPIO_PIN_SBC_PWR_CTRL_RESET);
				TimeOut(10000);
				GPIO_Writepin(GPIOA, SBC_PWR_CTRL, GPIO_PIN_SBC_PWR_CTRL_SET);
				ElapsedSec = 0U;
			}
			break;

		case INTERVAL_SEL_06H:
			if (ElapsedSec >= INTERVAL_06H_SEC)
			{
				GPIO_Writepin(GPIOA, SBC_PWR_CTRL, GPIO_PIN_SBC_PWR_CTRL_RESET);
				TimeOut(10000);
				GPIO_Writepin(GPIOA, SBC_PWR_CTRL, GPIO_PIN_SBC_PWR_CTRL_SET);
				ElapsedSec = 0U;
			}
			break;

		case INTERVAL_SEL_12H:
			if (ElapsedSec >= INTERVAL_12H_SEC)
			{
				GPIO_Writepin(GPIOA, SBC_PWR_CTRL, GPIO_PIN_SBC_PWR_CTRL_RESET);
				TimeOut(10000);
				GPIO_Writepin(GPIOA, SBC_PWR_CTRL, GPIO_PIN_SBC_PWR_CTRL_SET);
				ElapsedSec = 0U;
			}
			break;

		case INTERVAL_SEL_18H:
			if (ElapsedSec >= INTERVAL_18H_SEC)
			{
				GPIO_Writepin(GPIOA, SBC_PWR_CTRL,GPIO_PIN_SBC_PWR_CTRL_RESET);
				TimeOut(10000);
				GPIO_Writepin(GPIOA, SBC_PWR_CTRL, GPIO_PIN_SBC_PWR_CTRL_SET);
				ElapsedSec = 0U;
			}
			break;
		case INTERVAL_SEL_24H:
			if (ElapsedSec >= INTERVAL_24H_SEC)
			{
				GPIO_Writepin(GPIOA, SBC_PWR_CTRL, GPIO_PIN_SBC_PWR_CTRL_RESET);
				TimeOut(10000);
				GPIO_Writepin(GPIOA, SBC_PWR_CTRL,GPIO_PIN_SBC_PWR_CTRL_SET);
				ElapsedSec = 0U;
			}
			break;
		default:
			break;
	}
}

