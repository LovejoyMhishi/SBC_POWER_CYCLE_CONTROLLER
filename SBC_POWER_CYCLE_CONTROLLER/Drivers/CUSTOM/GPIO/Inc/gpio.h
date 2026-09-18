
/* ******************* ──────────────────────────────────────────────────────────────── ******************* */
/*                                                                                                          *
 *              ╔═════════════════════════════════════════════════════════════════════════╗                 *
 *               ║                            FILE: GPIO.H                               ║                  *
 *               ║                            AUTHOR: LOVEJOY MHISHI                     ║                  *
 *               ║                            DATE: MAY 18, 2026                         ║                  *
 *              ╠═════════════════════════════════════════════════════════════════════════╣                 *
 *               ║       STM32 GPIO DRIVER - FUNCTION PROTOTYPES AND DEFINITIONS         ║                  *
 *              ╚═════════════════════════════════════════════════════════════════════════╝                 *
 * THIS HEADER FILE PROVIDES FUNCTION PROTOTYPES, TYPE DEFINITIONS, AND EXTERNAL VARIABLES                  *
 * FOR THE STM32 GPIO DRIVER.                                                                               *
 *                                                                                                          *
 * CONTENTS:                                                                                                *
 *   - GPIO PIN MODES: INPUT, OUTPUT, ALTERNATE FUNCTION, ANALOG                                            *
 *   - OUTPUT TYPES: PUSH-PULL, OPEN-DRAIN                                                                  *
 *   - PULL-UP/PULL-DOWN CONFIGURATIONS                                                                     *
 *   - FUNCTION PROTOTYPES FOR GPIO INITIALIZATION AND CONTROL                                              *
 *                                                                                                          *
 * INTENDED USE:                                                                                            *
 *   - INCLUDE IN APPLICATION FILES (E.G., APP.C, MAIN.C) TO ACCESS GPIO DRIVER APIS.                       *
 *                                                                                                          *
 * DEPENDENCIES:                                                                                            *
 *   - CMSIS DEVICE HEADERS (E.G., STM32G030XX.H) FOR REGISTER DEFINITIONS.                                 *
 *   - GPIO.C IMPLEMENTATION FILE CONTAINING THE FUNCTION BODIES.                                           *
 *                                                                                                          */
/* ******************* ──────────────────────────────────────────────────────────────── ******************* */
#ifndef CUSTOM_GPIO_INC_GPIO_H_
#define CUSTOM_GPIO_INC_GPIO_H_
/* ──────────────────────────────────────────────────────────────────────────────────────────────────────── */
/* 																											*/
/*                                           INCLUDES                                                       */
/*                                                                                  						*/
/* ──────────────────────────────────────────────────────────────────────────────────────────────────────── */
#include <stm32g0xx.h>


/* ──────────────────────────────────────────────────────────────────────────────────────────────────────── */
/*																											*/
/*                                           DEFINES                                                        */
/*																										    */
/* ──────────────────────────────────────────────────────────────────────────────────────────────────────── */
#define SBC_PWR_CTRL                                 (1U << 3)   		//GPIO PA3
#define INTERVAL_12H_SEL                             (1U << 4)   		//GPIO PA4
#define INTERVAL_01H_SEL                             (1U << 5)   		//GPIO PA5
#define INTERVAL_06H_SEL                             (1U << 6)          //GPIO PA6
#define INTERVAL_18H_SEL                             (1U << 0)          //GPIO PB0
#define LED_GRN                                      (1U << 7)   		//GPIO PB7

/* ──────────────────────────────────────────────────────────────────────────────────────────────────────── */
/*																											*/
/*                                           DEFINATIONS                                                    */
/*																										    */
/* ──────────────────────────────────────────────────────────────────────────────────────────────────────── */
typedef enum
{
    GPIO_PIN_RESET         = 0,
    GPIO_PIN_SET           = 1,

    GPIO_PIN_SBC_PWR_CTRL_SET   = 0,
    GPIO_PIN_SBC_PWR_CTRL_RESET = 1

} GPIO_PinState;




/* ──────────────────────────────────────────────────────────────────────────────────────────────────────── */
/*																											*/
/*                                           LOW-LEVEL FUNCTIONS                                            */
/*																										    */
/* ──────────────────────────────────────────────────────────────────────────────────────────────────────── */
void GPIO_Init(void);
void GPIO_Writepin(GPIO_TypeDef *GPIOx, uint16_t pin, GPIO_PinState State);
void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t Pin);

#endif /* CUSTOM_GPIO_INC_GPIO_H_ */
