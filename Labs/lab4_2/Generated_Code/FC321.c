/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : FC321.c
**     Project     : lab4wtss
**     Processor   : MK20DX128VLH5
**     Component   : FreeCntr32
**     Version     : Component 02.070, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-08-23, 03:19, # CodeGen: 0
**     Abstract    :
**         This device "FreeCntr32" implements 32-bit Free Running Counter
**     Settings    :
**         Timer name                  : FTM1_CNT (16-bit)
**         Compare name                : FTM1_MOD
**         Counter shared              : No
**
**         High speed mode
**             Prescaler               : divide-by-1
**             Clock                   : 50000000 Hz
**           Resolution of timer
**             microseconds            : ---
**             milliseconds            : 1
**             seconds                 : ---
**             seconds (real)          : 0.00131072
**             Hz                      : ---
**             kHz                     : ---
**             MHz                     : ---
**
**         Initialization:
**              Timer                  : Enabled
**
**         Timer registers
**              Counter                : FTM1_CNT  [0x40039004]
**              Mode                   : FTM1_SC   [0x40039000]
**              Run                    : FTM1_SC   [0x40039000]
**              Prescaler              : FTM1_SC   [0x40039000]
**
**         Compare registers
**              Compare                : FTM1_MOD  [0x40039008]
**     Contents    :
**         Reset     - byte FC321_Reset(void);
**         GetTimeUS - byte FC321_GetTimeUS(word *Time);
**         GetTimeMS - byte FC321_GetTimeMS(word *Time);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file FC321.c
** @version 01.00
** @brief
**         This device "FreeCntr32" implements 32-bit Free Running Counter
*/         
/*!
**  @addtogroup FC321_module FC321 module documentation
**  @{
*/         

/* MODULE FC321. */

#include "FC321.h"

/*
** ===================================================================
**     Method      :  FC321_Reset (component FreeCntr32)
*/
/*!
**     @brief
**         This method clears the counter.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
*/
/* ===================================================================*/
/*
byte FC321_Reset(void)
**  This method is implemented as a macro. See FC321.h file.  **
*/

/*
** ===================================================================
**     Method      :  FC321_GetTimeUS (component FreeCntr32)
**     Description :
**         Returns the time (as a 16-bit unsigned integer) in microseconds
**         since the last resetting after the last reset.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Time            - A pointer to the returned 16-bit value
**                           in microseconds
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_OVERFLOW - Software counter overflow
**                           ERR_MATH - Overflow during evaluation
** ===================================================================
*/
/*
byte FC321_GetTimeUS(word *Time)
**  This method is implemented as a macro. See FC321.h file.  **
*/

/*
** ===================================================================
**     Method      :  FC321_GetTimeMS (component FreeCntr32)
**     Description :
**         Returns the time (as a 16-bit unsigned integer) in milliseconds
**         since the last resetting after the last reset.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Time            - A pointer to the returned 16-bit value
**                           in milliseconds
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_OVERFLOW - Software counter overflow
**                           ERR_MATH - Overflow during evaluation
** ===================================================================
*/
/*
byte FC321_GetTimeMS(word *Time)
**  This method is implemented as a macro. See FC321.h file.  **
*/

/* END FC321. */

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
