
/**
  ********************************************************************************
  * @file    stm8s_tim1_CounterModeConfig.c
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
  * @brief  Specifies the TIM1 Counter Mode to be used.
  * @param   TIM1_CounterMode specifies the Counter Mode to be used
  * This parameter can be one of the following values:
  * - TIM1_COUNTERMODE_UP: TIM1 Up Counting Mode
  * - TIM1_COUNTERMODE_DOWN: TIM1 Down Counting Mode
  * - TIM1_COUNTERMODE_CENTERALIGNED1: TIM1 Center Aligned Mode1
  * - TIM1_CounterMode_CenterAligned2: TIM1 Center Aligned Mode2
  * - TIM1_COUNTERMODE_CENTERALIGNED3: TIM1 Center Aligned Mode3
  * @retval None
  */
void TIM1_CounterModeConfig(TIM1_CounterMode_TypeDef TIM1_CounterMode)
{
  /* Check the parameters */
  assert_param(IS_TIM1_COUNTER_MODE_OK(TIM1_CounterMode));
  
  
  /* Reset the CMS and DIR Bits & Set the Counter Mode */
  TIM1->CR1 = (uint8_t)((uint8_t)(TIM1->CR1 & (uint8_t)((uint8_t)(~TIM1_CR1_CMS) & (uint8_t)(~TIM1_CR1_DIR)))
                        | (uint8_t)TIM1_CounterMode);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
