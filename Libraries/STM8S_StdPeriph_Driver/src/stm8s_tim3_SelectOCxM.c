
/**
  ********************************************************************************
  * @file    stm8s_tim3_SelectOCxM.c
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
  * @brief  Selects the TIM3 Output Compare Mode. This function disables the
  * selected channel before changing the Output Compare Mode. User has to
  * enable this channel using TIM3_CCxCmd and TIM3_CCxNCmd functions.
  * @param   TIM3_Channel specifies the TIM3 Channel.
  * This parameter can be one of the following values:
  *                       - TIM3_CHANNEL_1: TIM3 Channel1
  *                       - TIM3_CHANNEL_2: TIM3 Channel2
  * @param   TIM3_OCMode specifies the TIM3 Output Compare Mode.
  * This parameter can be one of the following values:
  *                       - TIM3_OCMODE_TIMING
  *                       - TIM3_OCMODE_ACTIVE
  *                       - TIM3_OCMODE_TOGGLE
  *                       - TIM3_OCMODE_PWM1
  *                       - TIM3_OCMODE_PWM2
  *                       - TIM3_FORCEDACTION_ACTIVE
  *                       - TIM3_FORCEDACTION_INACTIVE
  * @retval None
  */
void TIM3_SelectOCxM(TIM3_Channel_TypeDef TIM3_Channel, TIM3_OCMode_TypeDef TIM3_OCMode)
{
  /* Check the parameters */
  assert_param(IS_TIM3_CHANNEL_OK(TIM3_Channel));
  assert_param(IS_TIM3_OCM_OK(TIM3_OCMode));
  
  if (TIM3_Channel == TIM3_CHANNEL_1)
  {
    /* Disable the Channel 1: Reset the CCE Bit */
    TIM3->CCER1 &= (uint8_t)(~TIM3_CCER1_CC1E);
    
    /* Reset the Output Compare Bits & Set the Output Compare Mode */
    TIM3->CCMR1 = (uint8_t)((uint8_t)(TIM3->CCMR1 & (uint8_t)(~TIM3_CCMR_OCM)) | (uint8_t)TIM3_OCMode);
  }
  else
  {
    /* Disable the Channel 2: Reset the CCE Bit */
    TIM3->CCER1 &= (uint8_t)(~TIM3_CCER1_CC2E);
    
    /* Reset the Output Compare Bits & Set the Output Compare Mode */
    TIM3->CCMR2 = (uint8_t)((uint8_t)(TIM3->CCMR2 & (uint8_t)(~TIM3_CCMR_OCM)) | (uint8_t)TIM3_OCMode);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
