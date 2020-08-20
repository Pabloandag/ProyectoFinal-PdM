/*
 * mySelector_delay.c
 *
 *  Created on: 20 ago. 2020
 *      Author: pablo
 */

#include "mySelector_delay.h"

void delayRestart(delay_t* delay){
	delay->startTime = tickRead();
}
