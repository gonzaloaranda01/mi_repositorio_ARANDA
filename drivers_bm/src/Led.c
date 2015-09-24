/* Copyright 2014, Mariano Cerdeiro
 * Copyright 2014, Pablo Ridolfi
 * Copyright 2014, Juan Cecconi
 * Copyright 2014, Gustavo Muro
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief Blinking_echo example source file
 **
 ** This is a mini example of the CIAA Firmware.
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */
/** \addtogroup Examples CIAA Firmware Examples
 ** @{ */
/** \addtogroup Blinking Blinking_echo example source file
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 * ARANDA GONZALO
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20150603 v0.0.3   ErPe change uint8 type by uint8_t
 *                        in line 172
 * 20141019 v0.0.2   JuCe add printf in each task,
 *                        remove trailing spaces
 * 20140731 v0.0.1   PR   first functional version
 */

/*==================[inclusions]=============================================*/
//#include "os.h"               /* <= operating system header */
//#include "ciaaPOSIX_stdio.h"  /* <= device handler header */
//#include "ciaaPOSIX_string.h" /* <= string header */
//#include "ciaak.h"            /* <= ciaa kernel header */
//#include "Led.h"         /* <= own header */
#include "chip.h"         /* <= own header */

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/** \brief File descriptor for digital output ports
 *
 * Device path /dev/dio/out/0
 */

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
/** \brief Main function
 *
 * This is the main entry point of the software.
 *
 * \returns 0
 *
 * \remarks This function never returns. Return value is only to avoid compiler
 *          warnings or errors.
 */

void encender_led(int led)
{

	switch (led)
	{

		case (1):

		    Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 0);
		break;

		case (2):

		     Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 1);
		break;

		case (3):

			  Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 2);
		break;

		case (4):

		      Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 0, 14);
		break;

		case (5):

		     Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 1, 11);
    	break;

		case (6):

		     Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 1, 12);
		break;

	}

}

void apagar_led(int led)
{

	switch (led)
		{

			case (1):
			    Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 0);
			break;

			case (2):
		        Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 1);
	    	break;

			case (3):
	     	    Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 2);
			break;

			case (4):
				Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 0, 14);
			break;

			case (5):
				 Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 1, 11);
	    	break;

			case (6):
		         Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 1, 12);
			break;

		}
}

void inicializar_led(void)
{
	/* inicializo leds*/
	Chip_GPIO_Init(LPC_GPIO_PORT);
    /* */
	Chip_SCU_PinMux(2,0,MD_PUP,FUNC4); 		 /* remapea P2_0 en GPIO5[0], LED0R y habilita el pull up*/
	Chip_SCU_PinMux(2,1,MD_PUP,FUNC4);		 /* remapea P2_1 en GPIO5[1], LED0G y habilita el pull up */
	Chip_SCU_PinMux(2,2,MD_PUP,FUNC4);		 /* remapea P2_2 en GPIO5[2], LED0B y habilita el pull up */
	Chip_SCU_PinMux(2,10,MD_PUP,FUNC0); 	 /* remapea P2_10 en GPIO0[14], LED1 y habilita el pull up */
	Chip_SCU_PinMux(2,11,MD_PUP,FUNC0); 	 /* remapea P2_11 en GPIO1[11], LED2 y habilita el pull up */
	Chip_SCU_PinMux(2,12,MD_PUP,FUNC0); 	 /* remapea P2_12 en GPIO1[12], LED3 y habilita el pull up */

    /* seteo los leds como puerto de salida */
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 5, (1<<2)|(1<<1)|(1<<0), 1); 	   /*LPC_GPIO_PORT, puerto, led, output*/
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 0, (1<<14), 1);   				   /**/
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 1, (1<<11)|(1<<12), 1); 		   /**/

	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 0);
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 1);
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 2);
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 0, 14);
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 1, 11);
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 1, 12);

}
