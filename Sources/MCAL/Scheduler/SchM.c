/*******************************************************************************/
/**
\file       SchM.c
\brief      Shceduler Module
\author     Gerardo Valdovinos
\version    1.0
\date       22/10/2014
*/
/****************************************************************************************************/

/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/** Own headers */
#include "SchM.h"
/** Used modules */

/*****************************************************************************************************
* Definition of module wide VARIABLEs 
*****************************************************************************************************/

const tstOs_TaskCfg* pstOs_TaskCfg;     // Pointer to task array configuration
const tstOs_Task* pstOs_Task;           // Pointer to task configuration

/* This array and TCB should be created dinamically in Memory */
tstTCB_Task astTCB_Task[4];             // Number of tasks defined in astOs_Task[]
tstTCB* stTCB;                          // Pointer to Task Control Block

/*****************************************************************************************************
* Declaration of module wide FUNCTIONs 
*****************************************************************************************************/
void SchM_Background(void);

/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs 
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide TYPEs 
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs 
*****************************************************************************************************/

/*****************************************************************************************************
* Code of module wide FUNCTIONS
****************************************************************************************************/

/****************************************************************************************************/
/**
* \brief    Scheduler initialization
* \author   Gerardo Valdovinos
* \param    void
* \return   void     
*/
void SchM_Init(const tstOs_TaskCfg* Os_TaskCfg)
{
    u8 u8Index;
    
    /* Copy pointer */
    pstOs_TaskCfg = Os_TaskCfg;
    
    pstOs_Task = (tstOs_Task*)pstOs_TaskCfg->pstOs_Task;
    
    /* Extract all tasks */
    for(u8Index = 0; u8Index < Os_TaskCfg->u8NumberOfTasks; u8Index++)
    {
        astTCB_Task[u8Index].eTCB_Priority = pstOs_Task[u8Index].ePriority;
        astTCB_Task[u8Index].eTCB_TaskID = pstOs_Task[u8Index].eTaskID;
        astTCB_Task[u8Index].u8TCB_State = 0;// SUSPENDED          
    }
}
/****************************************************************************************************/

/****************************************************************************************************/
/**
* \brief    Scheduler De-initialization
* \author   Gerardo Valdovinos
* \param    void
* \return   void     
*/
void SchM_DeInit(void)
{
    pstOs_TaskCfg = NULL;    
}
/****************************************************************************************************/

/****************************************************************************************************/
/**
* \brief    Scheduler start
* \author   Gerardo Valdovinos
* \param    void
* \return   void     
*/
void SchM_Start(void)
{
    /* Initialize OsTick timer */
    Gpt_EnableNotification(0);
    Gpt_StartTimer(0);
    
    /* Go to a background task */
    SchM_Background();
}
/****************************************************************************************************/

/****************************************************************************************************/
/**
* \brief    Scheduler OsTick callback 
* \author   Gerardo Valdovinos
* \param    void
* \return   void     
*/
void SchM_OsTick(void)
{
    u8 u8IndexTable;
    u8 u8Mask;
    u8 u8Offset;
    u8 u8MaskOffset;
    static u8 u8OsTick = 0;
    
    /********************
     * Increment OsTick *
     ********************/
    u8OsTick++;
    
    /* Search an available task to execute */
    for(u8IndexTable = 0; u8IndexTable < pstOs_TaskCfg->u8NumberOfTasks; u8IndexTable++)
    {
        /* Copy to local variables */
        u8Mask = pstOs_TaskCfg->pstOs_Task[u8IndexTable].u8Mask;
        u8Offset = pstOs_TaskCfg->pstOs_Task[u8IndexTable].u8Offset;
        
        /* Form the real mask (Mask + Offset) */
        u8MaskOffset = (u8Mask + u8Offset) & u8Mask;
        
        /* Verify match */
        if( (u8OsTick & u8Mask) == u8MaskOffset )
        {
        
            /****************
             * Execute task *
             ****************/
            pstOs_TaskCfg->pstOs_Task[u8IndexTable].vpCallback();
            
            break;
        }
    }
           
}
/****************************************************************************************************/

/****************************************************************************************************/
/**
* \brief    Scheduler Background task
* \author   Gerardo Valdovinos
* \param    void
* \return   void     
*/
void SchM_Background(void)
{
    /* Loop forever */
    for(;;) 
    {
        //PORTA_PA4 = 1;
        
        /* Call Dispatcher */
        SchM_Dispatcher();
         
        _FEED_COP();    /* feeds the dog */
    }                   /* loop forever */    
}
/****************************************************************************************************/

/****************************************************************************************************/
/**
* \brief    Scheduler dispatcher 
* \author   Gerardo Valdovinos
* \param    void
* \return   void     
*/
void SchM_Dispatcher(void)
{

}
