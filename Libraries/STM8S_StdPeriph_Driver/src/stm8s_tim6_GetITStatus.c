
/**
  ********************************************************************************
  * @file    stm8s_tim6_GetITStatus.c
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
#include "stm8s_tim6.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup TIM6_Public_Functions
  * @{
  */

/**
  * @brief  Checks whether the TIM6 interrupt has occurred or not.
  * @param   TIM6_IT : Specifies the TIM6 interrupt source to check.
  * This parameter can be one of the @ref TIM6_IT_TypeDef enumeration.
  * @retval ITStatus : The new state of the TIM6_IT.
  * This parameter can be any of the @ref ITStatus enumeration.
  */
ITStatus TIM6_GetITStatus(TIM6_IT_TypeDef TIM6_IT)
{
  ITStatus bitstatus = RESET;
  uint8_t itStatus = 0, itEnable = 0;
  
  /* Check the parameters */
  assert_param(IS_TIM6_GET_IT_OK(TIM6_IT));
  
  itStatus = (uint8_t)(TIM6->SR1 & (uint8_t)TIM6_IT);
  
  itEnable = (uint8_t)(TIM6->IER & (uint8_t)TIM6_IT);
  
  if ((itStatus != (uint8_t)RESET ) && (itEnable != (uint8_t)RESET ))
  {
    bitstatus = (ITStatus)SET;
  }
  else
  {
    bitstatus = (ITStatus)RESET;
  }
  return ((ITStatus)bitstatus);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
