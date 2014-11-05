/* ###################################################################
**     Filename    : main.c
**     Project     : Lab8v1
**     Processor   : MK20DX128VLH5
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-09-21, 20:40, # CodeGen: 0
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
#include "mqx_tasks.h"
#include "MQX1.h"
#include "SystemTimer1.h"
#include "Accel.h"
#include "IntI2cLdd1.h"
#include "Light_Sense.h"
#include "AdcLdd1.h"
#include "Term1.h"
#include "Inhr1.h"
#include "ASerialLdd1.h"
#include "USB1.h"
#include "USB0.h"
#include "HIDM1.h"
#include "Tx2.h"
#include "CS1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
LWSEM_STRUCT adcsem;
LWSEM_STRUCT i2csem;
LWSEM_STRUCT uartsem; // global variable
word snt;
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)


/*lint -restore Enable MISRA rule (6.3) checking. */
{
   /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  
  /* Write your code here */
  /* For example: for(;;) { } */
  _lwsem_create(&adcsem, 1);
  _lwsem_create(&i2csem, 1);
  _lwsem_create(&uartsem, 1);
  byte aslp_cnt	[2]=  {0x29, 0x5e};
  byte ctrl_reg1[2]= {0x2a, 0x01};//fast mode, active
  //CI2C1_SelectSlave(0x1d); //select mma8451q with sa=1
  Accel_SendBlock(ctrl_reg1, 2, &snt); //sleep& data rate 12.5hz, fast read on, active mode
  Accel_SendStop();
  Accel_SendBlock(aslp_cnt, 2, &snt); //30sec sleep time
  Accel_SendStop();
  //Term1_SetColor(clGreen, clBlack);

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} 

/*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

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
