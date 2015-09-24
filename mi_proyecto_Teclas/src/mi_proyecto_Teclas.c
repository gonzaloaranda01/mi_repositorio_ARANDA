/* Copyright 2015, Eduardo Filomena, Juan Manuel Reta
 * All rights reserved.
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

/** \brief Blinking Bare Metal example source file
 **
 ** This is a mini example of the CIAA Firmware.
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */

/** \addtogroup Examples CIAA Firmware Examples
 ** @{ */
/** \addtogroup Baremetal Bare Metal example source file
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 *
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
 */

/*==================[inclusions]=============================================*/
#include "mi_proyecto_Teclas.h"       /* <= own header */
#include "Led.h"
#include "Teclas.h"


#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif


/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

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
//static int32_t LED_RGB_r;

# define LED_rojo 5
# define LED_verde 6
# define LED_naranja 4
# define LED_RGB_v 2
# define LED_RGB_a 3
# define LED_RGB_r 1
# define TECLA_1 1

void main(void)
{
         /* perform the needed initialization here */
	 	int Tecla=0;
	 	int Rojo,Verde,Naranja,Blanco;

	 	Rojo = Verde = Naranja = Blanco = 0;
	 	/*inicializo drivers*/
		inicializar_led();
        inicializarTeclas();

		while(1)
		{
			Tecla = tecla_on();
			//-------------------------------------------
			if (Tecla == 2)
			{
				if( Naranja == 1)
				{
					Naranja = 0;
					apagar_led(LED_naranja);
				}
				else
				{
					Naranja = 1;
					encender_led(LED_naranja);
				}
			}
			if (Tecla == 3)
			{
				if( Rojo == 1)
				{
					Rojo = 0;
					apagar_led(LED_rojo);
				}
				else
				{
					Rojo = 1;
					encender_led(LED_rojo);
				}
			}
			if (Tecla == 1)
			{
				if( Blanco == 1)
				{
					Blanco = 0;
					apagar_led(LED_RGB_a);
					apagar_led(LED_RGB_v);
					apagar_led(LED_RGB_r);
				}
				else
				{
					Blanco = 1;
					encender_led(LED_RGB_v);
					encender_led(LED_RGB_r);
					encender_led(LED_RGB_a);
				}
			}
			if (Tecla == 4)
			{
				if( Verde == 1)
				{
					Verde = 0;
					apagar_led(LED_verde);
				}
				else
				{
					Verde = 1;
					encender_led(LED_verde);
				}
			}
		}
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

