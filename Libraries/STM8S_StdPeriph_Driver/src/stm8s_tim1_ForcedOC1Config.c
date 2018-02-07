
/**
  ********************************************************************************
  * @file    stm8s_tim1_ForcedOC1Config.c
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
  * @brief  Forces the TIM1 Channel1 output waveform to active or inactive level.
  * @param   TIM1_ForcedAction specifies the forced Action to be set to the output waveform.
  * This parameter can be one of the following values:
  * - TIM1_FORCEDACTION_ACTIVE: Force active level on OC1REF
  * - TIM1_FORCEDACTION_INACTIVE: Force inactive level on OC1REF.
  * @retval None
  */
void TIM1_ForcedOC1Config(TIM1_ForcedAction_TypeDef TIM1_ForcedAction)
{
  /* Check the parameters */
  assert_param(IS_TIM1_FORCED_ACTION_OK(TIM1_ForcedAction));
  
  /* Reset the OCM Bits & Configure the Forced output Mode */
  TIM1->CCMR1 =  (uint8_t)((uint8_t)(TIM1->CCMR1 & (uint8_t)(~TIM1_CCMR_OCM))|
                           (uint8_t)TIM1_ForcedAction);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
