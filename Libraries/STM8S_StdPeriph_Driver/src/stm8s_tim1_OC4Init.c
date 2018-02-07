
/**
  ********************************************************************************
  * @file    stm8s_tim1_OC4Init.c
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
  * @brief  Initializes the TIM1 Channel4 according to the specified parameters.
  * @param  TIM1_OCMode specifies the Output Compare mode  from 
  *         @ref TIM1_OCMode_TypeDef.
  * @param  TIM1_OutputState specifies the Output State
  *         from @ref TIM1_OutputState_TypeDef.
  * @param  TIM1_Pulse specifies the Pulse width  value.
  * @param  TIM1_OCPolarity specifies the Output Compare Polarity
  *         from @ref TIM1_OCPolarity_TypeDef.
  * @param  TIM1_OCIdleState specifies the Output Compare Idle State
  *         from @ref TIM1_OCIdleState_TypeDef.
  * @retval None
  */
void TIM1_OC4Init(TIM1_OCMode_TypeDef TIM1_OCMode,
                  TIM1_OutputState_TypeDef TIM1_OutputState,
                  uint16_t TIM1_Pulse,
                  TIM1_OCPolarity_TypeDef TIM1_OCPolarity,
                  TIM1_OCIdleState_TypeDef TIM1_OCIdleState)
{
  /* Check the parameters */
  assert_param(IS_TIM1_OC_MODE_OK(TIM1_OCMode));
  assert_param(IS_TIM1_OUTPUT_STATE_OK(TIM1_OutputState));
  assert_param(IS_TIM1_OC_POLARITY_OK(TIM1_OCPolarity));
  assert_param(IS_TIM1_OCIDLE_STATE_OK(TIM1_OCIdleState));
  
  /* Disable the Channel 4: Reset the CCE Bit */
  TIM1->CCER2 &= (uint8_t)(~(TIM1_CCER2_CC4E | TIM1_CCER2_CC4P));
  /* Set the Output State  &  the Output Polarity */
  TIM1->CCER2 |= (uint8_t)((uint8_t)(TIM1_OutputState & TIM1_CCER2_CC4E ) |  
                           (uint8_t)(TIM1_OCPolarity  & TIM1_CCER2_CC4P ));
  
  /* Reset the Output Compare Bit  and Set the Output Compare Mode */
  TIM1->CCMR4 = (uint8_t)((uint8_t)(TIM1->CCMR4 & (uint8_t)(~TIM1_CCMR_OCM)) | 
                          TIM1_OCMode);
  
  /* Set the Output Idle state */
  if (TIM1_OCIdleState != TIM1_OCIDLESTATE_RESET)
  {
    TIM1->OISR |= (uint8_t)(~TIM1_CCER2_CC4P);
  }
  else
  {
    TIM1->OISR &= (uint8_t)(~TIM1_OISR_OIS4);
  }
  
  /* Set the Pulse value */
  TIM1->CCR4H = (uint8_t)(TIM1_Pulse >> 8);
  TIM1->CCR4L = (uint8_t)(TIM1_Pulse);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
