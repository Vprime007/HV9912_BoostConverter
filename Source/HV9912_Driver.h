#ifndef _HV9912_DRIVER_H
#define _HV9912_DRIVER_H

#include "config/HV9912_Driver_cfg.h"

#include <stdint.h>

/******************************************************************************
*   Public Definitions
*******************************************************************************/


/******************************************************************************
*   Public Macros
*******************************************************************************/


/******************************************************************************
*   Public Data Types
*******************************************************************************/
typedef uint8_t                     (HV9912_Handle_t);

typedef enum HV9912_Phase_State_e{
    HV9912_PHASE_DISABLE = 0,
    HV9912_PHASE_ENABLE,

    HV9912_PHASE_INVALID,
}HV9912_Phase_State_t;

typedef enum HV9912_Ret_e{
    HV9912_STATUS_ERROR,
    HV9912_STATUS_OK,
}HV9912_Ret_t;

/******************************************************************************
*   Public Variables
*******************************************************************************/


/******************************************************************************
*   Error Check
*******************************************************************************/


/******************************************************************************
*   Public Functions
*******************************************************************************/
/***************************************************************************//*!
*  \brief HV9912 Driver initialization.
*
*   This function is used to init the HV9912 Driver.
*   
*   Preconditions: None.
*
*   Side Effects: None.
*
*   \return     operation status
*
*******************************************************************************/
HV9912_Ret_t HV9912_InitDriver(void);

/***************************************************************************//*!
*  \brief Add HV9912 driver instance.
*
*   This function is used to add a HV9912 driver instance to the module.
*   
*   Preconditions: None.
*
*   Side Effects: None.
*
*   \param[in]  config              Driver configuration.
*   \param[in]  pHandle             Pointer to store instance handle.
*
*   \return     operation status
*
*******************************************************************************/
HV9912_Ret_t HV9912_AddDriver(HV9912_Config_t config, HV9912_Handle_t *pHandle);

/***************************************************************************//*!
*  \brief Remove HV9912 driver instance.
*
*   This function is used to remove a HV9912 driver instance to the module.
*   
*   Preconditions: None.
*
*   Side Effects: None.
*
*   \param[in]  handle             Instance handle.
*
*   \return     operation status
*
*******************************************************************************/
HV9912_Ret_t HV9912_RemoveDriver(HV9912_Handle_t handle);

/***************************************************************************//*!
*  \brief Set HV9912 phase state
*
*   This function is used to set the phase state (enabled/disabled) of 
*   a driver instance.
*   
*   Preconditions: None.
*
*   Side Effects: None.
*
*   \param[in]  state               Phase state.
*   \param[in]  pHandle             Instance handle.
*
*   \return     operation status
*
*******************************************************************************/
HV9912_Ret_t HV9912_SetPhaseState(HV9912_Phase_State_t state, HV9912_Handle_t handle);

/***************************************************************************//*!
*  \brief Get HV9912 phase state
*
*   This function is used to get the phase state (enabled/disabled) of 
*   a driver instance.
*   
*   Preconditions: None.
*
*   Side Effects: None.
*
*   \param[in]  pState              Pointer to store phase state.
*   \param[in]  pHandle             Instance handle.
*
*   \return     operation status
*
*******************************************************************************/
HV9912_Ret_t HV9912_GetPhaseState(HV9912_Handle_t handle, HV9912_Phase_State_t *pState);

/***************************************************************************//*!
*  \brief Set HV9912 phase Dimming duty cycle.
*
*   This function is used to set the dimming duty cycle of a driver instance.
*   
*   Preconditions: None.
*
*   Side Effects: None.
*
*   \param[in]  duty                Dimming duty cycle
*   \param[in]  handle              Instance handle.
*
*   \return     operation status
*
*******************************************************************************/
HV9912_Ret_t HV9912_SetDimmingDuty(uint32_t duty, HV9912_Handle_t handle);

/***************************************************************************//*!
*  \brief Get HV9912 dimming duty.
*
*   This function is used to get the dimming duty cycle of 
*   a driver instance.
*   
*   Preconditions: None.
*
*   Side Effects: None.
*
*   \param[in]  handle              Instance handle.
*   \param[in]  pDuty               Pointer to store dimming duty.
*
*   \return     operation status
*
*******************************************************************************/
HV9912_Ret_t HV9912_GetDimmingDuty(HV9912_Handle_t handle, uint32_t *pDuty);

/***************************************************************************//*!
*  \brief Set HV9912 Current reference factor.
*
*   This function is used to set the current reference factor of a driver 
*   instance.
*   
*   Preconditions: None.
*
*   Side Effects: None.
*
*   \param[in]  ref_factor          Current reference factor.
*   \param[in]  handle              Instance handle.
*
*   \return     operation status
*
*******************************************************************************/
HV9912_Ret_t HV9912_SetCurrentRef(uint32_t ref_factor, HV9912_Handle_t handle);

/***************************************************************************//*!
*  \brief Get HV9912 Current reference factor.
*
*   This function is used to get the current reference factor of a driver 
*   instance.
*   
*   Preconditions: None.
*
*   Side Effects: None.
*
*   \param[in]  handle              Instance handle.
*   \param[in]  pRefFactor          Pointer to store current ref factor.
*
*   \return     operation status
*
*******************************************************************************/
HV9912_Ret_t HV9912_GetCurrentRef(HV9912_Handle_t handle, uint32_t *pRefFactor);

#endif//_HV9912_DRIVER_H