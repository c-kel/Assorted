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
#include "TU1.h"
#include "CE.h"
#include "BitIoLdd3.h"
#include "SM1.h"
#include "SMasterLdd1.h"
#include "LEDR.h"
#include "BitIoLdd4.h"
#include "LEDG.h"
#include "BitIoLdd5.h"
#include "LEDB.h"
#include "BitIoLdd6.h"
#include "TU2.h"
#include "CSN.h"
#include "BitIoLdd7.h"
#include "IRQ.h"
#include "ExtIntLdd1.h"
#include "WAIT1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#define CD_ADDR 0x09
#define FIFO_STATUS_ADDR 0X17
#define STATUS_ADDR 0X07

// #define 
const uint8 CONFIG_TX[2]={0x20, 0b00111010};
const uint8 CONFIG_RX[2]={0x20, 0b01001011};
const uint8 SETUP_RETR[2]={0x24, 0x0A};
const uint8 RF_CH[2]={0x25, 0b00011101};
const uint8 RX_PW_P0[2]={0x31, 0x05};
const uint8 TEST_BLOCK[6]={0x90, 0, 4,3,2,1};

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  uint8  status;
  uint8 statusad= 0;
  word  Snd;
  uint8 spin= 0;
  LDD_TDeviceData* dummy;
  LDD_TDeviceData* rummy;
  word *Time;
 //rummy=0;
  //dummy = SM1_Init(rummy);
  Left_Dir_ClrVal();
  Right_Dir_ClrVal();
  Left_Spd_SetRatio8(255);
  Right_Spd_SetRatio8(255);
  //*
  for(;;){
	//  Left_Dir_SetVal();
	//  Right_Dir_SetVal();
	  //FC321_Reset();
	  *Time=0;
	 // while (*Time<500){
//	  FC321_GetTimeMS(Time);
	  //}
	  Left_Dir_ClrVal();
	  Right_Dir_ClrVal();
	 // FC321_Reset();
	  *Time=0;
	//  while (*Time<500){
	//	  FC321_GetTimeMS(Time);
	//  }


  }
  //*/
  for(;;){}
/*
  SM1_SendBlock(dummy, CONFIG_TX, 2);
  SM1_SendBlock(dummy, SETUP_RETR, 2);
  SM1_SendBlock(dummy, RF_CH, 2);
  SM1_SendBlock(dummy, RX_PW_P0, 2);
  SM1_SendBlock(dummy, &statusad, 1);
  SM1_ReceiveBlock(dummy, &status, 1);
   */ 
	  /*
	  Right_Dir_ClrVal();
	 SM1_SendBlock(CONFIG_TX,2, &Snd);
	 Right_Dir_SetVal();
	 
	 Right_Dir_ClrVal();
	 SM1_SendBlock(&statusad, 1, &Snd);
	  SM1_RecvBlock(&status, 1 ,&Snd);
	  Right_Dir_SetVal();
  */
  /*
	  Left_Dir_ClrVal();
	  Right_Dir_SetVal();
	  Left_Spd_SetRatio8(255);
	  	  Right_Spd_SetRatio8(25);
	  int abc;
	  for(abc<100000;abc++;abc=0){};
	  Left_Spd_SetRatio8(256);
	  Right_Spd_SetRatio8(256);
	  for(abc<100000;abc++;abc=0){};
	  Left_Spd_SetRatio8(256);
	  Right_Spd_SetRatio8(0);
  
  */
  /* For example: for(;;) { } */

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
