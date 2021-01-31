/*******************************************************************************
* File Name: MUX2.h  
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

#if !defined(CY_PINS_MUX2_H) /* Pins MUX2_H */
#define CY_PINS_MUX2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MUX2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MUX2__PORT == 15 && ((MUX2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MUX2_Write(uint8 value);
void    MUX2_SetDriveMode(uint8 mode);
uint8   MUX2_ReadDataReg(void);
uint8   MUX2_Read(void);
void    MUX2_SetInterruptMode(uint16 position, uint16 mode);
uint8   MUX2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MUX2_SetDriveMode() function.
     *  @{
     */
        #define MUX2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MUX2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MUX2_DM_RES_UP          PIN_DM_RES_UP
        #define MUX2_DM_RES_DWN         PIN_DM_RES_DWN
        #define MUX2_DM_OD_LO           PIN_DM_OD_LO
        #define MUX2_DM_OD_HI           PIN_DM_OD_HI
        #define MUX2_DM_STRONG          PIN_DM_STRONG
        #define MUX2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MUX2_MASK               MUX2__MASK
#define MUX2_SHIFT              MUX2__SHIFT
#define MUX2_WIDTH              1u

/* Interrupt constants */
#if defined(MUX2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MUX2_SetInterruptMode() function.
     *  @{
     */
        #define MUX2_INTR_NONE      (uint16)(0x0000u)
        #define MUX2_INTR_RISING    (uint16)(0x0001u)
        #define MUX2_INTR_FALLING   (uint16)(0x0002u)
        #define MUX2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MUX2_INTR_MASK      (0x01u) 
#endif /* (MUX2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MUX2_PS                     (* (reg8 *) MUX2__PS)
/* Data Register */
#define MUX2_DR                     (* (reg8 *) MUX2__DR)
/* Port Number */
#define MUX2_PRT_NUM                (* (reg8 *) MUX2__PRT) 
/* Connect to Analog Globals */                                                  
#define MUX2_AG                     (* (reg8 *) MUX2__AG)                       
/* Analog MUX bux enable */
#define MUX2_AMUX                   (* (reg8 *) MUX2__AMUX) 
/* Bidirectional Enable */                                                        
#define MUX2_BIE                    (* (reg8 *) MUX2__BIE)
/* Bit-mask for Aliased Register Access */
#define MUX2_BIT_MASK               (* (reg8 *) MUX2__BIT_MASK)
/* Bypass Enable */
#define MUX2_BYP                    (* (reg8 *) MUX2__BYP)
/* Port wide control signals */                                                   
#define MUX2_CTL                    (* (reg8 *) MUX2__CTL)
/* Drive Modes */
#define MUX2_DM0                    (* (reg8 *) MUX2__DM0) 
#define MUX2_DM1                    (* (reg8 *) MUX2__DM1)
#define MUX2_DM2                    (* (reg8 *) MUX2__DM2) 
/* Input Buffer Disable Override */
#define MUX2_INP_DIS                (* (reg8 *) MUX2__INP_DIS)
/* LCD Common or Segment Drive */
#define MUX2_LCD_COM_SEG            (* (reg8 *) MUX2__LCD_COM_SEG)
/* Enable Segment LCD */
#define MUX2_LCD_EN                 (* (reg8 *) MUX2__LCD_EN)
/* Slew Rate Control */
#define MUX2_SLW                    (* (reg8 *) MUX2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MUX2_PRTDSI__CAPS_SEL       (* (reg8 *) MUX2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MUX2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MUX2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MUX2_PRTDSI__OE_SEL0        (* (reg8 *) MUX2__PRTDSI__OE_SEL0) 
#define MUX2_PRTDSI__OE_SEL1        (* (reg8 *) MUX2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MUX2_PRTDSI__OUT_SEL0       (* (reg8 *) MUX2__PRTDSI__OUT_SEL0) 
#define MUX2_PRTDSI__OUT_SEL1       (* (reg8 *) MUX2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MUX2_PRTDSI__SYNC_OUT       (* (reg8 *) MUX2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MUX2__SIO_CFG)
    #define MUX2_SIO_HYST_EN        (* (reg8 *) MUX2__SIO_HYST_EN)
    #define MUX2_SIO_REG_HIFREQ     (* (reg8 *) MUX2__SIO_REG_HIFREQ)
    #define MUX2_SIO_CFG            (* (reg8 *) MUX2__SIO_CFG)
    #define MUX2_SIO_DIFF           (* (reg8 *) MUX2__SIO_DIFF)
#endif /* (MUX2__SIO_CFG) */

/* Interrupt Registers */
#if defined(MUX2__INTSTAT)
    #define MUX2_INTSTAT            (* (reg8 *) MUX2__INTSTAT)
    #define MUX2_SNAP               (* (reg8 *) MUX2__SNAP)
    
	#define MUX2_0_INTTYPE_REG 		(* (reg8 *) MUX2__0__INTTYPE)
#endif /* (MUX2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MUX2_H */


/* [] END OF FILE */
