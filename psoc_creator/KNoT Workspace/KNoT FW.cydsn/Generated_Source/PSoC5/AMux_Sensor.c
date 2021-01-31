/*******************************************************************************
* File Name: AMux_Sensor.c
* Version 1.80
*
*  Description:
*    This file contains all functions required for the analog multiplexer
*    AMux User Module.
*
*   Note:
*
*******************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "AMux_Sensor.h"

static uint8 AMux_Sensor_lastChannel = AMux_Sensor_NULL_CHANNEL;


/*******************************************************************************
* Function Name: AMux_Sensor_Start
********************************************************************************
* Summary:
*  Disconnect all channels.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void AMux_Sensor_Start(void) 
{
    uint8 chan;

    for(chan = 0u; chan < AMux_Sensor_CHANNELS ; chan++)
    {
#if (AMux_Sensor_MUXTYPE == AMux_Sensor_MUX_SINGLE)
        AMux_Sensor_Unset(chan);
#else
        AMux_Sensor_CYAMUXSIDE_A_Unset(chan);
        AMux_Sensor_CYAMUXSIDE_B_Unset(chan);
#endif
    }

    AMux_Sensor_lastChannel = AMux_Sensor_NULL_CHANNEL;
}


#if (!AMux_Sensor_ATMOSTONE)
/*******************************************************************************
* Function Name: AMux_Sensor_Select
********************************************************************************
* Summary:
*  This functions first disconnects all channels then connects the given
*  channel.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void AMux_Sensor_Select(uint8 channel) 
{
    AMux_Sensor_DisconnectAll();        /* Disconnect all previous connections */
    AMux_Sensor_Connect(channel);       /* Make the given selection */
    AMux_Sensor_lastChannel = channel;  /* Update last channel */
}
#endif


/*******************************************************************************
* Function Name: AMux_Sensor_FastSelect
********************************************************************************
* Summary:
*  This function first disconnects the last connection made with FastSelect or
*  Select, then connects the given channel. The FastSelect function is similar
*  to the Select function, except it is faster since it only disconnects the
*  last channel selected rather than all channels.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void AMux_Sensor_FastSelect(uint8 channel) 
{
    /* Disconnect the last valid channel */
    if( AMux_Sensor_lastChannel != AMux_Sensor_NULL_CHANNEL)
    {
        AMux_Sensor_Disconnect(AMux_Sensor_lastChannel);
    }

    /* Make the new channel connection */
#if (AMux_Sensor_MUXTYPE == AMux_Sensor_MUX_SINGLE)
    AMux_Sensor_Set(channel);
#else
    AMux_Sensor_CYAMUXSIDE_A_Set(channel);
    AMux_Sensor_CYAMUXSIDE_B_Set(channel);
#endif


    AMux_Sensor_lastChannel = channel;   /* Update last channel */
}


#if (AMux_Sensor_MUXTYPE == AMux_Sensor_MUX_DIFF)
#if (!AMux_Sensor_ATMOSTONE)
/*******************************************************************************
* Function Name: AMux_Sensor_Connect
********************************************************************************
* Summary:
*  This function connects the given channel without affecting other connections.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void AMux_Sensor_Connect(uint8 channel) 
{
    AMux_Sensor_CYAMUXSIDE_A_Set(channel);
    AMux_Sensor_CYAMUXSIDE_B_Set(channel);
}
#endif

/*******************************************************************************
* Function Name: AMux_Sensor_Disconnect
********************************************************************************
* Summary:
*  This function disconnects the given channel from the common or output
*  terminal without affecting other connections.
*
* Parameters:
*  channel:  The channel to disconnect from the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void AMux_Sensor_Disconnect(uint8 channel) 
{
    AMux_Sensor_CYAMUXSIDE_A_Unset(channel);
    AMux_Sensor_CYAMUXSIDE_B_Unset(channel);
}
#endif

#if (AMux_Sensor_ATMOSTONE)
/*******************************************************************************
* Function Name: AMux_Sensor_DisconnectAll
********************************************************************************
* Summary:
*  This function disconnects all channels.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void AMux_Sensor_DisconnectAll(void) 
{
    if(AMux_Sensor_lastChannel != AMux_Sensor_NULL_CHANNEL) 
    {
        AMux_Sensor_Disconnect(AMux_Sensor_lastChannel);
        AMux_Sensor_lastChannel = AMux_Sensor_NULL_CHANNEL;
    }
}
#endif

/* [] END OF FILE */
