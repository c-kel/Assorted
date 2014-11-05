/* ###################################################################
 **     Filename    : main.c
 **     Project     : ex_spi_g8
 **     Processor   : MK20DX128VLH5
 **     Version     : Driver 01.01
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2014-10-22, 12:35, # CodeGen: 0
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
#include "SM1.h"
#include "SMasterLdd1.h"
#include "Term1.h"
#include "Inhr1.h"
#include "ASerialLdd1.h"

#include "CE.h"
#include "BitIoLdd1.h"
#include "CSN.h"
#include "BitIoLdd2.h"
#include "IRQ.h"
#include "ExtIntLdd1.h"
#include "WAIT1.h"
#include "UTIL1.h"
#include "WAIT2.h"
#include "FRTOS1.h"
#include "UTIL2.h"
#include "LED1.h"
#include "LEDpin1.h"
#include "BitIoLdd6.h"
#include "LED2.h"
#include "LEDpin2.h"
#include "BitIoLdd7.h"
#include "LED3.h"
#include "LEDpin3.h"
#include "BitIoLdd8.h"
/* Including shared modules, which are used for whole project */
#if nnnrf
#include "RStack.h"
#endif

#include "RNet_App.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
const SM1_TComData R_REGISTER_CONFIG 	= 0x00;
const SM1_TComData R_SETUP_RETR  		= 0x04;
const SM1_TComData R_RX_PAYLOAD 		= 0b01100001;
const SM1_TComData W_TX_PAYLOAD 		= 0b10100000;
const SM1_TComData FLUSH_TX 			= 0b11100001;
const SM1_TComData FLUSH_RX 			= 0b11100010;
const SM1_TComData NOP 					= 0xFF;

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
	/* Write your local variable definition here */

	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/
	SM1_TComData config[2]		={0x20,0x3a}; 	//byte
	SM1_TComData setup_retr[2]	={0x24, 0x0c};
	byte SM1_Status;
	SM1_TComData rcon[5]={0,0,0,0,0};
	//SM1_TComData 
	
	word rdummy;
	word tdummy;
#if nnnrf
	uint8 staz;
	RSTACK_Init();
	WAIT2_Waitms(150);
	RF1_WriteRegister(0x00, 0x3a);

	for(;;){
		staz = RF1_ReadRegister(0x00);
		Term1_SendNum(staz);
		WAIT2_Waitms(500);


	}
#endif
	for(;;){

#if	SSN	
		CSN_ClrVal();
		WAIT2_Waitus(1);
#endif
		SM1_Status= SM1_SendBlock(config	,2,&tdummy);      
#if SSN
		CSN_SetVal();
		WAIT2_Waitus(1);
#endif
		if (SM1_Status == ERR_OK) {
			Term1_SendStr("ERR_OK \n");
		}
		else if (SM1_Status == ERR_SPEED) {
			Term1_SendStr("ERR_SPEED \n");
		}
		else if (SM1_Status == ERR_DISABLED) {
			Term1_SendStr("ERR_DISABLED \n");
		}
		else if (SM1_Status == ERR_TXFULL){
			Term1_SendStr("ERR_TXFULL \n");
		}

#if SSN
		CSN_ClrVal();
		WAIT2_Waitus(1);
#endif

		SM1_Status= SM1_SendBlock(setup_retr,2,&tdummy);

#if SSN
		WAIT2_Waitus(1);
		CSN_SetVal();
#endif
		if (SM1_Status == ERR_OK) {
			Term1_SendStr("ERR_OK \n");
		}
		else if (SM1_Status == ERR_SPEED) {
			Term1_SendStr("ERR_SPEED \n");
		}
		else if (SM1_Status == ERR_DISABLED) {
			Term1_SendStr("ERR_DISABLED \n");
		}
		else if (SM1_Status == ERR_TXFULL){
			Term1_SendStr("ERR_TXFULL \n");
		}

#if SSN
		CSN_ClrVal();
		WAIT2_Waitus(1);
#endif

		SM1_SendChar(R_REGISTER_CONFIG);
		SM1_Status= SM1_RecvBlock(rcon,1,&rdummy);

#if SSN
		WAIT2_Waitus(1);
		CSN_SetVal();
#endif
		if (SM1_Status == ERR_OK) {
			Term1_SendStr("ERR_OK \n");	
		}
		else if (SM1_Status == ERR_SPEED) {
			Term1_SendStr("ERR_SPEED \n");
		}
		else if (SM1_Status == ERR_RXEMPTY){
			Term1_SendStr("ERR_RXEMPTY \n");
			LED1_On();
		}
		else if (SM1_Status == ERR_OVERRUN) {
			Term1_SendStr("ERR_OVERRUN \n");
		}
		else if (SM1_Status == ERR_FAULT){
			Term1_SendStr("ERR_FAULT \n");
		}

		Term1_SendNum(rcon[0]);
		Term1_SendStr(",");
		Term1_SendNum(rcon[1]);
		Term1_SendStr(",");
		Term1_SendNum(rdummy);
		if (rdummy){
			LED2_On();			
		}
		//		Term1_SendStr(",");
		//		Term1_SendNum(rcon[3]);
		//		Term1_SendStr(",");
		//		Term1_SendNum(rcon[4]);


		Term1_SendStr("\n");
#if SSN
		CSN_ClrVal();
		WAIT2_Waitus(1);
#endif

		SM1_SendChar(NOP);
		SM1_Status= SM1_RecvChar(rcon);

#if SSN
		WAIT2_Waitus(1);
		CSN_SetVal(); 
#endif
		if (SM1_Status == ERR_OK) {
			Term1_SendStr("ERR_OK \n");	
		}
		else if (SM1_Status == ERR_SPEED) {
			Term1_SendStr("ERR_SPEED \n");
		}
		else if (SM1_Status == ERR_RXEMPTY){
			Term1_SendStr("ERR_RXEMPTY \n");
		}
		else if (SM1_Status == ERR_OVERRUN) {
			Term1_SendStr("ERR_OVERRUN \n");
		}
		else if (SM1_Status == ERR_FAULT){
			Term1_SendStr("ERR_FAULT \n");
		}
		Term1_SendNum(*rcon);

		Term1_CRLF();

		SM1_ClearRxBuf();
		WAIT2_Waitms(300);
		LED1_Off();
		LED2_Off();
	}
	/* Write your code here */
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
