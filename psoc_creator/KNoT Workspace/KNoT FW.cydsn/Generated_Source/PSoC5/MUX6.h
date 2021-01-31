/*******************************************************************************
* File Name: MUX6.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_MUX6_H) /* Pins MUX6_H */
#define CY_PINS_MUX6_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MUX6_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MUX6__PORT == 15 && ((MUX6__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MUX6_Write(uint8 value);
void    MUX6_SetDriveMode(uint8 mode);
uint8   MUX6_ReadDataReg(void);
uint8   MUX6_Read(void);
void    MUX6_SetInterruptMode(uint16 position, uint16 mode);
uint8   MUX6_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MUX6_SetDriveMode() function.
     *  @{
     */
        #define MUX6_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MUX6_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MUX6_DM_RES_UP          PIN_DM_RES_UP
        #define MUX6_DM_RES_DWN         PIN_DM_RES_DWN
        #define MUX6_DM_OD_LO           PIN_DM_OD_LO
        #define MUX6_DM_OD_HI           PIN_DM_OD_HI
        #define MUX6_DM_STRONG          PIN_DM_STRONG
        #define MUX6_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MUX6_MASK               MUX6__MASK
#define MUX6_SHIFT              MUX6__SHIFT
#define MUX6_WIDTH              1u

/* Interrupt constants */
#if defined(MUX6__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MUX6_SetInterruptMode() function.
     *  @{
     */
        #define MUX6_INTR_NONE      (uint16)(0x0000u)
        #define MUX6_INTR_RISING    (uint16)(0x0001u)
        #define MUX6_INTR_FALLING   (uint16)(0x0002u)
        #define MUX6_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MUX6_INTR_MASK      (0x01u) 
#endif /* (MUX6__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MUX6_PS                     (* (reg8 *) MUX6__PS)
/* Data Register */
#define MUX6_DR                     (* (reg8 *) MUX6__DR)
/* Port Number */
#define MUX6_PRT_NUM                (* (reg8 *) MUX6__PRT) 
/* Connect to Analog Globals */                                                  
#define MUX6_AG                     (* (reg8 *) MUX6__AG)                       
/* Analog MUX bux enable */
#define MUX6_AMUX                   (* (reg8 *) MUX6__AMUX) 
/* Bidirectional Enable */                                                        
#define MUX6_BIE                    (* (reg8 *) MUX6__BIE)
/* Bit-mask for Aliased Register Access */
#define MUX6_BIT_MASK               (* (reg8 *) MUX6__BIT_MASK)
/* Bypass Enable */
#define MUX6_BYP                    (* (reg8 *) MUX6__BYP)
/* Port wide control signals */                                                   
#define MUX6_CTL                    (* (reg8 *) MUX6__CTL)
/* Drive Modes */
#define MUX6_DM0                    (* (reg8 *) MUX6__DM0) 
#define MUX6_DM1                    (* (reg8 *) MUX6__DM1)
#define MUX6_DM2                    (* (reg8 *) MUX6__DM2) 
/* Input Buffer Disable Override */
#define MUX6_INP_DIS                (* (reg8 *) MUX6__INP_DIS)
/* LCD Common or Segment Drive */
#define MUX6_LCD_COM_SEG            (* (reg8 *) MUX6__LCD_COM_SEG)
/* Enable Segment LCD */
#define MUX6_LCD_EN                 (* (reg8 *) MUX6__LCD_EN)
/* Slew Rate Control */
#define MUX6_SLW                    (* (reg8 *) MUX6__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MUX6_PRTDSI__CAPS_SEL       (* (reg8 *) MUX6__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MUX6_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MUX6__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MUX6_PRTDSI__OE_SEL0        (* (reg8 *) MUX6__PRTDSI__OE_SEL0) 
#define MUX6_PRTDSI__OE_SEL1        (* (reg8 *) MUX6__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MUX6_PRTDSI__OUT_SEL0       (* (reg8 *) MUX6__PRTDSI__OUT_SEL0) 
#define MUX6_PRTDSI__OUT_SEL1       (* (reg8 *) MUX6__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MUX6_PRTDSI__SYNC_OUT       (* (reg8 *) MUX6__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MUX6__SIO_CFG)
    #define MUX6_SIO_HYST_EN        (* (reg8 *) MUX6__SIO_HYST_EN)
    #define MUX6_SIO_REG_HIFREQ     (* (reg8 *) MUX6__SIO_REG_HIFREQ)
    #define MUX6_SIO_CFG            (* (reg8 *) MUX6__SIO_CFG)
    #define MUX6_SIO_DIFF           (* (reg8 *) MUX6__SIO_DIFF)
#endif /* (MUX6__SIO_CFG) */

/* Interrupt Registers */
#if defined(MUX6__INTSTAT)
    #define MUX6_INTSTAT            (* (reg8 *) MUX6__INTSTAT)
    #define MUX6_SNAP               (* (reg8 *) MUX6__SNAP)
    
	#define MUX6_0_INTTYPE_REG 		(* (reg8 *) MUX6__0__INTTYPE)
#endif /* (MUX6__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MUX6_H */


/* [] END OF FILE */
