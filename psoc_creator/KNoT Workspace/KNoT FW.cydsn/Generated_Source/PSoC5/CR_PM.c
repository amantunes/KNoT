/*******************************************************************************
* File Name: CR_PM.c
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

#include "CR.h"

/* Check for removal by optimization */
#if !defined(CR_Sync_ctrl_reg__REMOVED)

static CR_BACKUP_STRUCT  CR_backup = {0u};

    
/*******************************************************************************
* Function Name: CR_SaveConfig
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
void CR_SaveConfig(void) 
{
    CR_backup.controlState = CR_Control;
}


/*******************************************************************************
* Function Name: CR_RestoreConfig
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
void CR_RestoreConfig(void) 
{
     CR_Control = CR_backup.controlState;
}


/*******************************************************************************
* Function Name: CR_Sleep
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
void CR_Sleep(void) 
{
    CR_SaveConfig();
}


/*******************************************************************************
* Function Name: CR_Wakeup
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
void CR_Wakeup(void)  
{
    CR_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
