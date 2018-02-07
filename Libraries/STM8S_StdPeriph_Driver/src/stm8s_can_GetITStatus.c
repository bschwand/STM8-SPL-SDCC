
/**
  ********************************************************************************
  * @file    stm8s_can_GetITStatus.c
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
  * @brief  Checks whether the specified CAN interrupt has occurred or not.
  * @param   CAN_IT: specifies the CAN interrupt source to check, can be one of @ref CAN_IT_TypeDef.
  * @retval The new state of CAN_IT, which can be one of @ref ITStatus.
  */
ITStatus CAN_GetITStatus(CAN_IT_TypeDef CAN_IT)
{
  ITStatus pendingbitstatus = RESET;
  CAN_Page_TypeDef can_page = CAN_GetSelectedPage();
  
  /* Check the parameters */
  assert_param(IS_CAN_IT_STATUS_OK(CAN_IT));
  
  
  switch (CAN_IT)
  {
  case CAN_IT_TME:
    if ((CAN->IER & CAN_IER_TMEIE) !=RESET)
    {
      pendingbitstatus = CheckITStatus(CAN->TSR, CAN_TSR_RQCP012);
    }
    else
    {
      pendingbitstatus = RESET;
    }
    break;
    
  case CAN_IT_FMP:
    if ((CAN->IER & CAN_IER_FMPIE) !=RESET)
    {
      pendingbitstatus = CheckITStatus(CAN->RFR, CAN_RFR_FMP01);
    }
    else
    {
      pendingbitstatus = RESET;
    }
    break;
  case CAN_IT_FF:
    if ((CAN->IER & CAN_IER_FFIE) !=RESET)
    {
      pendingbitstatus = CheckITStatus(CAN->RFR, CAN_RFR_FULL);
    }
    else
    {
      pendingbitstatus = RESET;
    }
    break;
  case CAN_IT_FOV:
    if ((CAN->IER & CAN_IER_FOVIE) !=RESET)
    {
      pendingbitstatus = CheckITStatus(CAN->RFR, CAN_RFR_FOVR);
    }
    else
    {
      pendingbitstatus = RESET;
    }
    break;
  case CAN_IT_WKU:
    if ((CAN->IER & CAN_IER_WKUIE) !=RESET)
    {
      pendingbitstatus = CheckITStatus(CAN->MSR, CAN_MSR_WKUI);
    }
    else
    {
      pendingbitstatus = RESET;
    }
    break;
    
  case CAN_IT_ERR:
    CAN->PSR = CAN_Page_Config;
    if ((CAN->Page.Config.EIER & CAN_EIER_ERRIE) !=RESET)
    {
      pendingbitstatus = CheckITStatus(CAN->Page.Config.ESR, CAN_ESR_EWGF|CAN_ESR_EPVF|CAN_ESR_BOFF|CAN_ESR_LEC);
    }
    else
    {
      pendingbitstatus = RESET;
    }
    break;
    
  case CAN_IT_EWG:
    CAN->PSR = CAN_Page_Config;
    if ((CAN->Page.Config.EIER & CAN_EIER_EWGIE) !=RESET)
    {
      pendingbitstatus = CheckITStatus(CAN->Page.Config.ESR, CAN_ESR_EWGF);
    }
    else
    {
      pendingbitstatus = RESET;
    }
    break;
    
  case CAN_IT_EPV:
    CAN->PSR = CAN_Page_Config;
    if ((CAN->Page.Config.EIER & CAN_EIER_EPVIE) !=RESET)
    {
      pendingbitstatus = CheckITStatus(CAN->Page.Config.ESR, CAN_ESR_EPVF);
    }
    else
    {
      pendingbitstatus = RESET;
    }
    break;
  case CAN_IT_BOF:
    CAN->PSR = CAN_Page_Config;
    if ((CAN->Page.Config.EIER & CAN_EIER_BOFIE) !=RESET)
    {
      pendingbitstatus = CheckITStatus(CAN->Page.Config.ESR, CAN_ESR_BOFF);
    }
    else
    {
      pendingbitstatus = RESET;
    }
    break;
  case CAN_IT_LEC:
    CAN->PSR = CAN_Page_Config;
    if ((CAN->Page.Config.EIER & CAN_EIER_LECIE) !=RESET)
    {
      pendingbitstatus = CheckITStatus(CAN->Page.Config.ESR, CAN_ESR_LEC);
    }
    else
    {
      pendingbitstatus = RESET;
    }
    break;
  default :
    pendingbitstatus = RESET;
    break;
  }
  /*Restore Last Page*/
  CAN_SelectPage(can_page);
  /* Return the CAN_IT status */
  return  (ITStatus)pendingbitstatus;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
