/*
 * mySelector_blinker.h
 *
 *  Created on: 19 ago. 2020
 *      Author: pablo
 */

#ifndef MYPROGRAMS_TASK_PARAMETERS_INC_MYSELECTOR_BLINKER_H_
#define MYPROGRAMS_TASK_PARAMETERS_INC_MYSELECTOR_BLINKER_H_

#define BLINK_TIME_ON 500 /**< Time the blinker led will remain on during blink in ms. */

#include "sapi.h"
#include "mySelector_leds.h"
#include "mySelector_delay.h"

/** Blinker FSM states. */
typedef enum{
   STATE_LED_ON,
   STATE_LED_OFF
} blinkerState_t;

/** Blinker available periods. */
typedef enum{
	BLINKER_PERIOD_FIVE_SECONDS,
	BLINKER_PERIOD_TEN_SECONDS,
	BLINKER_PERIOD_FIFTEEN_SECONDS
} blinkerPeriod_t;

/** Blinker error handler. */
void myBlinkerError( void );

/** Blinker initialization. */
void myBlinkerInit( void );

/** Reports current blinker set period through UART. */
void myBlinkerReportPeriod(void);

/** Sets time between blinks of the blinker.
 * @param [in] period Any of the available blinker periods.
*/
void myBlinkerSetPeriod(blinkerPeriod_t period);

/** Controls blinker FSM.
 * @param [in] led LED which will blink.
*/
void myBlinkerUpdate( gpioMap_t led );

/** Establish next available period as blinker period. */
void myBlinkerSwitchPeriod( void );

#endif /* MYPROGRAMS_TASK_PARAMETERS_INC_MYSELECTOR_BLINKER_H_ */
