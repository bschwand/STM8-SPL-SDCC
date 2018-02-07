
/**
  ********************************************************************************
  * @file    stm8s_tim1_OC1Init.c
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
  * @brief  Initializes the TIM1 Channel1 according to the specified parameters.
  * @param  TIM1_OCMode specifies the Output Compare mode from 
  *         @ref TIM1_OCMode_TypeDef.
  * @param  TIM1_OutputState specifies the Output State from 
  *         @ref TIM1_OutputState_TypeDef.
  * @param  TIM1_OutputNState specifies the Complementary Output State 
  *         from @ref TIM1_OutputNState_TypeDef.
  * @param  TIM1_Pulse specifies the Pulse width value.
  * @param  TIM1_OCPolarity specifies the Output Compare Polarity from 
  *         @ref TIM1_OCPolarity_TypeDef.
  * @param  TIM1_OCNPolarity specifies the Complementary Output Compare Polarity
  *         from @ref TIM1_OCNPolarity_TypeDef.
  * @param  TIM1_OCIdleState specifies the Output Compare Idle State from 
  *         @ref TIM1_OCIdleState_TypeDef.
  * @param  TIM1_OCNIdleState specifies the Complementary Output Compare Idle 
  *         State from @ref TIM1_OCIdleState_TypeDef.
  * @retval None
  */
void TIM1_OC1Init(TIM1_OCMode_TypeDef TIM1_OCMode,
                  TIM1_OutputState_TypeDef TIM1_OutputState,
                  TIM1_OutputNState_TypeDef TIM1_OutputNState,
                  uint16_t TIM1_Pulse,
                  TIM1_OCPolarity_TypeDef TIM1_OCPolarity,
                  TIM1_OCNPolarity_TypeDef TIM1_OCNPolarity,
                  TIM1_OCIdleState_TypeDef TIM1_OCIdleState,
                  TIM1_OCNIdleState_TypeDef TIM1_OCNIdleState)
{
  /* Check the parameters */
  assert_param(IS_TIM1_OC_MODE_OK(TIM1_OCMode));
  assert_param(IS_TIM1_OUTPUT_STATE_OK(TIM1_OutputState));
  assert_param(IS_TIM1_OUTPUTN_STATE_OK(TIM1_OutputNState));
  assert_param(IS_TIM1_OC_POLARITY_OK(TIM1_OCPolarity));
  assert_param(IS_TIM1_OCN_POLARITY_OK(TIM1_OCNPolarity));
  assert_param(IS_TIM1_OCIDLE_STATE_OK(TIM1_OCIdleState));
  assert_param(IS_TIM1_OCNIDLE_STATE_OK(TIM1_OCNIdleState));
  
  /* Disable the Channel 1: Reset the CCE Bit, Set the Output State , 
  the Output N State, the Output Polarity & the Output N Polarity*/
  TIM1->CCER1 &= (uint8_t)(~( TIM1_CCER1_CC1E | TIM1_CCER1_CC1NE 
                             | TIM1_CCER1_CC1P | TIM1_CCER1_CC1NP));
  /* Set the Output State & Set the Output N State & Set the Output Polarity &
  Set the Output N Polarity */
  TIM1->CCER1 |= (uint8_t)((uint8_t)((uint8_t)(TIM1_OutputState & TIM1_CCER1_CC1E)
                                     | (uint8_t)(TIM1_OutputNState & TIM1_CCER1_CC1NE))
                           | (uint8_t)( (uint8_t)(TIM1_OCPolarity  & TIM1_CCER1_CC1P)
                                       | (uint8_t)(TIM1_OCNPolarity & TIM1_CCER1_CC1NP)));
  
  /* Reset the Output Compare Bits & Set the Output Compare Mode */
  TIM1->CCMR1 = (uint8_t)((uint8_t)(TIM1->CCMR1 & (uint8_t)(~TIM1_CCMR_OCM)) | 
                          (uint8_t)TIM1_OCMode);
  
  /* Reset the Output Idle state & the Output N Idle state bits */
  TIM1->OISR &= (uint8_t)(~(TIM1_OISR_OIS1 | TIM1_OISR_OIS1N));
  /* Set the Output Idle state & the Output N Idle state configuration */
  TIM1->OISR |= (uint8_t)((uint8_t)( TIM1_OCIdleState & TIM1_OISR_OIS1 ) | 
                          (uint8_t)( TIM1_OCNIdleState & TIM1_OISR_OIS1N ));
  
  /* Set the Pulse value */
  TIM1->CCR1H = (uint8_t)(TIM1_Pulse >> 8);
  TIM1->CCR1L = (uint8_t)(TIM1_Pulse);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
