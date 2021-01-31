/*******************************************************************************
* File Name: MUX4.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_MUX4_ALIASES_H) /* Pins MUX4_ALIASES_H */
#define CY_PINS_MUX4_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define MUX4_0			(MUX4__0__PC)
#define MUX4_0_INTR	((uint16)((uint16)0x0001u << MUX4__0__SHIFT))

#define MUX4_INTR_ALL	 ((uint16)(MUX4_0_INTR))

#endif /* End Pins MUX4_ALIASES_H */


/* [] END OF FILE */
