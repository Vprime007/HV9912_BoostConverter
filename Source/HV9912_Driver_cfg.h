#ifndef _HV9912_DRIVER_CFG_H
#define _HV9912_DRIVER_CFG_H

#include <stdint.h>

/******************************************************************************
*   Public Definitions
*******************************************************************************/
#define HV9912_CFG_MAX_NUM_OF_DEVICES       (2)
#define HV9912_CFG_MAX_DIM_DUTY             (255)
#define HV9912_CFG_MAX_REF_FACTOR           (255)

/******************************************************************************
*   Public Macros
*******************************************************************************/


/******************************************************************************
*   Public Data Types
*******************************************************************************/
typedef struct HV9912_Config_s{
    uint8_t phase_en_gpio;
    uint8_t dimming_gpio;
    uint8_t current_ref_gpio;
}HV9912_Config_t;

typedef enum HV9912_CFG_Ret_e{
    HV9912_CFG_STATUS_ERROR,
    HV9912_CFG_STATUS_OK,
}HV9912_CFG_Ret_t;

/******************************************************************************
*   Public Variables
*******************************************************************************/


/******************************************************************************
*   Error Check
*******************************************************************************/


/******************************************************************************
*   Public Functions
*******************************************************************************/
HV9912_CFG_Ret_t HV9912_CFG_SetupDevice(HV9912_Config_t *pConfig);

HV9912_CFG_Ret_t HV9912_CFG_EnablePhase(HV9912_Config_t *pConfig);

HV9912_CFG_Ret_t HV9912_CFG_DisablePhase(HV9912_Config_t *pConfig);

HV9912_CFG_Ret_t HV9912_CFG_SetCurrentRef(uint32_t factor, HV9912_Config_t *pConfig);

HV9912_CFG_Ret_t HV9912_CFG_SetDimmingDuty(uint32_t duty, HV9912_Config_t *pConfig);


#endif//_HV9912_DRIVER_CFG_H