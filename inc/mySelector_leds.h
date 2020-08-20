/*
 * leds.h
 *
 *  Created on: 13 jul. 2020
 *      Author: pablo
 */

#ifndef MYPROGRAMS_SEMAFORO_INC_LEDS_H_
#define MYPROGRAMS_SEMAFORO_INC_LEDS_H_

#include "sapi.h"

/*! Available colors of the RGB LED. */
typedef enum{
   RGB_COLOR_RED,
   RGB_COLOR_GREEN,
   RGB_COLOR_BLUE
} rgbColor_t;

/*! Turns on given LED.
 * @param [in] led LED to turn on.
 */
bool_t ledTurnOn (gpioMap_t led);

/*! Turns off given LED.
 * @param[in] led LED to turn off.
 */
bool_t ledTurnOff (gpioMap_t led);

/*! Turns on all LEDs. */
void ledTurnOnAll(void);

/*! Turns off all LEDs. */
void ledTurnOffAll(void);

/*! Turns on RGB LED with the input color.
 * @param[in] color Any of the available colors for the RGB LED.
 */
void ledTurnOnRGB(rgbColor_t color);

/*! Turns off RGB LED. */
void ledTurnOffRGB(void);

#endif /* MYPROGRAMS_SEMAFORO_INC_LEDS_H_ */


