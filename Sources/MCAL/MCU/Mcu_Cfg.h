 /****************************************************************************************************/
/**

\file       Mcu_Cfg.h
\brief      Microcontroller configuration
\author     Gerardo Valdovinos
\version    1.0
\date       08/10/2014
*/
/****************************************************************************************************/

/****************************************************************************************************/

#ifndef __MCU_CFG_H
#define __MCU_CFG_H


/*****************************************************************************************************
* Include files
*****************************************************************************************************/
#include <hidef.h>          /* common defines and macros */
#include "derivative.h"     /* derivative-specific definitions */
//#include "Typedefs.h"

/*****************************************************************************************************
* Definition of module wide VARIABLES
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs
*****************************************************************************************************/

/*-- Macros ------------------------------------------------------------------*/
/** Xtal frequency */ 
#define XTAL_FREQ_MHZ       4u 
/** Bus frequency */
#define BUS_FREQ_MHZ        48u

/*-- Function Prototypes -----------------------------------------------------*/


#endif /* __MCU_CFG_H */

/*******************************************************************************/