
/**
  ********************************************************************************
  * @file    stm8s_tim3_SelectOnePulseMode.c
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
#include "stm8s_tim3.h"
#include "private/stm8s_tim3_private.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup TIM3_Public_Functions
  * @{
  */

/**
  * @brief  Selects the TIM3’s One Pulse Mode.
  * @param   TIM3_OPMode specifies the OPM Mode to be used.
  * This parameter can be one of the following values
  *                    - TIM3_OPMODE_SINGLE
  *                    - TIM3_OPMODE_REPETITIVE
  * @retval None
  */
void TIM3_SelectOnePulseMode(TIM3_OPMode_TypeDef TIM3_OPMode)
{
  /* Check the parameters */
  assert_param(IS_TIM3_OPM_MODE_OK(TIM3_OPMode));
  
  /* Set or Reset the OPM Bit */
  if (TIM3_OPMode != TIM3_OPMODE_REPETITIVE)
  {
    TIM3->CR1 |= TIM3_CR1_OPM;
  }
  else
  {
    TIM3->CR1 &= (uint8_t)(~TIM3_CR1_OPM);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
