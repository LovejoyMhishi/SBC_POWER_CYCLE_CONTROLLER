/* ******************* ──────────────────────────────────────────────────────────────── ******************* */
/*                                                                                                          *
 *              ╔═════════════════════════════════════════════════════════════════════════╗                 *
 *               ║                            FILE: tim.h                                ║                  *
 *               ║                            AUTHOR: LOVEJOY MHISHI                     ║                  *
 *               ║                            DATE: DECEMBER 23, 2025                    ║                  *
 *              ╠═════════════════════════════════════════════════════════════════════════╣                 *
 *               ║         STM32 TIMER DRIVER - FUNCTION PROTOTYPES AND DEFINITIONS      ║                  *
 *              ╚═════════════════════════════════════════════════════════════════════════╝                 *
 * THIS HEADER FILE PROVIDES FUNCTION PROTOTYPES, TYPE DEFINITIONS, AND MACROS FOR THE STM32 TIMER DRIVER.  *
 *                                                                                                          *
 * CONTENTS:                                                                                                *
 *   - TIMER DEFINES                                                                                        *
 *   - TIMER INITIALIZATION AND CONFIGURATION FUNCTION PROTOTYPES                                           *
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

#ifndef CUSTOM_TIMX_INC_TIM_H_
#define CUSTOM_TIMX_INC_TIM_H_

#include "stm32g0xx.h"

#define TIM14_PSC     15999
#define TIM14_ARR     999


void TIM14_Init(void);

extern volatile uint8_t SecCnt;
extern volatile uint8_t MinCnt;
extern volatile uint8_t HouCnt;

__STATIC_INLINE void TIMx_Start(TIM_TypeDef *TIMx)
{
    SET_BIT(TIMx->CR1, TIM_CR1_CEN);
}

__STATIC_INLINE void TIMx_Stop(TIM_TypeDef *TIMx)
{
    CLEAR_BIT(TIMx->CR1, TIM_CR1_CEN);
    CLEAR_REG(TIMx->CNT);
    CLEAR_BIT(TIMx->SR, TIM_SR_UIF);
}



#endif /* CUSTOM_TIMX_INC_TIM_H_ */
