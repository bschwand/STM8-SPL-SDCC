
/**
  ********************************************************************************
  * @file    stm8s_tim1_SelectOnePulseMode.c
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
#include "stm8s_tim1.h"
#include "private/stm8s_tim1_private.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup TIM1_Public_Functions
  * @{
  */

/**
  * @brief  Selects the TIM1’s One Pulse Mode.
  * @param   TIM1_OPMode specifies the OPM Mode to be used.
  * This parameter can be one of the following values
  *                    - TIM1_OPMODE_SINGLE
  *                    - TIM1_OPMODE_REPETITIVE
  * @retval None
  */
void TIM1_SelectOnePulseMode(TIM1_OPMode_TypeDef TIM1_OPMode)
{
  /* Check the parameters */
  assert_param(IS_TIM1_OPM_MODE_OK(TIM1_OPMode));
  
  /* Set or Reset the OPM Bit */
  if (TIM1_OPMode != TIM1_OPMODE_REPETITIVE)
  {
    TIM1->CR1 |= TIM1_CR1_OPM;
  }
  else
  {
    TIM1->CR1 &= (uint8_t)(~TIM1_CR1_OPM);
  }
  
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
