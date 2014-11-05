/* ###################################################################
**     Filename    : mqx_tasks.h
**     Project     : SPI_Test
**     Processor   : MK20DX128VLH5
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-09-29, 11:38, # CodeGen: 1
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Task1_task - void Task1_task(uint32_t task_init_data);
**
** ###################################################################*/
/*!
** @file mqx_tasks.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup mqx_tasks_module mqx_tasks module documentation
**  @{
*/         

#ifndef __mqx_tasks_H
#define __mqx_tasks_H
/* MODULE mqx_tasks */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
//#include "Right_Dir.h"
//#include "BitIoLdd1.h"
//#include "Left_Dir.h"
//#include "BitIoLdd2.h"
#include "TU1.h"
//#include "Left_Spd.h"
//#include "PwmLdd2.h"
//#include "MQX1.h"
//#include "SystemTimer1.h"
#include "IRQ.h"
#include "ExtIntLdd1.h"
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
//#include "FC321.h"
//#include "RealTimeLdd1.h"
#include "TU2.h"
#include "CSN.h"
#include "BitIoLdd7.h"

#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Event       :  Task1_task (module mqx_tasks)
**
**     Component   :  Task1 [MQXLite_task]
**     Description :
**         MQX task routine. The routine is generated into mqx_tasks.c
**         file.
**     Parameters  :
**         NAME            - DESCRIPTION
**         task_init_data  - 
**     Returns     : Nothing
** ===================================================================
*/
void Task1_task(uint32_t task_init_data);


/* END mqx_tasks */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __mqx_tasks_H*/
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
