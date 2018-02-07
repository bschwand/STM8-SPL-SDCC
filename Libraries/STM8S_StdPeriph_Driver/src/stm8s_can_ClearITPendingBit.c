
/**
  ********************************************************************************
  * @file    stm8s_can_ClearITPendingBit.c
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
  * @brief   Clears the CAN’s interrupt pending bits.
  * @param   CAN_IT: specifies the interrupt pending bit to clear,
  *  can be one of the following parameters:
  *                            CAN_IT_TME = Transmit mailbox empty interrupt
  *                             CAN_IT_FF =FIFO  full    interrupt
  *                            CAN_IT_FOV =FIFO  overrun  interrupt
  *                             CAN_IT_WKU =Wake-up interrupt
  *                             CAN_IT_ERR =General Error interrupt
  *                             CAN_IT_EWG =Error warning interrupt
  *                             CAN_IT_EPV  =Error passive  interrupt
  *                             CAN_IT_BOF = Bus-off   interrupt
  *                             CAN_IT_LEC  =Last error code interrupt
  * @retval None
  */
void CAN_ClearITPendingBit(CAN_IT_TypeDef CAN_IT)
{
  CAN_Page_TypeDef can_page = CAN_GetSelectedPage();
  /* Check the parameters */
  assert_param(IS_CAN_IT_PENDING_BIT_OK(CAN_IT));
  
  switch (CAN_IT)
  {
  case CAN_IT_TME:
    CAN->TSR = CAN_TSR_RQCP012;/* rc_w1*/
    break;
    
  case CAN_IT_FF:
    CAN->RFR = CAN_RFR_FULL; /* rc_w1*/
    break;
    
  case CAN_IT_FOV:
    CAN->RFR = CAN_RFR_FOVR; /* rc_w1*/
    break;
    
  case CAN_IT_WKU:
    CAN->MSR = CAN_MSR_WKUI;  /* rc_w1*/
    break;
    
  case CAN_IT_ERR:
    CAN->PSR = CAN_Page_Config;
    CAN->Page.Config.ESR = (uint8_t)CAN_ESR_RESET_VALUE;
    CAN->MSR = CAN_MSR_ERRI;
    break;
    
  case CAN_IT_EWG:
    CAN->MSR = CAN_MSR_ERRI;
    break;
    
  case CAN_IT_EPV:
    CAN->MSR = CAN_MSR_ERRI;
    break;
    
  case CAN_IT_BOF:
    CAN->MSR = CAN_MSR_ERRI;
    break;
    
  case CAN_IT_LEC:
    CAN->PSR = CAN_Page_Config;
    CAN->Page.Config.ESR = (uint8_t)CAN_ESR_RESET_VALUE;
    break;

  default :
    break;
  }
  /*Restore Last Page*/
  CAN_SelectPage(can_page);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
