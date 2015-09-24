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


int tecla_on(void)
{
	int estadoTecla = 0;
	static int contador = 0;

	uint8_t estadoTecla_4 = 1 ;
	uint8_t estadoTecla_3 = 1 ;
	uint8_t estadoTecla_2 = 1 ;
	uint8_t estadoTecla_1 = 1 ;

	static uint8_t estadoTecla_4_anterior = 1;
	static uint8_t estadoTecla_3_anterior = 1;
	static uint8_t estadoTecla_2_anterior = 1;
	static uint8_t estadoTecla_1_anterior = 1;

	estadoTecla_1 = Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, 4);
	estadoTecla_2 = Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, 8);
	estadoTecla_3 = Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, 9);
	estadoTecla_4 = Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 1, 9);
	//------------------------------------------------------
	estadoTecla = 0;
	contador++;
	if (contador > 100000)
	{
		contador = 0;
		if(estadoTecla_1 == 0)
		{
			if (estadoTecla_1_anterior == 1 )
			{
				estadoTecla = 1;
			}
			else if (estadoTecla_1_anterior == 0)
			{
				estadoTecla = 0;
			}
		}
		estadoTecla_1_anterior = estadoTecla_1;
		//------------------------------------------------------

		if (estadoTecla_2 == 0)
		{
			if (estadoTecla_2_anterior == 1 )
			{
				estadoTecla = 2;

			}else if (estadoTecla_2_anterior == 0)
			{
				estadoTecla = 0;
			}
		}
		estadoTecla_2_anterior = estadoTecla_2;

		//------------------------------------------------------

		if (estadoTecla_3 == 0)
		{
			if (estadoTecla_3_anterior == 1 )
			{
				estadoTecla = 3;

			}
			else if (estadoTecla_3_anterior == 0)
			{
				estadoTecla = 0;
			}
		}
		estadoTecla_3_anterior = estadoTecla_3;

		//------------------------------------------------------

		if(estadoTecla_4 == 0)
		{
			if (estadoTecla_4_anterior == 1 )
			{
				estadoTecla = 4;

			}else if (estadoTecla_4_anterior == 0)
			{
				estadoTecla = 0;
			}
		}
		estadoTecla_4_anterior = estadoTecla_4;
	}
//--------------------------------------------------------------
	return estadoTecla;
}

void inicializarTeclas(void)
{
	/* inicializo*/
	Chip_GPIO_Init(LPC_GPIO_PORT);

	/* inicializo pulsadores */
	Chip_SCU_PinMux(1,0,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* remapea P1_0 en GPIO 0[4], SW1 */
	Chip_SCU_PinMux(1,1,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* remapea P1_1 en GPIO 0[8], SW2 */
	Chip_SCU_PinMux(1,2,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* remapea P1_2 en GPIO 0[9], SW3 */
	Chip_SCU_PinMux(1,6,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* remapea P1_6 en GPIO 1[9], SW4 */

	/* seteo los pulsadores como puerto de entrada  */
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 0, (1<<4)|(1<<9)|(1<<8), 0);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 1, (1<<9), 0);
}
