
/**
  ********************************************************************************
  * @file    stm8s_can_GetFlagStatus.c
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
  * @brief  Checks whether the specified CAN flag is set or not.
  * @param   CAN_FLAG: specifies the flag to check, can be one of @ref CAN_FLAG_TypeDef enumeration.
  * @retval The new state of CAN_FLAG which can be one of @ref FlagStatus.
  */
FlagStatus CAN_GetFlagStatus(CAN_FLAG_TypeDef CAN_Flag)
{
  FlagStatus bitstatus = RESET;
  CAN_Page_TypeDef can_page = (CAN_Page_TypeDef)0;
  
  /* Check the parameters */
  assert_param(IS_CAN_FLAG_STATUS_OK(CAN_Flag));
  
  if (((uint16_t)CAN_Flag & 0x0700)!= RESET)
  {
    if (((uint16_t)CAN_Flag & 0x020B)!= RESET)
    {
      /*Receive Flags*/
      if ((CAN->RFR & (uint16_t)CAN_Flag )!= RESET)
      {
        /* CAN_FLAG is set */
        bitstatus = SET;
      }
      else
      {
        /* CAN_FLAG is reset */
        bitstatus = RESET;
      }
      
    }
    else if (((uint16_t)CAN_Flag & 0x0403)!= RESET)
    {
      /*Transmit Flags*/
      if ((CAN->TSR & (uint16_t)CAN_Flag )!= RESET)
      {
        /* CAN_FLAG is set */
        bitstatus = SET;
      }
      else
      {
        /* CAN_FLAG is reset */
        bitstatus = RESET;
      }
    }
    else /*if((CAN_Flag & 0x0108)!=(uint16_t)RESET)*/
    {
      /*wake up Flags*/
      if ((CAN->MSR & (uint16_t)CAN_Flag )!= RESET)
      {
        /* CAN_FLAG is set */
        bitstatus = SET;
      }
      else
      {
        /* CAN_FLAG is reset */
        bitstatus = RESET;
      }
    }
  }
  else
  {
    /*Error Flags*/
    can_page = CAN_GetSelectedPage();
    
    CAN->PSR = CAN_Page_Config;
    if ((CAN->Page.Config.ESR & (uint16_t)CAN_Flag) != RESET)
    {
      /* CAN_FLAG is set */
      bitstatus = SET;
    }
    else
    {
      /* CAN_FLAG is reset */
      bitstatus = RESET;
    }
    /*Restore Last Page*/
    CAN_SelectPage(can_page);
  }
  
  
  /* Return the CAN_FLAG status */
  return  (FlagStatus)bitstatus;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
