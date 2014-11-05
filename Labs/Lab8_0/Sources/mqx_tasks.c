/* ###################################################################
**     Filename    : mqx_tasks.c
**     Project     : Lab8v1
**     Processor   : MK20DX128VLH5
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-09-21, 20:40, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Task1_task - void Task1_task(uint32_t task_init_data);
**
** ###################################################################*/
/*!
** @file mqx_tasks.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup mqx_tasks_module mqx_tasks module documentation
**  @{
*/         
/* MODULE mqx_tasks */

#include "Cpu.h"
#include "Events.h"
#include "mqx_tasks.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */
volatile uint16 bw; //brightness variable
extern LWSEM_STRUCT adcsem;
extern LWSEM_STRUCT i2csem;
extern LWSEM_STRUCT uartsem;
extern word snt;
volatile int16 vec[3];
volatile int16 xw,yw,zw; //values written to in
						//accel task and read from in term task
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
void Task1_task(uint32_t task_init_data)
{
	Light_Sense_Calibrate(TRUE);
	for(;;){
		
		Light_Sense_Measure(TRUE); 
		_lwsem_wait(&adcsem);
		Light_Sense_GetValue16(&bw); 
		_lwsem_post(&adcsem);
		_time_delay_ticks(2);
	}
}
/*
** ===================================================================
**     Event       :  Task2_task (module mqx_tasks)
**
**     Component   :  Task2 [MQXLite_task]
**     Description :
**         MQX task routine. The routine is generated into mqx_tasks.c
**         file.
**     Parameters  :
**         NAME            - DESCRIPTION
**         task_init_data  - 
**     Returns     : Nothing
** ===================================================================
*/
void Task2_task(uint32_t task_init_data)
{	
	for(;;){
		byte c;
		Accel_SendChar(0x00);
		Accel_RecvChar(&c);
		Accel_SendStop();		
		if (c&&0x01){
			Accel_SendChar(0x01);
			Accel_RecvBlock(vec, 6, &snt);
			Accel_SendStop();
			_lwsem_wait(&i2csem);
			xw=vec[0]; yw=vec[1]; zw=vec[2];
			_lwsem_post(&i2csem);
		}
		_time_delay_ticks(2);
	}
}

/*
** ===================================================================
**     Event       :  Task3_task (module mqx_tasks)
**
**     Component   :  Task3 [MQXLite_task]
**     Description :
**         MQX task routine. The routine is generated into mqx_tasks.c
**         file.
**     Parameters  :
**         NAME            - DESCRIPTION
**         task_init_data  - 
**     Returns     : Nothing
** ===================================================================
*/
void Task3_task(uint32_t task_init_data)
{
	for(;;){
	volatile int16 xr,yr,zr;
	uint16 br;
	static char * st1 ="\n\rAccelerometer x value: "  ;
	static char * st2 ="\n\rAccelerometer y value: " ;
	static char * st3 ="\n\rAccelerometer z value: " ;
	static char * st4 ="\n\rLight Sensor value: " ;
	_lwsem_wait(&i2csem);
	xr=xw, yr=yw, zr=zw, br=bw;
	_lwsem_post(&i2csem);
	Term1_Cls();
	Term1_MoveTo(1,1);
	Term1_SendStr(st1);
	Term1_SendNum(xr);
	Term1_SendStr(st2);
	Term1_SendNum(yr);
	Term1_SendStr(st3);
	Term1_SendNum(zr);
	Term1_SendStr(st4);
	Term1_SendNum(br);
	Term1_SendStr(" ");

	_time_delay_ticks(50);
	}
//Term1_SendStr("\r \n");
	
}

/* END mqx_tasks */

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
