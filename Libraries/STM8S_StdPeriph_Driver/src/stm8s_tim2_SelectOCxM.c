
/**
  ********************************************************************************
  * @file    stm8s_tim2_SelectOCxM.c
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
  * @brief  Selects the TIM2 Output Compare Mode. This function disables the
  * selected channel before changing the Output Compare Mode. User has to
  * enable this channel using TIM2_CCxCmd and TIM2_CCxNCmd functions.
  * @param   TIM2_Channel specifies the TIM2 Channel.
  * This parameter can be one of the following values:
  *                       - TIM2_CHANNEL_1: TIM2 Channel1
  *                       - TIM2_CHANNEL_2: TIM2 Channel2
  *                       - TIM2_CHANNEL_3: TIM2 Channel3
  * @param   TIM2_OCMode specifies the TIM2 Output Compare Mode.
  * This parameter can be one of the following values:
  *                       - TIM2_OCMODE_TIMING
  *                       - TIM2_OCMODE_ACTIVE
  *                       - TIM2_OCMODE_TOGGLE
  *                       - TIM2_OCMODE_PWM1
  *                       - TIM2_OCMODE_PWM2
  *                       - TIM2_FORCEDACTION_ACTIVE
  *                       - TIM2_FORCEDACTION_INACTIVE
  * @retval None
  */
void TIM2_SelectOCxM(TIM2_Channel_TypeDef TIM2_Channel, TIM2_OCMode_TypeDef TIM2_OCMode)
{
  /* Check the parameters */
  assert_param(IS_TIM2_CHANNEL_OK(TIM2_Channel));
  assert_param(IS_TIM2_OCM_OK(TIM2_OCMode));
  
  if (TIM2_Channel == TIM2_CHANNEL_1)
  {
    /* Disable the Channel 1: Reset the CCE Bit */
    TIM2->CCER1 &= (uint8_t)(~TIM2_CCER1_CC1E);
    
    /* Reset the Output Compare Bits & Set the Output Compare Mode */
    TIM2->CCMR1 = (uint8_t)((uint8_t)(TIM2->CCMR1 & (uint8_t)(~TIM2_CCMR_OCM))
                            | (uint8_t)TIM2_OCMode);
  }
  else if (TIM2_Channel == TIM2_CHANNEL_2)
  {
    /* Disable the Channel 2: Reset the CCE Bit */
    TIM2->CCER1 &= (uint8_t)(~TIM2_CCER1_CC2E);
    
    /* Reset the Output Compare Bits & Set the Output Compare Mode */
    TIM2->CCMR2 = (uint8_t)((uint8_t)(TIM2->CCMR2 & (uint8_t)(~TIM2_CCMR_OCM))
                            | (uint8_t)TIM2_OCMode);
  }
  else
  {
    /* Disable the Channel 3: Reset the CCE Bit */
    TIM2->CCER2 &= (uint8_t)(~TIM2_CCER2_CC3E);
    
    /* Reset the Output Compare Bits & Set the Output Compare Mode */
    TIM2->CCMR3 = (uint8_t)((uint8_t)(TIM2->CCMR3 & (uint8_t)(~TIM2_CCMR_OCM))
                            | (uint8_t)TIM2_OCMode);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
