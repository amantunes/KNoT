/*******************************************************************************
* File Name: AMux_Sensor.h
* Version 1.80
*
*  Description:
*    This file contains the constants and function prototypes for the Analog
*    Multiplexer User Module AMux.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_AMUX_AMux_Sensor_H)
#define CY_AMUX_AMux_Sensor_H

#include "cyfitter.h"
#include "cyfitter_cfg.h"

#if ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) || \
         (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC4) || \
         (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5))    
    #include "cytypes.h"
#else
    #include "syslib/cy_syslib.h"
#endif /* ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) */


/***************************************
*        Function Prototypes
***************************************/

void AMux_Sensor_Start(void) ;
#define AMux_Sensor_Init() AMux_Sensor_Start()
void AMux_Sensor_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void AMux_Sensor_Stop(void); */
/* void AMux_Sensor_Select(uint8 channel); */
/* void AMux_Sensor_Connect(uint8 channel); */
/* void AMux_Sensor_Disconnect(uint8 channel); */
/* void AMux_Sensor_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define AMux_Sensor_CHANNELS  2u
#define AMux_Sensor_MUXTYPE   1
#define AMux_Sensor_ATMOSTONE 1

/***************************************
*             API Constants
***************************************/

#define AMux_Sensor_NULL_CHANNEL 0xFFu
#define AMux_Sensor_MUX_SINGLE   1
#define AMux_Sensor_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if AMux_Sensor_MUXTYPE == AMux_Sensor_MUX_SINGLE
# if !AMux_Sensor_ATMOSTONE
#  define AMux_Sensor_Connect(channel) AMux_Sensor_Set(channel)
# endif
# define AMux_Sensor_Disconnect(channel) AMux_Sensor_Unset(channel)
#else
# if !AMux_Sensor_ATMOSTONE
void AMux_Sensor_Connect(uint8 channel) ;
# endif
void AMux_Sensor_Disconnect(uint8 channel) ;
#endif

#if AMux_Sensor_ATMOSTONE
# define AMux_Sensor_Stop() AMux_Sensor_DisconnectAll()
# define AMux_Sensor_Select(channel) AMux_Sensor_FastSelect(channel)
void AMux_Sensor_DisconnectAll(void) ;
#else
# define AMux_Sensor_Stop() AMux_Sensor_Start()
void AMux_Sensor_Select(uint8 channel) ;
# define AMux_Sensor_DisconnectAll() AMux_Sensor_Start()
#endif

#endif /* CY_AMUX_AMux_Sensor_H */


/* [] END OF FILE */
