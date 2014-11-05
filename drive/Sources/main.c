/* ###################################################################
**     Filename    : main.c
**     Project     : SPI_Test
**     Processor   : MK20DX128VLH5
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-09-22, 17:56, # CodeGen: 0
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
#include "Right_Dir.h"
#include "BitIoLdd1.h"
#include "Left_Dir.h"
#include "BitIoLdd2.h"
#include "Right_Spd.h"
#include "PwmLdd1.h"
#include "TU1.h"
#include "Left_Spd.h"
#include "PwmLdd2.h"
#include "LEDR_BUZZER.h"
#include "BitIoLdd4.h"
//#include "CE.h"
//#include "BitIoLdd3.h"
//#include "SM1.h"
//#include "SMasterLdd1.h"
//#include "LEDR.h"
//#include "BitIoLdd4.h"
//#include "LEDG.h"
//#include "BitIoLdd5.h"
//#include "LEDB.h"
//#include "BitIoLdd6.h"
//#include "CSN.h"
//#include "BitIoLdd7.h"
//#include "IRQ.h"
//#include "ExtIntLdd1.h"
#include "WAIT1.h"
#include "TI1.h"
#include "TimerIntLdd1.h"
#include "EInt1.h"
#include "ExtIntLdd2.h"
#include "TU2.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
bool button=0;
uint8 dooty=0;

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
 //*/

  for(;;){
	  dooty=0;
	 // PWM1_SetRatio8(dooty);
	  if (button==1){
//		  Right_Dir_ClrVal();
//		  Left_Dir_ClrVal();
//		  Right_Spd_SetRatio8(255);
//		  Left_Spd_SetRatio8(255);
//		  WAIT1_Waitms(100);
//		  Right_Dir_SetVal();
//		  Left_Dir_SetVal();
//		  Right_Spd_SetRatio8(255);
//		  Left_Spd_SetRatio8(255);
//		  WAIT1_Waitms(100);
		  button=0;
	  }
	  else {

		  Right_Dir_ClrVal();
		  Left_Dir_ClrVal();
		  Right_Spd_SetRatio8(255);
		  Left_Spd_SetRatio8(255);
		  WAIT1_Waitms(50);
		  Right_Spd_SetRatio8(200);
		  Left_Spd_SetRatio8(200);
		  WAIT1_Waitms(50);
		  Right_Spd_SetRatio8(150);
		  Left_Spd_SetRatio8(150);
		  WAIT1_Waitms(50);
		  Right_Spd_SetRatio8(100);
		  Left_Spd_SetRatio8(100);
		  WAIT1_Waitms(50);
		  Right_Spd_SetRatio8(50);
		  Left_Spd_SetRatio8(50);
		  WAIT1_Waitms(50);
		  Right_Dir_SetVal();
		  Left_Dir_SetVal();
		  int i;
		  for(i=0; i<7;i++){
			  Right_Spd_SetRatio8(00);
			  Left_Spd_SetRatio8(00);
			  WAIT1_Waitms(100);
		  }
	  }
  }
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
