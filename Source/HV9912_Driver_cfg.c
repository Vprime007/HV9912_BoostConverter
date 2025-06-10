/******************************************************************************
*   Includes
*******************************************************************************/
#include "HV9912_Driver_cfg.h"

/******************************************************************************
*   Private Definitions
*******************************************************************************/


/******************************************************************************
*   Private Macros
*******************************************************************************/


/******************************************************************************
*   Private Data Types
*******************************************************************************/


/******************************************************************************
*   Private Functions Declaration
*******************************************************************************/


/******************************************************************************
*   Public Variables
*******************************************************************************/


/******************************************************************************
*   Private Variables
*******************************************************************************/


/******************************************************************************
*   Error Check
*******************************************************************************/


/******************************************************************************
*   Private Functions Definitions
*******************************************************************************/


/******************************************************************************
*   CallBack Functions implementation
*******************************************************************************/


/******************************************************************************
*   Public Functions Definitions
*******************************************************************************/
/***************************************************************************//*!
*  \brief Setup a HV9912 Device.
*
*   This function is used to setup any related peripheral to a HV9912 instance.
*   
*   Preconditions: None.
*
*   Side Effects: None.
*
*   \param[in]  pConfig             Pointer to instance configuration.
*
*   \return     operation status
*
*******************************************************************************/
HV9912_CFG_Ret_t HV9912_CFG_SetupDevice(HV9912_Config_t *pConfig){

    /*Populate this function based on the hardware used (ie. MCU).
    This function should initialize/configure any peripherals used
    by an instance of the HV9912 driver. The pConfig should contain 
    all infos/variables needed to setup the peripherals*/

    return HV9912_CFG_STATUS_OK;
}

/***************************************************************************//*!
*  \brief Enable HV9912 Phase.
*
*   This function is used to enable a HV9912 Phase using related peripherals.
*   
*   Preconditions: None.
*
*   Side Effects: None.
*
*   \param[in]  pConfig             Pointer to instance configuration.
*
*   \return     operation status
*
*******************************************************************************/
HV9912_CFG_Ret_t HV9912_CFG_EnablePhase(HV9912_Config_t *pConfig){

    /*Populate this function based on the hardware used (ie. MCU).
    This function should enable the phase of a Hv9912 instance. All
    variables/infos needed should be in pConfig.*/

    return HV9912_CFG_STATUS_OK;
}

/***************************************************************************//*!
*  \brief Disable HV9912 Phase.
*
*   This function is used to disable a HV9912 Phase using related peripherals.
*   
*   Preconditions: None.
*
*   Side Effects: None.
*
*   \param[in]  pConfig             Pointer to instance configuration.
*
*   \return     operation status
*
*******************************************************************************/
HV9912_CFG_Ret_t HV9912_CFG_DisablePhase(HV9912_Config_t *pConfig){

    /*Populate this function based on the hardware used (ie. MCU).
    This function should disable the phase of a Hv9912 instance. All
    variables/infos needed should be in pConfig.*/

    return HV9912_CFG_STATUS_OK;
}

/***************************************************************************//*!
*  \brief Set current reference factor.
*
*   This function is used to set the current reference factor of a HV9912 
*   instance using related peripherals.
*   
*   Preconditions: None.
*
*   Side Effects: None.
*
*   \param[in]  factor              Current Ref factor.
*   \param[in]  pConfig             Pointer to instance configuration.
*
*   \return     operation status
*
*******************************************************************************/
HV9912_CFG_Ret_t HV9912_CFG_SetCurrentRef(uint32_t factor, HV9912_Config_t *pConfig){

    return HV9912_CFG_STATUS_OK;
}
/***************************************************************************//*!
*  \brief Set dimming duty cycle
*
*   This function is used to set the dimming duty cycle of a HV9912 instance
*   using related peripherals.
*   
*   Preconditions: None.
*
*   Side Effects: None.
*
*   \param[in]  duty                Dimming duty cycle.
*   \param[in]  pConfig             Pointer to instance configuration.
*
*   \return     operation status
*
*******************************************************************************/
HV9912_CFG_Ret_t HV9912_CFG_SetDimmingDuty(uint32_t duty, HV9912_Config_t *pConfig){

    return HV9912_CFG_STATUS_OK;
}

/******************************************************************************
*   Interrupts
*******************************************************************************/


