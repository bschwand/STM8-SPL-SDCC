
/**
  ********************************************************************************
  * @file    stm8s_tim3_OC1Init.c
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
  * @brief  Initializes the TIM3 Channel1 according to the specified parameters.
  * @param   TIM3_OCMode specifies the Output Compare mode  from @ref TIM3_OCMode_TypeDef.
  * @param   TIM3_OutputState specifies the Output State  from @ref TIM3_OutputState_TypeDef.
  * @param   TIM3_Pulse specifies the Pulse width  value.
  * @param   TIM3_OCPolarity specifies the Output Compare Polarity  from @ref TIM3_OCPolarity_TypeDef.
  * @retval None
  */
void TIM3_OC1Init(TIM3_OCMode_TypeDef TIM3_OCMode,
                  TIM3_OutputState_TypeDef TIM3_OutputState,
                  uint16_t TIM3_Pulse,
                  TIM3_OCPolarity_TypeDef TIM3_OCPolarity)
{
  /* Check the parameters */
  assert_param(IS_TIM3_OC_MODE_OK(TIM3_OCMode));
  assert_param(IS_TIM3_OUTPUT_STATE_OK(TIM3_OutputState));
  assert_param(IS_TIM3_OC_POLARITY_OK(TIM3_OCPolarity));
  
  /* Disable the Channel 1: Reset the CCE Bit, Set the Output State , the Output Polarity */
  TIM3->CCER1 &= (uint8_t)(~( TIM3_CCER1_CC1E | TIM3_CCER1_CC1P));
  /* Set the Output State &  Set the Output Polarity  */
  TIM3->CCER1 |= (uint8_t)((uint8_t)(TIM3_OutputState  & TIM3_CCER1_CC1E   ) | (uint8_t)(TIM3_OCPolarity   & TIM3_CCER1_CC1P   ));
  
  /* Reset the Output Compare Bits & Set the Output Compare Mode */
  TIM3->CCMR1 = (uint8_t)((uint8_t)(TIM3->CCMR1 & (uint8_t)(~TIM3_CCMR_OCM)) | (uint8_t)TIM3_OCMode);
  
  /* Set the Pulse value */
  TIM3->CCR1H = (uint8_t)(TIM3_Pulse >> 8);
  TIM3->CCR1L = (uint8_t)(TIM3_Pulse);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
