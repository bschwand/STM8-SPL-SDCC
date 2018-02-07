
/**
  ********************************************************************************
  * @file    stm8s_can_ITConfig.c
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
  * @brief   Enables or disables the specified CAN interrupts.
  * @param    CAN_IT: specifies the CAN interrupt sources to be enabled or disabled.
  * @param   NewState : CAN_IT new state , can be one of @ref FunctionalState
  * @retval None
  */
void CAN_ITConfig(CAN_IT_TypeDef CAN_IT, FunctionalState NewState)
{
  uint8_t tmperrorinterrupt = 0;
  CAN_Page_TypeDef can_page = CAN_GetSelectedPage();
  
  
  /* Check the parameters */
  assert_param(IS_CAN_IT_CONFIG_OK(CAN_IT));
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));
  
  tmperrorinterrupt = (uint8_t)(((uint16_t)CAN_IT) >>7);
  tmperrorinterrupt = (uint8_t)((uint8_t)((uint16_t)tmperrorinterrupt & 0xF0) | 
                                (uint8_t)((uint8_t)((uint16_t)tmperrorinterrupt & 0x0F) >>1));
  
  CAN->PSR = CAN_Page_Config;
  if (NewState != DISABLE)
  {
    /* Enable the selected CAN interrupt */
    CAN->IER |= (uint8_t)(CAN_IT);
    CAN->Page.Config.EIER |= (uint8_t)(tmperrorinterrupt);
  }
  else
  {
    /* Disable the selected CAN interrupt */
    CAN->IER &= (uint8_t)~(uint8_t)((uint16_t)CAN_IT);
    CAN->Page.Config.EIER &= (uint8_t)~(tmperrorinterrupt);
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
