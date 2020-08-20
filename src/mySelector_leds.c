/*
 * leds.c
 *
 *  Created on: 9 jul. 2020
 *      Author: pablo
 */

#include "mySelector_leds.h"



bool_t ledTurnOn (gpioMap_t led){
	return gpioWrite(led,ON);
}

bool_t ledTurnOff (gpioMap_t led){
	return gpioWrite(led,OFF);
}


void ledTurnOnAll(void){
	gpioWrite(LEDR,ON);
	gpioWrite(LEDG,ON);
	gpioWrite(LEDB,ON);
	gpioWrite(LED1,ON);
	gpioWrite(LED2,ON);
	gpioWrite(LED3,ON);
}

void ledTurnOffAll(void){
	gpioWrite(LEDR,OFF);
	gpioWrite(LEDG,OFF);
	gpioWrite(LEDB,OFF);
	gpioWrite(LED1,OFF);
	gpioWrite(LED2,OFF);
	gpioWrite(LED3,OFF);
}


void ledTurnOnRGB(rgbColor_t color){
	switch(color){
		case RGB_COLOR_RED:
			gpioWrite(LEDR,ON);
			gpioWrite(LEDG,OFF);
			gpioWrite(LEDB,OFF);
			break;
		case RGB_COLOR_GREEN:
			gpioWrite(LEDR,OFF);
			gpioWrite(LEDG,ON);
			gpioWrite(LEDB,OFF);
			break;
		case RGB_COLOR_BLUE:
			gpioWrite(LEDR,OFF);
			gpioWrite(LEDG,OFF);
			gpioWrite(LEDB,ON);
			break;
	}
}

void ledTurnOffRGB(void){
	gpioWrite(LEDR,OFF);
	gpioWrite(LEDG,OFF);
	gpioWrite(LEDB,OFF);
}
