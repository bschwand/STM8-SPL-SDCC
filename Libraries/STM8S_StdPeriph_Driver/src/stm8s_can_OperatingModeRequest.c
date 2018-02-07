
/**
  ********************************************************************************
  * @file    stm8s_can_OperatingModeRequest.c
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    30-September-2014
  * @brief   This file contains all the functions for the UART1 peripheral.
   ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm8s_can.h"
#include "private/stm8s_can_private.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup CAN_Public_Functions
  * @{
  */

/**
  * @brief  Select the CAN Operation mode.
  * @param  CAN_OperatingMode CAN Operating Mode ,
  *         this parameter can be one of @ref CAN_OperatingMode_TypeDef enumeration.
  * @retval the status of the requested mode which can be 
  *         - CAN_ModeStatus_Failed    CAN failed entering the specific mode
  *         - CAN_ModeStatus_Success  CAN Succeed entering the specific mode 

  */
CAN_ModeStatus_TypeDef CAN_OperatingModeRequest(CAN_OperatingMode_TypeDef CAN_OperatingMode)
{
  uint16_t timeout = CAN_ACKNOWLEDGE_TIMEOUT;
  uint8_t modestatus = 0;
  
  assert_param(IS_CAN_OPERATINGMODE_OK(CAN_OperatingMode));
  
  if (CAN_OperatingMode == CAN_OperatingMode_Initialization)
  {
    /* Request initialisation */
    CAN->MCR = (uint8_t)((uint8_t)(CAN->MCR & (uint8_t)(~CAN_MCR_SLEEP)) | CAN_MCR_INRQ);
    
    /* Wait the acknowledge */
    while (((CAN->MSR & CAN_MODE_MASK) != CAN_MSR_INAK) && (timeout != 0))
    {
      timeout--;
    }
    if ((CAN->MSR & CAN_MODE_MASK) != CAN_MSR_INAK)
    {
      modestatus = CAN_ModeStatus_Failed;
    }
    else
    {
      modestatus = CAN_ModeStatus_Success;  
    }
    
  }
  else  if (CAN_OperatingMode == CAN_OperatingMode_Normal)
  {
    /* Request leave initialisation and sleep mode  and enter Normal mode */
    CAN->MCR &= (uint8_t)(~(CAN_MCR_SLEEP|CAN_MCR_INRQ));
    
    /* Wait the acknowledge */
    while (((CAN->MSR & CAN_MODE_MASK) != 0) && (timeout!=0))
    {
      timeout--;
    }
    if ((CAN->MSR & CAN_MODE_MASK) != 0)
    {
      modestatus = CAN_ModeStatus_Failed;
    }
    else
    {
      modestatus = CAN_ModeStatus_Success;  
    }
  }
  else  if (CAN_OperatingMode == CAN_OperatingMode_Sleep)
  {
    /* Request Sleep mode */
    CAN->MCR = (uint8_t)((uint8_t)(CAN->MCR & (uint8_t)(~CAN_MCR_INRQ)) | CAN_MCR_SLEEP);
    
    /* Wait the acknowledge */
    while (((CAN->MSR & CAN_MODE_MASK) != CAN_MSR_SLAK) && (timeout!=0))
    {
      timeout--;
    }
    if ((CAN->MSR & CAN_MODE_MASK) != CAN_MSR_SLAK)
    {
      modestatus = CAN_ModeStatus_Failed;  
    }
    else
    {
      modestatus = CAN_ModeStatus_Success;  
    }
  }
  else
  {
    modestatus = CAN_ModeStatus_Failed;
  }
  return (CAN_ModeStatus_TypeDef)(modestatus);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
