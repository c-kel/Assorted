/* ###################################################################
 **     Filename    : mqx_tasks.c
 **     Project     : Lab9
 **     Processor   : MK20DX128VLH5
 **     Component   : Events
 **     Version     : Driver 01.00
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2014-09-23, 23:30, # CodeGen: 2
 **     Abstract    :
 **         This is user's event module.
 **         Put your event handler code here.
 **     Settings    :
 **     Contents    :
 **         Task1_task - void Task1_task(uint32_t task_init_data);
 **         Task2_task - void Task2_task(uint32_t task_init_data);
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
extern LWSEM_STRUCT i2csem;
extern LWSEM_STRUCT uartsem;
extern word snt;
volatile float result[3]; 
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
	static float alpha=0.01;
	int16 vec[3];
	int16 current[3]; //current 
	int16 previous[3]; //previous
	int counter;	
	int i;
	for(;;){
		byte c;
		Accel_SendChar(0x00);
		Accel_RecvChar(&c);
		Accel_SendStop();		
		if (c&&0x01){
			for(counter=0;counter<31;counter++){
				Accel_SendChar(0x01);
				Accel_RecvBlock(&vec, 6, &snt);
				Accel_SendStop();
//				current[0]=(vec[0]&0x1f - vec[0]&0x20) *256 + vec[1];
//				current[1]=(vec[2]&0x1f - vec[2]&0x20) *256 + vec[3];
//				current[2]=(vec[4]&0x1f - vec[4]&0x20) *256 + vec[5];
				//Term1_SendNum();
				for(i=0; i<3; i++){
					current[i]=current[i]/2048;					
					previous[i]= current[i];
				}
				_lwsem_wait(&i2csem);
				for(i=0; i<3; i++){
					result[i]= alpha * (float)current[i] + (1-alpha) * (float)previous[i];
				}
				_lwsem_post(&i2csem);
			}

		}
		_time_delay_ticks(5);
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
	int i;
	int counter;

	const char comma =  ',';
	for(;;){
		counter++;
		float p_result[3];

		_lwsem_wait(&uartsem);
		for(i=0; i<3; i++){
			p_result[i]=result[i];	
		}
		_lwsem_post(&uartsem);
		for(i=0; i<3; i++){
			Term1_SendFloatNum(p_result[i]);
			Term1_SendChar(comma);
		}
		Term1_CRLF();
		//_time_delay_ticks(50);
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
