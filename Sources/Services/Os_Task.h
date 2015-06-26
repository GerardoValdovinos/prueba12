/****************************************************************************************************/
/**

\file       Os_Task.h
\brief      Operative System Module Tasks
\author     Gerardo Valdovinos
\version    1.0
\date       03/11/2014
*/
/****************************************************************************************************/

/****************************************************************************************************/

#ifndef __OS_TASK_H
#define __OS_TASK_H


/*****************************************************************************************************
* Include files
*****************************************************************************************************/
#include "Os_Types.h"
#include "Os_TaskM.h"

/* Task functions includes */
#include "Control.h"
#include "Sci.h"
/*****************************************************************************************************
* Definition of module wide VARIABLES
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs
*****************************************************************************************************/
typedef struct
{
    u8  u8LedMask;
    u8  u8Status;
    u8  u8Freq;
    u8  u8FreqCnt;
    u8  u8Times;
    u8  u8Cnt;        
}tstLed;
/*-- Macros ------------------------------------------------------------------*/


/*-- Function Prototypes -----------------------------------------------------*/
DeclareTask(Task_1ms);
DeclareTask(Task_2ms);
DeclareTask(Task_4ms);
DeclareTask(Task_8ms);
DeclareTask(Task_16ms);
DeclareTask(Task_32ms);
DeclareTask(Task_64ms);


void vfnLedManager(tstLed *pstLed);

#endif /* __OS_TASK_H */

/*******************************************************************************/