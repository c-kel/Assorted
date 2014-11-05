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
#include "Accel.h"
#include "IntI2cLdd1.h"
#include "Term1.h"
#include "Inhr1.h"
#include "ASerialLdd1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
//LWSEM_STRUCT i2csem;
//LWSEM_STRUCT uartsem;
word * snt;
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)


/*lint -restore Enable MISRA rule (6.3) checking. */
{
   /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  
  /* Write your code here */
  /* For example: for(;;) { } */
 // _lwsem_create(&adcsem, 1);
 // _lwsem_create(&i2csem, 1);
  //_lwsem_create(&uartsem, 1);
 // Light_Sense_Calibrate(TRUE);
  byte f_setup[2]={0x09, 0x40};
  byte aslp_cnt[2]={0x29, 0xff};
  byte ctrl_reg1[2]={0x2a, 0x03};
  byte xyz_data_cfg[2]={0x0e, 0x01};
  byte w_f_status[2]={0x00, 0x00};
  uint8 out_x_msb_addr=0x01;
  uint8 out_x_lsb_addr=0x02;
  uint8 out_y_msb_addr=0x03;
  uint8 out_y_lsb_addr=0x04;
  uint8 out_z_msb_addr=0x05;
  uint8 out_z_lsb_addr=0x06;
  byte * r_f_status;
  /*  uint8 data[196];
  float x_data[32];
  float y_data[32];
  float z_data[32];
  float tprint[6]={0,0,0,0,0,0};
   */

  //CI2C1_SelectSlave(0x1d); //select mma8451q with sa=1
  Accel_SendBlock(ctrl_reg1, 2, snt); //sleep& data rate 12.5hz, fast read on, active mode
  
  Accel_SendBlock(aslp_cnt, 2, snt); //81sec sleep time
 // Accel_SendStop();
  Accel_SendBlock(f_setup, 2, snt); //circular fifo
  //Accel_SendStop();
  Accel_SendBlock(xyz_data_cfg, 2, snt); //4g dynamic range
  //Accel_SendStop();
  //Term1_SetColor(clGreen, clBlack);
  for(;;){
	  Accel_SendBlock(w_f_status, 1, snt);
	  Accel_RecvBlock(r_f_status, 1, snt);
	 // Accel_SendStop();
/*	  if(r_f_status&&0x80){
		  Accel_SendBlock(out_x_msb_addr, 1, snt);
		  Accel_RecvBlock(data, 196, snt);
		//  Accel_SendStop();
		  int i;
		  int j;
		  for (i<32;i++;i=0){
			  for (j<6; j+=2; j=0){
				  if (i<16){
					  tprint[j]=0.01*tprint[j]+  0.99*(  -2*(data[6*i+j]&&0x20)  +(data[6*i+j]&&0x1f)/16+  data[6*i+j+1]/4096);
				  }



				  else {
					  tprint[j+3]=0.01*tprint[j+3]+  0.99*(  -2*(data[6*i+j]&&0x20)+  (data[6*i+j]&&0x1f)/16  +  data[6*i+j+1]/4096);
				  }

			  }
		  }
		  Term1_CRLF();
		  for(i<2;i++;i=0){
			  Term1_CRLF();
			  for(j<3;j++;j=0){
				  Term1_SendFloatNum(tprint[i+j]);
				  Term1_SendStr(',');
			  }
		  }
	  }
*/
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
