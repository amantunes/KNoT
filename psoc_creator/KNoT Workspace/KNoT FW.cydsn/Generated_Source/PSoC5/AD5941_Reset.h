/*******************************************************************************
* File Name: AD5941_Reset.h  
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

#if !defined(CY_PINS_AD5941_Reset_H) /* Pins AD5941_Reset_H */
#define CY_PINS_AD5941_Reset_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "AD5941_Reset_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 AD5941_Reset__PORT == 15 && ((AD5941_Reset__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    AD5941_Reset_Write(uint8 value);
void    AD5941_Reset_SetDriveMode(uint8 mode);
uint8   AD5941_Reset_ReadDataReg(void);
uint8   AD5941_Reset_Read(void);
void    AD5941_Reset_SetInterruptMode(uint16 position, uint16 mode);
uint8   AD5941_Reset_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the AD5941_Reset_SetDriveMode() function.
     *  @{
     */
        #define AD5941_Reset_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define AD5941_Reset_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define AD5941_Reset_DM_RES_UP          PIN_DM_RES_UP
        #define AD5941_Reset_DM_RES_DWN         PIN_DM_RES_DWN
        #define AD5941_Reset_DM_OD_LO           PIN_DM_OD_LO
        #define AD5941_Reset_DM_OD_HI           PIN_DM_OD_HI
        #define AD5941_Reset_DM_STRONG          PIN_DM_STRONG
        #define AD5941_Reset_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define AD5941_Reset_MASK               AD5941_Reset__MASK
#define AD5941_Reset_SHIFT              AD5941_Reset__SHIFT
#define AD5941_Reset_WIDTH              1u

/* Interrupt constants */
#if defined(AD5941_Reset__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in AD5941_Reset_SetInterruptMode() function.
     *  @{
     */
        #define AD5941_Reset_INTR_NONE      (uint16)(0x0000u)
        #define AD5941_Reset_INTR_RISING    (uint16)(0x0001u)
        #define AD5941_Reset_INTR_FALLING   (uint16)(0x0002u)
        #define AD5941_Reset_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define AD5941_Reset_INTR_MASK      (0x01u) 
#endif /* (AD5941_Reset__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AD5941_Reset_PS                     (* (reg8 *) AD5941_Reset__PS)
/* Data Register */
#define AD5941_Reset_DR                     (* (reg8 *) AD5941_Reset__DR)
/* Port Number */
#define AD5941_Reset_PRT_NUM                (* (reg8 *) AD5941_Reset__PRT) 
/* Connect to Analog Globals */                                                  
#define AD5941_Reset_AG                     (* (reg8 *) AD5941_Reset__AG)                       
/* Analog MUX bux enable */
#define AD5941_Reset_AMUX                   (* (reg8 *) AD5941_Reset__AMUX) 
/* Bidirectional Enable */                                                        
#define AD5941_Reset_BIE                    (* (reg8 *) AD5941_Reset__BIE)
/* Bit-mask for Aliased Register Access */
#define AD5941_Reset_BIT_MASK               (* (reg8 *) AD5941_Reset__BIT_MASK)
/* Bypass Enable */
#define AD5941_Reset_BYP                    (* (reg8 *) AD5941_Reset__BYP)
/* Port wide control signals */                                                   
#define AD5941_Reset_CTL                    (* (reg8 *) AD5941_Reset__CTL)
/* Drive Modes */
#define AD5941_Reset_DM0                    (* (reg8 *) AD5941_Reset__DM0) 
#define AD5941_Reset_DM1                    (* (reg8 *) AD5941_Reset__DM1)
#define AD5941_Reset_DM2                    (* (reg8 *) AD5941_Reset__DM2) 
/* Input Buffer Disable Override */
#define AD5941_Reset_INP_DIS                (* (reg8 *) AD5941_Reset__INP_DIS)
/* LCD Common or Segment Drive */
#define AD5941_Reset_LCD_COM_SEG            (* (reg8 *) AD5941_Reset__LCD_COM_SEG)
/* Enable Segment LCD */
#define AD5941_Reset_LCD_EN                 (* (reg8 *) AD5941_Reset__LCD_EN)
/* Slew Rate Control */
#define AD5941_Reset_SLW                    (* (reg8 *) AD5941_Reset__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define AD5941_Reset_PRTDSI__CAPS_SEL       (* (reg8 *) AD5941_Reset__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define AD5941_Reset_PRTDSI__DBL_SYNC_IN    (* (reg8 *) AD5941_Reset__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define AD5941_Reset_PRTDSI__OE_SEL0        (* (reg8 *) AD5941_Reset__PRTDSI__OE_SEL0) 
#define AD5941_Reset_PRTDSI__OE_SEL1        (* (reg8 *) AD5941_Reset__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define AD5941_Reset_PRTDSI__OUT_SEL0       (* (reg8 *) AD5941_Reset__PRTDSI__OUT_SEL0) 
#define AD5941_Reset_PRTDSI__OUT_SEL1       (* (reg8 *) AD5941_Reset__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define AD5941_Reset_PRTDSI__SYNC_OUT       (* (reg8 *) AD5941_Reset__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(AD5941_Reset__SIO_CFG)
    #define AD5941_Reset_SIO_HYST_EN        (* (reg8 *) AD5941_Reset__SIO_HYST_EN)
    #define AD5941_Reset_SIO_REG_HIFREQ     (* (reg8 *) AD5941_Reset__SIO_REG_HIFREQ)
    #define AD5941_Reset_SIO_CFG            (* (reg8 *) AD5941_Reset__SIO_CFG)
    #define AD5941_Reset_SIO_DIFF           (* (reg8 *) AD5941_Reset__SIO_DIFF)
#endif /* (AD5941_Reset__SIO_CFG) */

/* Interrupt Registers */
#if defined(AD5941_Reset__INTSTAT)
    #define AD5941_Reset_INTSTAT            (* (reg8 *) AD5941_Reset__INTSTAT)
    #define AD5941_Reset_SNAP               (* (reg8 *) AD5941_Reset__SNAP)
    
	#define AD5941_Reset_0_INTTYPE_REG 		(* (reg8 *) AD5941_Reset__0__INTTYPE)
#endif /* (AD5941_Reset__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_AD5941_Reset_H */


/* [] END OF FILE */
