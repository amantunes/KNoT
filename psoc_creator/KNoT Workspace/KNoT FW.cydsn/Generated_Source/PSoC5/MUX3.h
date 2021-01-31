/*******************************************************************************
* File Name: MUX3.h  
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

#if !defined(CY_PINS_MUX3_H) /* Pins MUX3_H */
#define CY_PINS_MUX3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MUX3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MUX3__PORT == 15 && ((MUX3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MUX3_Write(uint8 value);
void    MUX3_SetDriveMode(uint8 mode);
uint8   MUX3_ReadDataReg(void);
uint8   MUX3_Read(void);
void    MUX3_SetInterruptMode(uint16 position, uint16 mode);
uint8   MUX3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MUX3_SetDriveMode() function.
     *  @{
     */
        #define MUX3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MUX3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MUX3_DM_RES_UP          PIN_DM_RES_UP
        #define MUX3_DM_RES_DWN         PIN_DM_RES_DWN
        #define MUX3_DM_OD_LO           PIN_DM_OD_LO
        #define MUX3_DM_OD_HI           PIN_DM_OD_HI
        #define MUX3_DM_STRONG          PIN_DM_STRONG
        #define MUX3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MUX3_MASK               MUX3__MASK
#define MUX3_SHIFT              MUX3__SHIFT
#define MUX3_WIDTH              1u

/* Interrupt constants */
#if defined(MUX3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MUX3_SetInterruptMode() function.
     *  @{
     */
        #define MUX3_INTR_NONE      (uint16)(0x0000u)
        #define MUX3_INTR_RISING    (uint16)(0x0001u)
        #define MUX3_INTR_FALLING   (uint16)(0x0002u)
        #define MUX3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MUX3_INTR_MASK      (0x01u) 
#endif /* (MUX3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MUX3_PS                     (* (reg8 *) MUX3__PS)
/* Data Register */
#define MUX3_DR                     (* (reg8 *) MUX3__DR)
/* Port Number */
#define MUX3_PRT_NUM                (* (reg8 *) MUX3__PRT) 
/* Connect to Analog Globals */                                                  
#define MUX3_AG                     (* (reg8 *) MUX3__AG)                       
/* Analog MUX bux enable */
#define MUX3_AMUX                   (* (reg8 *) MUX3__AMUX) 
/* Bidirectional Enable */                                                        
#define MUX3_BIE                    (* (reg8 *) MUX3__BIE)
/* Bit-mask for Aliased Register Access */
#define MUX3_BIT_MASK               (* (reg8 *) MUX3__BIT_MASK)
/* Bypass Enable */
#define MUX3_BYP                    (* (reg8 *) MUX3__BYP)
/* Port wide control signals */                                                   
#define MUX3_CTL                    (* (reg8 *) MUX3__CTL)
/* Drive Modes */
#define MUX3_DM0                    (* (reg8 *) MUX3__DM0) 
#define MUX3_DM1                    (* (reg8 *) MUX3__DM1)
#define MUX3_DM2                    (* (reg8 *) MUX3__DM2) 
/* Input Buffer Disable Override */
#define MUX3_INP_DIS                (* (reg8 *) MUX3__INP_DIS)
/* LCD Common or Segment Drive */
#define MUX3_LCD_COM_SEG            (* (reg8 *) MUX3__LCD_COM_SEG)
/* Enable Segment LCD */
#define MUX3_LCD_EN                 (* (reg8 *) MUX3__LCD_EN)
/* Slew Rate Control */
#define MUX3_SLW                    (* (reg8 *) MUX3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MUX3_PRTDSI__CAPS_SEL       (* (reg8 *) MUX3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MUX3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MUX3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MUX3_PRTDSI__OE_SEL0        (* (reg8 *) MUX3__PRTDSI__OE_SEL0) 
#define MUX3_PRTDSI__OE_SEL1        (* (reg8 *) MUX3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MUX3_PRTDSI__OUT_SEL0       (* (reg8 *) MUX3__PRTDSI__OUT_SEL0) 
#define MUX3_PRTDSI__OUT_SEL1       (* (reg8 *) MUX3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MUX3_PRTDSI__SYNC_OUT       (* (reg8 *) MUX3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MUX3__SIO_CFG)
    #define MUX3_SIO_HYST_EN        (* (reg8 *) MUX3__SIO_HYST_EN)
    #define MUX3_SIO_REG_HIFREQ     (* (reg8 *) MUX3__SIO_REG_HIFREQ)
    #define MUX3_SIO_CFG            (* (reg8 *) MUX3__SIO_CFG)
    #define MUX3_SIO_DIFF           (* (reg8 *) MUX3__SIO_DIFF)
#endif /* (MUX3__SIO_CFG) */

/* Interrupt Registers */
#if defined(MUX3__INTSTAT)
    #define MUX3_INTSTAT            (* (reg8 *) MUX3__INTSTAT)
    #define MUX3_SNAP               (* (reg8 *) MUX3__SNAP)
    
	#define MUX3_0_INTTYPE_REG 		(* (reg8 *) MUX3__0__INTTYPE)
#endif /* (MUX3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MUX3_H */


/* [] END OF FILE */
