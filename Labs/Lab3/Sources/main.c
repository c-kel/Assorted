/* ###################################################################
**     Filename    : main.c
**     Project     : Lab3
**     Processor   : MK20DX128VLH5
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-08-12, 15:32, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "RedLED.h"
#include "PwmLdd1.h"
#include "GreenLED.h"
#include "PwmLdd2.h"
#include "BlueLED.h"
#include "PwmLdd3.h"
#include "TU1.h"
#include "Term1.h"
#include "Inhr1.h"
#include "ASerialLdd2.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
//#############################################################################
  char z;
  //int chr = 0;
  uint8 r, b, g; // range: 0 to 0xFF
  uint8 h=128, s=128, v=128; // range: 0 to 0xFF
  for(;;){
/*AS1_RecvChar(&b);
  AS1_SendChar(b);
  }
*/
  
  Term1_ReadChar(&z);
  if (z=='q'){
h++;}
else if (z=='a'){
	h--;}
else if (z=='w'){
	s++;}
else if (z=='s'){
	s--;}
else if (z=='e'){
	v++;}
else if (z=='d'){
		v--;}
	// Convert HSV to RGB
	uint8 region = h / 43;
	uint8 remainder = (h - (region * 43)) * 6;
	uint8 p = (v * (255 - s)) >> 8;
	uint8 q = (v * (255 - ((s * remainder) >> 8))) >> 8;
	uint8 t = (v * (255 - ((s * (255 - remainder)) >> 8))) >> 8;
	switch (region) {
	case 0:
		r = v; g = t; b = p; break;
	case 1:
		r = q; g = v; b = p; break;
	case 2: 
		r = p; g = v; b = t; break;
	case 3:
		r = p; g = q; b = v; break;
	case 4:
		r = t; g = p; b = v; break;
	case 5:
		r = v; g = p; b = q; break;
		}
		
		BlueLED_SetRatio8(b);
	GreenLED_SetRatio8(g);
	RedLED_SetRatio8(r);  
  Term1_SetColor(clYellow, clBlack);
  Term1_CRLF();
  Term1_SendStr("press buttons");
  Term1_CRLF();
  Term1_SendStr("hue      satu       space");
  Term1_CRLF();
  Term1_SendNum(h);
  Term1_SendStr("      ");
  Term1_SendNum(s);
  Term1_SendStr("      ");
  Term1_SendNum(v);
  Term1_CRLF();
  Term1_SendStr("red      green       blue");
  Term1_CRLF();
 Term1_SendNum(r);
 Term1_SendStr("      ");
  Term1_SendNum(g);
  Term1_SendStr("      ");
  Term1_SendNum(b);
  Term1_CRLF();

	

  

	// r, b, g now contain the converted values in RGB colour space


  
  
  
  }
  
  
  
  
  
  
  
  
  
  
  

 // AS1_SendBlock(s);
  //char *s = "Hello";
//#################################################################################
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
