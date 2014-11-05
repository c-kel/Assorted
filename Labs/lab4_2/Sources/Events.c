/* ###################################################################
**     Filename    : Events.c
**     Project     : Lab3
**     Processor   : MK20DX128VLH5
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-08-12, 15:32, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

#ifdef __cplusplus
extern "C" {
#endif 

/*int chr = 0;
uint8 r, b, g; // range: 0 to 0xFF
uint8 h=128, s=128, v=128; // range: 0 to 0xFF
*/
/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MK20DX128EX5]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMIINT(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  AS1_OnError (module Events)
**
**     Component   :  AS1 [AsynchroSerial]
**     Description :
**         This event is called when a channel error (not the error
**         returned by a given method) occurs. The errors can be read
**         using <GetError> method.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AS1_OnError(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  AS1_OnRxChar (module Events)
**
**     Component   :  AS1 [AsynchroSerial]
**     Description :
**         This event is called after a correct character is received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled and either the <Receiver>
**         property is enabled or the <SCI output mode> property (if
**         supported) is set to Single-wire mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AS1_OnRxChar(void)
{
/*	char rec=21;     
	char num=21;
	AS1_RecvChar(&rec);


	if (rec=='w'){
		if (chr==0){
			h++;}
		if (chr==1){
			s++;}
		if (chr==2){
			v++;}
	}
	else if (rec=='s'){
		if (chr==0){
			h--;}
		if (chr==1){
			s--;}
		if (chr==2){
			v--;}
	}
	else if ((rec=='a')&&(chr==0)){
		chr=2;}
	else if((rec=='a')&&(chr!=0)){
		chr--;}
	else if((rec=='s')&&(chr==2)){
		chr=0;}
	else if((rec=='s')&&(chr!=2)){
		chr++;}

*/

	//##################################################################
	/* if ((rec<58)&&(rec>47)){
		num=rec-48;	}
	else if ((rec<71)&&(rec>64)){
		num=rec-55;	}
	else if ((rec<103)&&(rec>93)){
		num=rec-87;	}
	else if ((rec==8)||(rec==13)){
		rec=num;	}
	if (chr==6){
		if (rec==13){
//			AS1_SendBlock();
			AS1_SendChar(13);
			AS1_SendChar(10);
			BlueLED_SetRatio8(b);
			GreenLED_SetRatio8(g);
			RedLED_SetRatio8(r);}
		else if(rec==8){		  
			AS1_SendChar(8);
			chr--;}
	}
	else if (chr==5){
		if ((num>=0)&&(num<16)){
			AS1_SendChar(num);
			v=(0xF&v)+0xF*v;
			chr++;}
		else if(num==8){chr--;}
	}

	else if (chr==4){
		if ((num>=0)&&(num<16)){
			AS1_SendChar(num);
			v=(0xF0&v)+v;
			chr++;}
		else if(num==8){chr--;}

	}	
	else if (chr==3){
		if ((num>=0)&&(num<16)){
			AS1_SendChar(num);
			v=(0xF&s)+0xF*s;
			chr++;}
		else if(num==8){chr--;}

	}	
	else if (chr==2){
		if ((num>=0)&&(num<16)){
			AS1_SendChar(num);
			v=(0xF&s)+s;
			chr++;}
		else if(num==8){chr--;}

	}
	else if (chr==1){
		if ((num>=0)&&(num<16)){
			AS1_SendChar(num);
			v=(0xF&h)+0xF*h;
			chr++;}
		else if(num==8){chr--;}
	}
	else if (chr==0){
		if ((num>=0)&&(num<16)){
			AS1_SendChar(num);
			v=(0xF&h)+0xF*h;
			chr++;}

	}
	 */


	// Initialise h, s, and v to the appropriate values

	// Convert HSV to RGB
	/*
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

	BlueLED_SetRatio8(b);
	GreenLED_SetRatio8(g);
	RedLED_SetRatio8(r);
	AS1_SendChar("\r\n");
	AS1_SendChar("truytu");
	AS1_SendChar("\r\n\n\n\n\n\n\n\n\n\n\n");
	/* AS1_SendChar();
	AS1_SendChar();
	AS1_SendChar();
	AS1_SendChar();
	*/
	/*
/* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  AS1_OnTxChar (module Events)
**
**     Component   :  AS1 [AsynchroSerial]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AS1_OnTxChar(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  AS1_OnFullRxBuf (module Events)
**
**     Component   :  AS1 [AsynchroSerial]
**     Description :
**         This event is called when the input buffer is full;
**         i.e. after reception of the last character 
**         that was successfully placed into input buffer.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AS1_OnFullRxBuf(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  AS1_OnFreeTxBuf (module Events)
**
**     Component   :  AS1 [AsynchroSerial]
**     Description :
**         This event is called after the last character in output
**         buffer is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AS1_OnFreeTxBuf(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  TSS1_fOnFault (module Events)
**
**     Component   :  TSS1 [TSS_Library]
**     Description :
**         This callback function is called by TSS after Fault
**         occurence. This event is enabled always and depends on
**         selection 'generate code' if the callback is used.
**         The default CallBack Name is automatically generated with
**         automatic prefix update by current Component Name. User can
**         define own name, but then the automatic name update is not
**         functional.
**         Option is available from TSS3.0 version.
**     Parameters  :
**         NAME            - DESCRIPTION
**         u8FaultElecNum  - The value defines
**                           electrode number on which measurement fault
**                           occured.
**     Returns     : Nothing
** ===================================================================
*/
void TSS1_fOnFault(byte u8FaultElecNum)
{
  #if TSS_USE_PE_COMPONENT
  /* If large or small capacitor fault  */
  if(tss_CSSys.Faults.ChargeTimeout || tss_CSSys.Faults.SmallCapacitor)
  {
    /* Write your code here ... */
  }
  /* If data corruption fault  */
  if(tss_CSSys.Faults.DataCorruption)
  {
    /* Write your code here ... */
  }
  /* If small trigger period fault  */
  if(tss_CSSys.Faults.SmallTriggerPeriod)
  {
    /* Write your code here ... */
  }
  /* Clear the fault flags */
  (void) TSS_SetSystemConfig(System_Faults_Register, 0x00);

  (void) u8FaultElecNum;
  return;
  #endif
}

/*
** ===================================================================
**     Event       :  TSS1_fOnInit (module Events)
**
**     Component   :  TSS1 [TSS_Library]
**     Description :
**         This callback function is automatically called during the
**         TSS Init function execution. The function is intended for
**         implementation of peripherals initialization. TSS Component
**         automatically enables clock for all used TSS peripherals in
**         the internal function TSS_InitDevices which is called by
**         this callback.
**         This event is enabled always and depends on selection
**         'generate code' if the callback is used.
**         The default CallBack Name is automatically generated with
**         automatic prefix update by current Component Name. User can
**         define own name, but then the automatic name update is not
**         functional.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TSS1_fOnInit(void)
{
  #if TSS_USE_PE_COMPONENT
    TSS1_InitDevices();
  #endif

  /* Write your code here ... */

}

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

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
