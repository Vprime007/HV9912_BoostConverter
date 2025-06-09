/******************************************************************************
*   Includes
*******************************************************************************/
#include <stdbool.h>

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
    uint8_t current_factor;
    uint8_t dim_duty;
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
static bool isTableFull(void){

    for(uint8_t i=0; i<HV9912_CFG_MAX_NUM_OF_DEVICES; i++){
        if(!(HV9912_table[i].active_flag))    return false;
    }

    return true;
}

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
HV9912_Ret_t HV9912_InitDriver(void){

    return HV9912_STATUS_OK;
}

HV9912_Ret_t HV9912_AddDriver(HV9912_Handle_t *pHandle){

    return HV9912_STATUS_OK;
}

HV9912_Ret_t HV9912_RemoveDriver(HV9912_Handle_t handle){

    return HV9912_STATUS_OK;
}

HV9912_Ret_t HV9912_SetPhaseState(HV9912_Phase_State_t state, HV9912_Handle_t handle){

    return HV9912_STATUS_OK;
}

HV9912_Ret_t HV9912_GetPhaseState(HV9912_Handle_t handle, HV9912_Phase_State_t *pState){

    return HV9912_STATUS_OK;
}

HV9912_Ret_t HV9912_SetDimmingDuty(uint8_t duty, HV9912_Handle_t handle){

    return HV9912_STATUS_OK;
}

/******************************************************************************
*   Interrupts
*******************************************************************************/


