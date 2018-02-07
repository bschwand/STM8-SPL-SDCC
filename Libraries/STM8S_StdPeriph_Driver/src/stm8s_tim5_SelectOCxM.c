
/**
  ********************************************************************************
  * @file    stm8s_tim5_SelectOCxM.c
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
  * @brief  Selects the TIM5 Output Compare Mode. This function disables the
  * selected channel before changing the Output Compare Mode. User has to
  * enable this channel using TIM5_CCxCmd and TIM5_CCxNCmd functions.
  * @param   TIM5_Channel specifies the TIM5 Channel.
  * This parameter can be one of the following values:
  *                       - TIM5_Channel1: TIM5 Channel1
  *                       - TIM5_Channel2: TIM5 Channel2
  *                       - TIM5_Channel3: TIM5 Channel3
  * @param   TIM5_OCMode specifies the TIM5 Output Compare Mode.
  * This parameter can be one of the following values:
  *                       - TIM5_OCMODE_TIMING
  *                       - TIM5_OCMODE_ACTIVE
  *                       - TIM5_OCMODE_TOGGLE
  *                       - TIM5_OCMODE_PWM1
  *                       - TIM5_OCMODE_PWM2
  *                       - TIM5_FORCEDACTION_ACTIVE
  *                       - TIM5_FORCEDACTION_INACTIVE
  * @retval None
  */
void TIM5_SelectOCxM(TIM5_Channel_TypeDef TIM5_Channel, TIM5_OCMode_TypeDef TIM5_OCMode)
{
  /* Check the parameters */
  assert_param(IS_TIM5_CHANNEL_OK(TIM5_Channel));
  assert_param(IS_TIM5_OCM_OK(TIM5_OCMode));
  
  if (TIM5_Channel == TIM5_CHANNEL_1)
  {
    /* Disable the Channel 1: Reset the CCE Bit */
    TIM5->CCER1 &= (uint8_t)(~TIM5_CCER1_CC1E);
    
    /* Reset the Output Compare Bits  Set the Output Compare Mode */
    TIM5->CCMR1 = (uint8_t)((uint8_t)(TIM5->CCMR1 & (uint8_t)(~TIM5_CCMR_OCM)) 
                            | (uint8_t)TIM5_OCMode);
  }
  else if (TIM5_Channel == TIM5_CHANNEL_2)
  {
    /* Disable the Channel 2: Reset the CCE Bit */
    TIM5->CCER1 &= (uint8_t)(~TIM5_CCER1_CC2E);
    
    /* Reset the Output Compare Bits ** Set the Output Compare Mode */
    TIM5->CCMR2 = (uint8_t)((uint8_t)(TIM5->CCMR2 & (uint8_t)(~TIM5_CCMR_OCM))
                            | (uint8_t)TIM5_OCMode);
  }
  else
  {
    /* Disable the Channel 3: Reset the CCE Bit */
    TIM5->CCER2 &= (uint8_t)(~TIM5_CCER2_CC3E);
    
    /* Reset the Output Compare Bits ** Set the Output Compare Mode */
    TIM5->CCMR3 = (uint8_t)((uint8_t)(TIM5->CCMR3 & (uint8_t)(~TIM5_CCMR_OCM))
                            | (uint8_t)TIM5_OCMode);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
