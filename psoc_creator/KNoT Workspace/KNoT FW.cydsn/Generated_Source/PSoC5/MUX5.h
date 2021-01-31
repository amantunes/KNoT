/*******************************************************************************
* File Name: MUX5.h  
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

#if !defined(CY_PINS_MUX5_H) /* Pins MUX5_H */
#define CY_PINS_MUX5_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MUX5_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MUX5__PORT == 15 && ((MUX5__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MUX5_Write(uint8 value);
void    MUX5_SetDriveMode(uint8 mode);
uint8   MUX5_ReadDataReg(void);
uint8   MUX5_Read(void);
void    MUX5_SetInterruptMode(uint16 position, uint16 mode);
uint8   MUX5_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MUX5_SetDriveMode() function.
     *  @{
     */
        #define MUX5_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MUX5_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MUX5_DM_RES_UP          PIN_DM_RES_UP
        #define MUX5_DM_RES_DWN         PIN_DM_RES_DWN
        #define MUX5_DM_OD_LO           PIN_DM_OD_LO
        #define MUX5_DM_OD_HI           PIN_DM_OD_HI
        #define MUX5_DM_STRONG          PIN_DM_STRONG
        #define MUX5_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MUX5_MASK               MUX5__MASK
#define MUX5_SHIFT              MUX5__SHIFT
#define MUX5_WIDTH              1u

/* Interrupt constants */
#if defined(MUX5__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MUX5_SetInterruptMode() function.
     *  @{
     */
        #define MUX5_INTR_NONE      (uint16)(0x0000u)
        #define MUX5_INTR_RISING    (uint16)(0x0001u)
        #define MUX5_INTR_FALLING   (uint16)(0x0002u)
        #define MUX5_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MUX5_INTR_MASK      (0x01u) 
#endif /* (MUX5__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MUX5_PS                     (* (reg8 *) MUX5__PS)
/* Data Register */
#define MUX5_DR                     (* (reg8 *) MUX5__DR)
/* Port Number */
#define MUX5_PRT_NUM                (* (reg8 *) MUX5__PRT) 
/* Connect to Analog Globals */                                                  
#define MUX5_AG                     (* (reg8 *) MUX5__AG)                       
/* Analog MUX bux enable */
#define MUX5_AMUX                   (* (reg8 *) MUX5__AMUX) 
/* Bidirectional Enable */                                                        
#define MUX5_BIE                    (* (reg8 *) MUX5__BIE)
/* Bit-mask for Aliased Register Access */
#define MUX5_BIT_MASK               (* (reg8 *) MUX5__BIT_MASK)
/* Bypass Enable */
#define MUX5_BYP                    (* (reg8 *) MUX5__BYP)
/* Port wide control signals */                                                   
#define MUX5_CTL                    (* (reg8 *) MUX5__CTL)
/* Drive Modes */
#define MUX5_DM0                    (* (reg8 *) MUX5__DM0) 
#define MUX5_DM1                    (* (reg8 *) MUX5__DM1)
#define MUX5_DM2                    (* (reg8 *) MUX5__DM2) 
/* Input Buffer Disable Override */
#define MUX5_INP_DIS                (* (reg8 *) MUX5__INP_DIS)
/* LCD Common or Segment Drive */
#define MUX5_LCD_COM_SEG            (* (reg8 *) MUX5__LCD_COM_SEG)
/* Enable Segment LCD */
#define MUX5_LCD_EN                 (* (reg8 *) MUX5__LCD_EN)
/* Slew Rate Control */
#define MUX5_SLW                    (* (reg8 *) MUX5__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MUX5_PRTDSI__CAPS_SEL       (* (reg8 *) MUX5__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MUX5_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MUX5__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MUX5_PRTDSI__OE_SEL0        (* (reg8 *) MUX5__PRTDSI__OE_SEL0) 
#define MUX5_PRTDSI__OE_SEL1        (* (reg8 *) MUX5__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MUX5_PRTDSI__OUT_SEL0       (* (reg8 *) MUX5__PRTDSI__OUT_SEL0) 
#define MUX5_PRTDSI__OUT_SEL1       (* (reg8 *) MUX5__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MUX5_PRTDSI__SYNC_OUT       (* (reg8 *) MUX5__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MUX5__SIO_CFG)
    #define MUX5_SIO_HYST_EN        (* (reg8 *) MUX5__SIO_HYST_EN)
    #define MUX5_SIO_REG_HIFREQ     (* (reg8 *) MUX5__SIO_REG_HIFREQ)
    #define MUX5_SIO_CFG            (* (reg8 *) MUX5__SIO_CFG)
    #define MUX5_SIO_DIFF           (* (reg8 *) MUX5__SIO_DIFF)
#endif /* (MUX5__SIO_CFG) */

/* Interrupt Registers */
#if defined(MUX5__INTSTAT)
    #define MUX5_INTSTAT            (* (reg8 *) MUX5__INTSTAT)
    #define MUX5_SNAP               (* (reg8 *) MUX5__SNAP)
    
	#define MUX5_0_INTTYPE_REG 		(* (reg8 *) MUX5__0__INTTYPE)
#endif /* (MUX5__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MUX5_H */


/* [] END OF FILE */
