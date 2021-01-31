/*******************************************************************************
* File Name: Reset_CR_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Reset_CR.h"

/* Check for removal by optimization */
#if !defined(Reset_CR_Sync_ctrl_reg__REMOVED)

static Reset_CR_BACKUP_STRUCT  Reset_CR_backup = {0u};

    
/*******************************************************************************
* Function Name: Reset_CR_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Reset_CR_SaveConfig(void) 
{
    Reset_CR_backup.controlState = Reset_CR_Control;
}


/*******************************************************************************
* Function Name: Reset_CR_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void Reset_CR_RestoreConfig(void) 
{
     Reset_CR_Control = Reset_CR_backup.controlState;
}


/*******************************************************************************
* Function Name: Reset_CR_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Reset_CR_Sleep(void) 
{
    Reset_CR_SaveConfig();
}


/*******************************************************************************
* Function Name: Reset_CR_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Reset_CR_Wakeup(void)  
{
    Reset_CR_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
