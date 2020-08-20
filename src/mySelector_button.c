/*
 * mySelector_button.c
 *
 *  Created on: 17 ago. 2020
 *      Author: pablo
 */

#include "mySelector_button.h"
#include "mySelector_blinker.h"

buttonState_t buttonState;
delay_t buttonUpdateTick;


void myButtonPressed( void )
{
 myBlinkerSwitchPeriod();
}

void myButtonReleased( void )
{
}

void myButtonError( void )
{
   myButtonInit();
}

void myButtonInit( void )
{
   buttonState = STATE_BUTTON_UP;  // Set initial state
}


void myButtonUpdate( gpioMap_t button )
{
   static bool_t flagFalling = FALSE;
   static bool_t flagRising = FALSE;

   switch( buttonState ){

      case STATE_BUTTON_UP:
         /* CHECK TRANSITION CONDITIONS */
         if( !gpioRead(button) ){
            buttonState = STATE_BUTTON_FALLING;
         }
      break;

      case STATE_BUTTON_DOWN:
         /* CHECK TRANSITION CONDITIONS */
         if( gpioRead(button) ){
            buttonState = STATE_BUTTON_RISING;
         }
      break;

      case STATE_BUTTON_FALLING:
         /* ENTRY */
         if( flagFalling == FALSE ){
            flagFalling = TRUE;
            break;
         }

         /* CHECK TRANSITION CONDITIONS */
         if( !gpioRead(button) ){
            buttonState = STATE_BUTTON_DOWN;
            myButtonPressed();
         } else{
            buttonState = STATE_BUTTON_UP;
         }

         /* LEAVE */
         if( buttonState != STATE_BUTTON_FALLING ){
            flagFalling = FALSE;
         }
      break;

      case STATE_BUTTON_RISING:
         /* ENTRY */
         if( flagRising == FALSE ){
            flagRising = TRUE;
         break;
         }
         /* CHECK TRANSITION CONDITIONS */
         if( gpioRead(button) ){
            buttonState = STATE_BUTTON_UP;
            myButtonReleased();
         } else{
            buttonState = STATE_BUTTON_DOWN;
         }

         /* LEAVE */
         if( buttonState != STATE_BUTTON_RISING ){
            flagRising = FALSE;
         }
      break;

      default:
        myButtonError();
      break;
   }
}


