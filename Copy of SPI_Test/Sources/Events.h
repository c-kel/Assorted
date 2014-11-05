/* ###################################################################
**     Filename    : Events.h
**     Project     : SPI_Test
**     Processor   : MK20DX128VLH5
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-09-22, 17:56, # CodeGen: 0
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

#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Event       :  IRQ_OnInterrupt (module Events)
**
**     Component   :  IRQ [ExtInt_LDD]
*/
/*!
**     @brief
**         This event is called when an active signal edge/level has
**         occurred.
**     @param
**         UserDataPtr     - Pointer to RTOS device
**                           data structure pointer.
*/
/* ===================================================================*/
void IRQ_OnInterrupt(void);

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
