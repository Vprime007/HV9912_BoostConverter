#ifndef _HV9912_DRIVER_H
#define _HV9912_DRIVER_H

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
typedef uint8_t                 (HV9912_Handle_t);

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
HV9912_Ret_t HV9912_InitDriver(void);

HV9912_Ret_t HV9912_AddDriver(HV9912_Handle_t *pHandle);

HV9912_Ret_t HV9912_RemoveDriver(HV9912_Handle_t handle);

HV9912_Ret_t HV9912_SetPhaseState(HV9912_Phase_State_t state, HV9912_Handle_t handle);

HV9912_Ret_t HV9912_GetPhaseState(HV9912_Handle_t handle, HV9912_Phase_State_t *pState);

HV9912_Ret_t HV9912_SetDimmingDuty(uint8_t duty, HV9912_Handle_t handle);

#endif//_HV9912_DRIVER_H