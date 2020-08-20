/*
 * mySelector_blinker.c
 *
 *  Created on: 19 ago. 2020
 *      Author: pablo
 */


#include "mySelector_blinker.h"

blinkerState_t blinkerState;	/**< Blinker state for updating the FSM */
blinkerPeriod_t blinkerPeriod;	/**< Blinker period between blinks of the blinker */
delay_t blinkerOnDelay;			/**< Delay used to control the time the led is ON */
delay_t blinkerOffDelay;		/**< Delay used to control the time the led is OFF */



void myBlinkerError( void ){
	uartWriteString( UART_USB, "ERROR DETECTED: REINITIALIZING...\r\n" );
	myBlinkerInit();
}

void myBlinkerInit( void ){
	delayInit(&blinkerOffDelay,5000);
	delayInit(&blinkerOnDelay,BLINK_TIME_ON);
	blinkerState = STATE_LED_OFF;
	blinkerPeriod= BLINKER_PERIOD_FIVE_SECONDS;
	ledTurnOnRGB(RGB_COLOR_RED);
	uartConfig( UART_USB, 115200 );
	uartWriteString( UART_USB, "INITIALIZING BLINKER\r\n" );
	myBlinkerReportPeriod();
}

void myBlinkerReportPeriod(void){
	switch(blinkerPeriod){
		case BLINKER_PERIOD_FIVE_SECONDS:
			uartWriteString( UART_USB, "Blinker period: 5 seconds\r\n" );
			break;
		case BLINKER_PERIOD_TEN_SECONDS:
			uartWriteString( UART_USB, "Blinker period: 10 seconds\r\n" );
			break;
		case BLINKER_PERIOD_FIFTEEN_SECONDS:
			uartWriteString( UART_USB, "Blinker period: 15 seconds\r\n" );
			break;
	}
}

void myBlinkerSetPeriod(blinkerPeriod_t period){

	switch(period){

		case BLINKER_PERIOD_FIVE_SECONDS:
			delayWrite(&blinkerOffDelay,5000);
			delayRestart(&blinkerOffDelay);
			blinkerPeriod = BLINKER_PERIOD_FIVE_SECONDS;
			break;

		case BLINKER_PERIOD_TEN_SECONDS:
			delayWrite(&blinkerOffDelay,10000);
			delayRestart(&blinkerOffDelay);
			blinkerPeriod = BLINKER_PERIOD_TEN_SECONDS;
			break;

		case BLINKER_PERIOD_FIFTEEN_SECONDS:
			delayWrite(&blinkerOffDelay,15000);
			delayRestart(&blinkerOffDelay);
			blinkerPeriod = BLINKER_PERIOD_FIFTEEN_SECONDS;
			break;

		default:
			myBlinkerError();
			break;
	}
}

void myBlinkerUpdate( gpioMap_t led ){

	static bool_t blinkerTurningOn = FALSE;
	static bool_t blinkerTurningOff = FALSE;

	switch(blinkerState){

		case STATE_LED_ON:
			if(blinkerTurningOn){
				ledTurnOn(led);
				blinkerTurningOn = FALSE;
			}
			if(delayRead(&blinkerOnDelay)){
				blinkerState = STATE_LED_OFF;
				blinkerTurningOff = TRUE;
			}
			break;

		case STATE_LED_OFF:
			if(blinkerTurningOff){
				ledTurnOff(led);
				blinkerTurningOff = FALSE;
			}
			if(delayRead(&blinkerOffDelay)){
				blinkerState = STATE_LED_ON;
				blinkerTurningOn = TRUE;
			}
			break;
	}
}

void myBlinkerSwitchPeriod( void ){
	switch(blinkerPeriod){

		case BLINKER_PERIOD_FIVE_SECONDS:
			myBlinkerSetPeriod(BLINKER_PERIOD_TEN_SECONDS);
			ledTurnOnRGB(RGB_COLOR_GREEN);
			break;

		case BLINKER_PERIOD_TEN_SECONDS:
			myBlinkerSetPeriod(BLINKER_PERIOD_FIFTEEN_SECONDS);
			ledTurnOnRGB(RGB_COLOR_BLUE);
			break;

		case BLINKER_PERIOD_FIFTEEN_SECONDS:
			myBlinkerSetPeriod(BLINKER_PERIOD_FIVE_SECONDS);
			ledTurnOnRGB(RGB_COLOR_RED);
			break;

		default:
			myBlinkerError();
			break;
	}
	myBlinkerReportPeriod();
}
