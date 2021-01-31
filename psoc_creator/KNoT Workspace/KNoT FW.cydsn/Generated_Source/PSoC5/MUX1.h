/*******************************************************************************
* File Name: MUX1.h  
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

#if !defined(CY_PINS_MUX1_H) /* Pins MUX1_H */
#define CY_PINS_MUX1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MUX1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MUX1__PORT == 15 && ((MUX1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MUX1_Write(uint8 value);
void    MUX1_SetDriveMode(uint8 mode);
uint8   MUX1_ReadDataReg(void);
uint8   MUX1_Read(void);
void    MUX1_SetInterruptMode(uint16 position, uint16 mode);
uint8   MUX1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MUX1_SetDriveMode() function.
     *  @{
     */
        #define MUX1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MUX1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MUX1_DM_RES_UP          PIN_DM_RES_UP
        #define MUX1_DM_RES_DWN         PIN_DM_RES_DWN
        #define MUX1_DM_OD_LO           PIN_DM_OD_LO
        #define MUX1_DM_OD_HI           PIN_DM_OD_HI
        #define MUX1_DM_STRONG          PIN_DM_STRONG
        #define MUX1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MUX1_MASK               MUX1__MASK
#define MUX1_SHIFT              MUX1__SHIFT
#define MUX1_WIDTH              1u

/* Interrupt constants */
#if defined(MUX1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MUX1_SetInterruptMode() function.
     *  @{
     */
        #define MUX1_INTR_NONE      (uint16)(0x0000u)
        #define MUX1_INTR_RISING    (uint16)(0x0001u)
        #define MUX1_INTR_FALLING   (uint16)(0x0002u)
        #define MUX1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MUX1_INTR_MASK      (0x01u) 
#endif /* (MUX1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MUX1_PS                     (* (reg8 *) MUX1__PS)
/* Data Register */
#define MUX1_DR                     (* (reg8 *) MUX1__DR)
/* Port Number */
#define MUX1_PRT_NUM                (* (reg8 *) MUX1__PRT) 
/* Connect to Analog Globals */                                                  
#define MUX1_AG                     (* (reg8 *) MUX1__AG)                       
/* Analog MUX bux enable */
#define MUX1_AMUX                   (* (reg8 *) MUX1__AMUX) 
/* Bidirectional Enable */                                                        
#define MUX1_BIE                    (* (reg8 *) MUX1__BIE)
/* Bit-mask for Aliased Register Access */
#define MUX1_BIT_MASK               (* (reg8 *) MUX1__BIT_MASK)
/* Bypass Enable */
#define MUX1_BYP                    (* (reg8 *) MUX1__BYP)
/* Port wide control signals */                                                   
#define MUX1_CTL                    (* (reg8 *) MUX1__CTL)
/* Drive Modes */
#define MUX1_DM0                    (* (reg8 *) MUX1__DM0) 
#define MUX1_DM1                    (* (reg8 *) MUX1__DM1)
#define MUX1_DM2                    (* (reg8 *) MUX1__DM2) 
/* Input Buffer Disable Override */
#define MUX1_INP_DIS                (* (reg8 *) MUX1__INP_DIS)
/* LCD Common or Segment Drive */
#define MUX1_LCD_COM_SEG            (* (reg8 *) MUX1__LCD_COM_SEG)
/* Enable Segment LCD */
#define MUX1_LCD_EN                 (* (reg8 *) MUX1__LCD_EN)
/* Slew Rate Control */
#define MUX1_SLW                    (* (reg8 *) MUX1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MUX1_PRTDSI__CAPS_SEL       (* (reg8 *) MUX1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MUX1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MUX1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MUX1_PRTDSI__OE_SEL0        (* (reg8 *) MUX1__PRTDSI__OE_SEL0) 
#define MUX1_PRTDSI__OE_SEL1        (* (reg8 *) MUX1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MUX1_PRTDSI__OUT_SEL0       (* (reg8 *) MUX1__PRTDSI__OUT_SEL0) 
#define MUX1_PRTDSI__OUT_SEL1       (* (reg8 *) MUX1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MUX1_PRTDSI__SYNC_OUT       (* (reg8 *) MUX1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MUX1__SIO_CFG)
    #define MUX1_SIO_HYST_EN        (* (reg8 *) MUX1__SIO_HYST_EN)
    #define MUX1_SIO_REG_HIFREQ     (* (reg8 *) MUX1__SIO_REG_HIFREQ)
    #define MUX1_SIO_CFG            (* (reg8 *) MUX1__SIO_CFG)
    #define MUX1_SIO_DIFF           (* (reg8 *) MUX1__SIO_DIFF)
#endif /* (MUX1__SIO_CFG) */

/* Interrupt Registers */
#if defined(MUX1__INTSTAT)
    #define MUX1_INTSTAT            (* (reg8 *) MUX1__INTSTAT)
    #define MUX1_SNAP               (* (reg8 *) MUX1__SNAP)
    
	#define MUX1_0_INTTYPE_REG 		(* (reg8 *) MUX1__0__INTTYPE)
#endif /* (MUX1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MUX1_H */


/* [] END OF FILE */
