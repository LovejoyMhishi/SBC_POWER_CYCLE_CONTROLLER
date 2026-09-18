

/* ******************* ──────────────────────────────────────────────────────────────── ******************* */
/*                                                                                                          *
 *              ╔═════════════════════════════════════════════════════════════════════════╗                 *
 *               ║                            FILE: APP.H                                ║                  *
 *               ║                            AUTHOR: LOVEJOY MHISHI                     ║                  *
 *               ║                            DATE: SEPT 17, 2026                        ║                  *
 *              ╠═════════════════════════════════════════════════════════════════════════╣                 *
 *               ║                       SBC POWER CYCLE CONTROL                         ║                  *
 *              ╚═════════════════════════════════════════════════════════════════════════╝                 *
 * THIS HEADER FILE PROVIDES INTERVAL DEFINITIONS, TYPE DEFINITIONS, AND FUNCTION PROTOTYPES.               *
 *                                                                                                          *
 * CONTENTS:                                                                                                *
 *   - INTERVAL DEFINITIONS                                                                                 *
 *   - TYPE DEFINITIONS                                                                                     *
 *   - FUNCTION PROTOTYPES                                                                                  *
 *                                                                                                          *
 * INTENDED USE:                                                                                            *
 *   - INCLUDE APP.H IN APPLICATION FILES TO ACCESS SBC POWER CYCLE CONTROL FUNCTIONS.                      *
 *                                                                                                          *
 * DEPENDENCIES:                                                                                            *
 *   - STM32G030XX.H                                                                                        *
 *   - GPIO.H                                                                                               *
 *                                                                                                          */
/* ******************* ──────────────────────────────────────────────────────────────── ******************* */


#ifndef INC_APP_H_
#define INC_APP_H_


/*
 * INTERVAL TIMES
 */
#define INTERVAL_01H_SEC                             (60U * 60U)
#define INTERVAL_06H_SEC                             (6U  * INTERVAL_01H_SEC)
#define INTERVAL_12H_SEC                             (12U * INTERVAL_01H_SEC)
#define INTERVAL_18H_SEC                             (18U * INTERVAL_01H_SEC)
#define INTERVAL_24H_SEC                             (24U * INTERVAL_01H_SEC)


typedef enum
{
	INTERVAL_SEL_01H                = 0x00,
	INTERVAL_SEL_06H                = 0x01,
	INTERVAL_SEL_12H                = 0x02,
	INTERVAL_SEL_18H                = 0x03,
	INTERVAL_SEL_24H                = 0xFF
} INTERVAL_SELECT;


INTERVAL_SELECT GetInterval(void);
void SBC_PWR_CYCLE_CTRLER_Init(void);
void SBC_PWR_CYCLE_CTRLER(void);
#endif /* INC_APP_H_ */
