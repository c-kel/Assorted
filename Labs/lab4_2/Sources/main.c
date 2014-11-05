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
#include "CI2C1.h"
#include "IntI2cLdd1.h"
#include "FC321.h"
#include "RealTimeLdd1.h"
#include "TU2.h"
#include "TSS1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
//###################################here
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
	/* Write your local variable definition here */

	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/
	//#############################################################################
	//char z;
	//int chr = 0;
	uint8 r, b, g; // range: 0 to 0xFF
	uint8 h=0, s=0, v=0; // range: 0 to 0xFF
	uint8 x=0, y=0, z=0;
	byte aslp_cnt[2];
		aslp_cnt[0]=0x29,aslp_cnt[1]= 0x5e;
	byte ctrl_reg1[2];
		ctrl_reg1[0]=0x2a,ctrl_reg1[1]= 0x03;
	word snt;
	byte vec[3];
		vec[0]=0,vec[1]=0,vec[2]=0;
	
	byte c=0;
	word t ; //timer and accel status register
	CI2C1_SelectSlave(0x1d); //select mma8451q with sa=1
	CI2C1_SendBlock(ctrl_reg1, 2, &snt); //sleep& data rate 12.5hz, fast read on, active mode
	CI2C1_SendStop();
	CI2C1_SendBlock(aslp_cnt, 2, &snt); //30sec sleep time
	CI2C1_SendStop();
	Term1_SetColor(clGreen, clBlack);
	for(;;){
		FC321_Reset();//reset free counter
		do {FC321_GetTimeMS(&t);} 
		while (t<80); //wait 80ms
		
		CI2C1_SendChar(0x01);
		CI2C1_RecvBlock(vec, 3, &snt);
		CI2C1_SendStop();
		x=vec[0], y=vec[1], z=vec[2];
		h=x, s=y, v=z; 
		
		
		CI2C1_SendChar(0x00);
		CI2C1_RecvChar(&c);
		CI2C1_SendStop();
		/*
		if (c&0x01){				//x data ready
			CI2C1_SendChar(0x01);
			CI2C1_RecvChar(&x);
			h=x<<1;
		}
		if (c&0x02){				//y data ready
			CI2C1_SendChar(0x03);
			CI2C1_RecvChar(&y);
			s=y<<1;
		}
		if (c&0x04){				//z data ready
			CI2C1_SendChar(0x05);
			CI2C1_RecvChar(&z);
			v=z<<1;
		}

		*/


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
		
		// r, b, g now contain the converted values in RGB colour space
		 
		
		
		
		RedLED_SetRatio8(r);
		GreenLED_SetRatio8(g);           //set rbg led
		BlueLED_SetRatio8(b);
		Term1_CRLF();
		Term1_SendStr(" x: ");    		//print raw values
		Term1_SendNum(x);
		Term1_SendStr("      y: ");
		Term1_SendNum(y);
		Term1_SendStr("      z: ");
		Term1_SendNum(z);
		



	

  
  
  
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
