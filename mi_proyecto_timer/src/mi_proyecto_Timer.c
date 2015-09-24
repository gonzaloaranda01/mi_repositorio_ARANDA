/* Copyright 2015, ARANDA GONZALO
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
/*
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
 */

/*==================[inclusions]=============================================*/
#include "mi_proyecto_Timer.h"       /* <= own header */




/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
//external void ISR_timer(void);

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

# define OFF 0
# define ON 1
# define TIME 250

int Count = 0;

void ISR_timer (void)
{
	timer_off();
	Count++;

}

int main(void)
{
         /* perform the needed initialization here */

       int Tecla = 0;
       int aux = 0;

	 	/*inicializo drivers*/
		inicializar_led();
        inicializarTeclas();

        /* timer*/
        inicializarTimer(TIME);
        habilitoInterrupcion();

        /*loop*/
		while(1)
		{
            Tecla = tecla_on();

            if(Tecla == 1)
            {
	        	if (aux == 0)
	        	{
	        	Count = 0;
	            aux = 1;
	        	} else if (aux==1)
	        	{
	        		aux =0;
	        	}
            }

            if (aux ==1){secuencia();}

        }
}
/* funcion secuencia de LEDs*/

void secuencia(void)
{

	switch(Count)
	{

	case (1):
              encender_led(LED_verde);
	          apagar_led(LED_RGB_a);
			  apagar_led(LED_RGB_a);
	break;

	case (2):
	        	encender_led(LED_rojo);
	        	apagar_led(LED_verde);

	break;

	case (3):
				 apagar_led(LED_rojo);
	    	     apagar_led(LED_verde);
                 encender_led(LED_naranja);

	break;

	case (4):
                apagar_led(LED_naranja);
                apagar_led(LED_rojo);
	        	apagar_led(LED_verde);
	        	encender_led(LED_RGB_a);

	        	Count = 0;
	break;


    }

}
/*==================[end of file]============================================*/

