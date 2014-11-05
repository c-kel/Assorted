/* ###################################################################
**     Filename    : Events.h
<<<<<<< HEAD
**     Project     : Lab4v1
=======
**     Project     : Lab3
>>>>>>> b7cccee2cb6e8b4139e62868eb20e77308d79017
**     Processor   : MK20DX128VLH5
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
<<<<<<< HEAD
**     Date/Time   : 2014-08-14, 23:19, # CodeGen: 0
=======
**     Date/Time   : 2014-08-12, 15:32, # CodeGen: 0
>>>>>>> b7cccee2cb6e8b4139e62868eb20e77308d79017
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
<<<<<<< HEAD
=======
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
>>>>>>> b7cccee2cb6e8b4139e62868eb20e77308d79017

#ifdef __cplusplus
extern "C" {
#endif 

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
void Cpu_OnNMIINT(void);


<<<<<<< HEAD
=======
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
void AS1_OnRxChar(void);

>>>>>>> b7cccee2cb6e8b4139e62868eb20e77308d79017
/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
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
