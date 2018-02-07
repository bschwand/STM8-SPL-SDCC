
/**
  ********************************************************************************
  * @file    stm8s_tim2_UpdateRequestConfig.c
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
#include "stm8s_tim2.h"
#include "private/stm8s_tim2_private.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup TIM2_Public_Functions
  * @{
  */

/**
  * @brief  Selects the TIM2 Update Request Interrupt source.
  * @param   TIM2_UpdateSource specifies the Update source.
  * This parameter can be one of the following values
  *                       - TIM2_UPDATESOURCE_REGULAR
  *                       - TIM2_UPDATESOURCE_GLOBAL
  * @retval None
  */
void TIM2_UpdateRequestConfig(TIM2_UpdateSource_TypeDef TIM2_UpdateSource)
{
  /* Check the parameters */
  assert_param(IS_TIM2_UPDATE_SOURCE_OK(TIM2_UpdateSource));
  
  /* Set or Reset the URS Bit */
  if (TIM2_UpdateSource != TIM2_UPDATESOURCE_GLOBAL)
  {
    TIM2->CR1 |= (uint8_t)TIM2_CR1_URS;
  }
  else
  {
    TIM2->CR1 &= (uint8_t)(~TIM2_CR1_URS);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
