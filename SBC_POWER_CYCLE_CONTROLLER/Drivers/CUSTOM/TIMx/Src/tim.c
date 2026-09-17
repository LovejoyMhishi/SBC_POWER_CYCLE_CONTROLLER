/* ******************* ──────────────────────────────────────────────────────────────── ******************* */
/*                                                                                                          *
 *              ╔═════════════════════════════════════════════════════════════════════════╗                 *
 *               ║                            FILE: tim.c                                ║                  *
 *               ║                            AUTHOR: LOVEJOY MHISHI                     ║                  *
 *               ║                            DATE: DECEMBER 23, 2025                    ║                  *
 *              ╠═════════════════════════════════════════════════════════════════════════╣                 *
 *               ║         STM32 TIMER DRIVER - FUNCTION PROTOTYPES AND DEFINITIONS      ║                  *
 *              ╚═════════════════════════════════════════════════════════════════════════╝                 *
 * THIS HEADER FILE PROVIDES FUNCTION PROTOTYPES, TYPE DEFINITIONS, AND MACROS FOR THE STM32 TIMER DRIVER.  *
 *                                                                                                          *
 * CONTENTS:                                                                                                *
 *   - TIMER INITIALIZATION AND CONFIGURATION FUNCTION BODIES                                               *
 *   - START, STOP, AND RESET FUNCTIONS                                                                     *
 *   - INTERRUPT HANDLING FUNCTION PROTOTYPES                                                               *
 *   - TIMER PRESCALER AND PERIOD SETTINGS                                                                  *
 *                                                                                                          *
 * INTENDED USE:                                                                                            *
 *   - INCLUDE IN APPLICATION FILES (E.G., MAIN.C, APP.C) TO ACCESS TIMER DRIVER APIS.                     *
 *                                                                                                          *
 * DEPENDENCIES:                                                                                            *
 *   - CMSIS DEVICE HEADERS (E.G., STM32G030XX.H) FOR REGISTER DEFINITIONS.                                *
 *   - TIMER.C IMPLEMENTATION FILE CONTAINING THE FUNCTION BODIES.                                         *
 *                                                                                                          */
/* ******************* ──────────────────────────────────────────────────────────────── ******************* */

#include "tim.h"

volatile uint8_t SecCnt = 0;
volatile uint8_t MinCnt = 0;
volatile uint8_t HouCnt = 0;

void TIM14_Init(void)
{
    CLEAR_BIT(TIM14->CR1, TIM_CR1_CEN);
    SET_BIT(RCC->APBENR2, RCC_APBENR2_TIM14EN);
    WRITE_REG(TIM14->PSC, TIM14_PSC);
    WRITE_REG(TIM14->ARR, TIM14_ARR);
    SET_BIT(TIM14->EGR, TIM_EGR_UG);
    CLEAR_BIT(TIM14->SR, TIM_SR_UIF);
    SET_BIT(TIM14->CR1, TIM_CR1_ARPE);
    SET_BIT(TIM14->DIER, TIM_DIER_UIE);
    NVIC_SetPriority(TIM14_IRQn, 2);
    NVIC_EnableIRQ(TIM14_IRQn);
}
