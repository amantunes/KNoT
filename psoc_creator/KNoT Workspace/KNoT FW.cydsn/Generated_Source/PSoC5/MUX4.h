/*******************************************************************************
* File Name: MUX4.h  
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

#if !defined(CY_PINS_MUX4_H) /* Pins MUX4_H */
#define CY_PINS_MUX4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MUX4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MUX4__PORT == 15 && ((MUX4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MUX4_Write(uint8 value);
void    MUX4_SetDriveMode(uint8 mode);
uint8   MUX4_ReadDataReg(void);
uint8   MUX4_Read(void);
void    MUX4_SetInterruptMode(uint16 position, uint16 mode);
uint8   MUX4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MUX4_SetDriveMode() function.
     *  @{
     */
        #define MUX4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MUX4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MUX4_DM_RES_UP          PIN_DM_RES_UP
        #define MUX4_DM_RES_DWN         PIN_DM_RES_DWN
        #define MUX4_DM_OD_LO           PIN_DM_OD_LO
        #define MUX4_DM_OD_HI           PIN_DM_OD_HI
        #define MUX4_DM_STRONG          PIN_DM_STRONG
        #define MUX4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MUX4_MASK               MUX4__MASK
#define MUX4_SHIFT              MUX4__SHIFT
#define MUX4_WIDTH              1u

/* Interrupt constants */
#if defined(MUX4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MUX4_SetInterruptMode() function.
     *  @{
     */
        #define MUX4_INTR_NONE      (uint16)(0x0000u)
        #define MUX4_INTR_RISING    (uint16)(0x0001u)
        #define MUX4_INTR_FALLING   (uint16)(0x0002u)
        #define MUX4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MUX4_INTR_MASK      (0x01u) 
#endif /* (MUX4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MUX4_PS                     (* (reg8 *) MUX4__PS)
/* Data Register */
#define MUX4_DR                     (* (reg8 *) MUX4__DR)
/* Port Number */
#define MUX4_PRT_NUM                (* (reg8 *) MUX4__PRT) 
/* Connect to Analog Globals */                                                  
#define MUX4_AG                     (* (reg8 *) MUX4__AG)                       
/* Analog MUX bux enable */
#define MUX4_AMUX                   (* (reg8 *) MUX4__AMUX) 
/* Bidirectional Enable */                                                        
#define MUX4_BIE                    (* (reg8 *) MUX4__BIE)
/* Bit-mask for Aliased Register Access */
#define MUX4_BIT_MASK               (* (reg8 *) MUX4__BIT_MASK)
/* Bypass Enable */
#define MUX4_BYP                    (* (reg8 *) MUX4__BYP)
/* Port wide control signals */                                                   
#define MUX4_CTL                    (* (reg8 *) MUX4__CTL)
/* Drive Modes */
#define MUX4_DM0                    (* (reg8 *) MUX4__DM0) 
#define MUX4_DM1                    (* (reg8 *) MUX4__DM1)
#define MUX4_DM2                    (* (reg8 *) MUX4__DM2) 
/* Input Buffer Disable Override */
#define MUX4_INP_DIS                (* (reg8 *) MUX4__INP_DIS)
/* LCD Common or Segment Drive */
#define MUX4_LCD_COM_SEG            (* (reg8 *) MUX4__LCD_COM_SEG)
/* Enable Segment LCD */
#define MUX4_LCD_EN                 (* (reg8 *) MUX4__LCD_EN)
/* Slew Rate Control */
#define MUX4_SLW                    (* (reg8 *) MUX4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MUX4_PRTDSI__CAPS_SEL       (* (reg8 *) MUX4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MUX4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MUX4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MUX4_PRTDSI__OE_SEL0        (* (reg8 *) MUX4__PRTDSI__OE_SEL0) 
#define MUX4_PRTDSI__OE_SEL1        (* (reg8 *) MUX4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MUX4_PRTDSI__OUT_SEL0       (* (reg8 *) MUX4__PRTDSI__OUT_SEL0) 
#define MUX4_PRTDSI__OUT_SEL1       (* (reg8 *) MUX4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MUX4_PRTDSI__SYNC_OUT       (* (reg8 *) MUX4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MUX4__SIO_CFG)
    #define MUX4_SIO_HYST_EN        (* (reg8 *) MUX4__SIO_HYST_EN)
    #define MUX4_SIO_REG_HIFREQ     (* (reg8 *) MUX4__SIO_REG_HIFREQ)
    #define MUX4_SIO_CFG            (* (reg8 *) MUX4__SIO_CFG)
    #define MUX4_SIO_DIFF           (* (reg8 *) MUX4__SIO_DIFF)
#endif /* (MUX4__SIO_CFG) */

/* Interrupt Registers */
#if defined(MUX4__INTSTAT)
    #define MUX4_INTSTAT            (* (reg8 *) MUX4__INTSTAT)
    #define MUX4_SNAP               (* (reg8 *) MUX4__SNAP)
    
	#define MUX4_0_INTTYPE_REG 		(* (reg8 *) MUX4__0__INTTYPE)
#endif /* (MUX4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MUX4_H */


/* [] END OF FILE */
