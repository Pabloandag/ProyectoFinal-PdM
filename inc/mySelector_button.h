/*
 * mySelector_button.h
 *
 *  Created on: 19 ago. 2020
 *      Author: pablo
 */

#ifndef MYPROGRAMS_SELECTOR_INC_MYSELECTOR_BUTTON_H_
#define MYPROGRAMS_SELECTOR_INC_MYSELECTOR_BUTTON_H_

#include "sapi.h"

/** Button debounce FSM states. */
typedef enum{
   STATE_BUTTON_UP,
   STATE_BUTTON_DOWN,
   STATE_BUTTON_FALLING,
   STATE_BUTTON_RISING
} buttonState_t;

/** Button error handler. */
void myButtonError( void );

/** Button initialization. */
void myButtonInit( void );

/** Controls button debounce FSM.
 * @param [in] button Button to control.
*/
void myButtonUpdate( gpioMap_t button );

/** Executes actions when button is pressed. */
void myButtonPressed( void );

/** Executes actions when button is released. */
void myButtonReleased( void );




#endif /* MYPROGRAMS_SELECTOR_INC_MYSELECTOR_BUTTON_H_ */
