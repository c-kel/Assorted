/* ###################################################################
**     Filename    : Events.c
**     Project     : drive
**     Processor   : MK20DX128VLH5
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-11-03, 01:42, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         No public methods
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

# define LOWC 262
# define LOWD 294
# define LOWE 330
#ifdef __cplusplus
extern "C" {
#endif 
extern bool button;
extern uint8 dooty;
uint32 scntr=0;
uint32 bcntr=0;

/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
**     Event       :  EInt1_OnInterrupt (module Events)
**
**     Component   :  EInt1 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void EInt1_OnInterrupt(void)
{
button=1;
if (button==1){
	  Right_Dir_ClrVal();
	  Left_Dir_ClrVal();
	  Right_Spd_SetRatio8(00);
	  Left_Spd_SetRatio8(00);
	  dooty+=20;
//	  PWM1_SetRatio8(dooty);
	  WAIT1_Waitms(100);
	  Right_Dir_SetVal();
	  Left_Dir_SetVal();
	  Right_Spd_SetRatio8(00);
	  Left_Spd_SetRatio8(00);
	  dooty+=20;
//	  PWM1_SetRatio8(dooty);
	  WAIT1_Waitms(100);
//	  button=0;
}
}

/*
** ===================================================================
**     Event       :  TI1_OnInterrupt (module Events)
**
**     Component   :  TI1 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TI1_OnInterrupt(void)
{
	if (bcntr<20000){
		if (scntr>10000/LOWE){
			LEDR_BUZZER_NegVal();
			scntr=0;
		}
		scntr++;
	}
	else if (bcntr>=20000 && bcntr<40000){
		if (scntr>10000/LOWD){
			LEDR_BUZZER_NegVal();
			scntr=0;
		}
		scntr++;
	}
	else if (bcntr>=40000 && bcntr<60000){
		if (scntr>10000/LOWC){
			LEDR_BUZZER_NegVal();
			scntr=0;
		}
		scntr++;
	}
	else if (bcntr>=60000 &&bcntr<80000){
		LEDR_BUZZER_ClrVal();
		scntr++;
	}
	else{
		bcntr=0;
	}
	
	bcntr++;
	
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
