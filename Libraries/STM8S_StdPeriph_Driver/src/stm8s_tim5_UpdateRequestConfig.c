
/**
  ********************************************************************************
  * @file    stm8s_tim5_UpdateRequestConfig.c
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
#include "stm8s_tim5.h"
#include "private/stm8s_tim5_private.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup TIM5_Public_Functions
  * @{
  */

/**
  * @brief  Selects the TIM5 Update Request Interrupt source.
  * @param   TIM5_UpdateSource specifies the Update source.
  * This parameter can be one of the following values
  *                       - TIM5_UPDATESOURCE_REGULAR
  *                       - TIM5_UPDATESOURCE_GLOBAL
  * @retval None
  */
void TIM5_UpdateRequestConfig(TIM5_UpdateSource_TypeDef TIM5_UpdateSource)
{
  /* Check the parameters */
  assert_param(IS_TIM5_UPDATE_SOURCE_OK(TIM5_UpdateSource));
  
  /* Set or Reset the URS Bit */
  if (TIM5_UpdateSource != TIM5_UPDATESOURCE_GLOBAL)
  {
    TIM5->CR1 |= TIM5_CR1_URS ;
  }
  else
  {
    TIM5->CR1 &= (uint8_t)(~TIM5_CR1_URS) ;
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
