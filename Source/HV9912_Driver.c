/******************************************************************************
*   Includes
*******************************************************************************/
#include <stdbool.h>
#include <stdlib.h>

#include "HV9912_Driver.h"

/******************************************************************************
*   Private Definitions
*******************************************************************************/
#define INVALID_TABLE_INDEX             (0xFF)

/******************************************************************************
*   Private Macros
*******************************************************************************/


/******************************************************************************
*   Private Data Types
*******************************************************************************/
typedef struct HV9921_Driver_s{
    bool active_flag;
    uint32_t current_factor;
    uint32_t dim_duty;
    HV9912_Phase_State_t phase_state;
    HV9912_Config_t config;
}HV9912_Driver_t;

/******************************************************************************
*   Private Functions Declaration
*******************************************************************************/
static bool isTableFull(void);
static uint8_t getFirstAvailableIndex(void);

/******************************************************************************
*   Public Variables
*******************************************************************************/


/******************************************************************************
*   Private Variables
*******************************************************************************/
static HV9912_Driver_t HV9912_table[HV9912_CFG_MAX_NUM_OF_DEVICES] = {0};

/******************************************************************************
*   Error Check
*******************************************************************************/


/******************************************************************************
*   Private Functions Definitions
*******************************************************************************/
/***************************************************************************//*!
*  \brief Is HV9912 table is full.
*
*   This function return if the HV9912 instance table if full or not.
*   (True -> Full / False -> Not full).
*   
*   Preconditions: None.
*
*   Side Effects: None.
*
*******************************************************************************/
static bool isTableFull(void){

    for(uint8_t i=0; i<HV9912_CFG_MAX_NUM_OF_DEVICES; i++){
        if(!(HV9912_table[i].active_flag))    return false;
    }

    return true;
}

/***************************************************************************//*!
*  \brief Get first available index.
*
*   This function return the first available index of the HV9912 driver 
*   instance table. If no index available -> return INVALID_TABLE_INDEX.
*   
*   Preconditions: None.
*
*   Side Effects: None.
*
*   \return     Table index.
*
*******************************************************************************/
static uint8_t getFirstAvailableIndex(void){

    for(uint8_t i=0; i<HV9912_CFG_MAX_NUM_OF_DEVICES; i++){
        if(!(HV9912_table[i].active_flag))      return i;
    }

    return INVALID_TABLE_INDEX;
}

/******************************************************************************
*   CallBack Functions implementation
*******************************************************************************/


/******************************************************************************
*   Public Functions Definitions
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
HV9912_Ret_t HV9912_InitDriver(void){

    return HV9912_STATUS_OK;
}

/***************************************************************************//*!
*  \brief Add HV9912 driver instance.
*
*   This function is used to add a HV9912 driver instance to the module.
*   
*   Preconditions: None.
*
*   Side Effects: None.
*
*   \param[in]  pHandle             Pointer to store instance handle.
*
*   \return     operation status
*
*******************************************************************************/
HV9912_Ret_t HV9912_AddDriver(HV9912_Handle_t *pHandle){

    return HV9912_STATUS_OK;
}

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
HV9912_Ret_t HV9912_RemoveDriver(HV9912_Handle_t handle){

    return HV9912_STATUS_OK;
}

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
HV9912_Ret_t HV9912_SetPhaseState(HV9912_Phase_State_t state, HV9912_Handle_t handle){

    //check if params are valid
    if((state >= HV9912_PHASE_INVALID) || (handle >= HV9912_CFG_MAX_NUM_OF_DEVICES)){
        return HV9912_STATUS_ERROR;
    }

    if(state == HV9912_table[handle].phase_state){
        //Phase already in requested state
        return HV9912_STATUS_OK;
    }

    //Set phase state via HV9912 cfg

    //Update phase_state
    HV9912_table[handle].phase_state = state;

    return HV9912_STATUS_OK;
}

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
HV9912_Ret_t HV9912_GetPhaseState(HV9912_Handle_t handle, HV9912_Phase_State_t *pState){

    //Check if params are valid
    if((handle >= HV9912_CFG_MAX_NUM_OF_DEVICES) || (pState == NULL)){
        return HV9912_STATUS_ERROR;
    }

    //Copy current state in pointer
    *pState = HV9912_table[handle].phase_state;

    return HV9912_STATUS_OK;
}

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
HV9912_Ret_t HV9912_SetDimmingDuty(uint32_t duty, HV9912_Handle_t handle){

    //Check if params are valid
    if(handle >= HV9912_CFG_MAX_NUM_OF_DEVICES){
        return HV9912_STATUS_ERROR;
    }

    //Clip duty to max value
    if(duty > HV9912_CFG_MAX_DIM_DUTY)  duty = HV9912_CFG_MAX_DIM_DUTY;

    //Update current value
    HV9912_table[handle].dim_duty = duty;

    return HV9912_STATUS_OK;
}

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
HV9912_Ret_t HV9912_GetDimmingDuty(HV9912_Handle_t handle, uint32_t *pDuty){

    //check if params are valid
    if((handle >= HV9912_CFG_MAX_NUM_OF_DEVICES) || (pDuty == NULL)){
        return HV9912_STATUS_ERROR;
    }

    //Copy current duty in pointer
    *pDuty = HV9912_table[handle].dim_duty;

    return HV9912_STATUS_OK;
}

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
HV9912_Ret_t HV9912_SetCurrentRef(uint32_t ref_factor, HV9912_Handle_t handle){

    //Check if params are valid
    if(handle >= HV9912_CFG_MAX_NUM_OF_DEVICES){
        return HV9912_STATUS_ERROR;
    }

    //Clip current ref factor
    if(ref_factor > HV9912_CFG_MAX_REF_FACTOR)  ref_factor = HV9912_CFG_MAX_REF_FACTOR;

    //Update current value
    HV9912_table[handle].current_factor = ref_factor;

    return HV9912_STATUS_OK;
}

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
HV9912_Ret_t HV9912_GetCurrentRef(HV9912_Handle_t handle, uint32_t *pRefFactor){

    //Check if params are valid
    if((handle > HV9912_CFG_MAX_NUM_OF_DEVICES) || (pRefFactor == NULL)){
        return HV9912_STATUS_ERROR;
    }

    //Copy current factor in pointer
    *pRefFactor = HV9912_table[handle].current_factor;

    return HV9912_STATUS_OK;
}

/******************************************************************************
*   Interrupts
*******************************************************************************/


