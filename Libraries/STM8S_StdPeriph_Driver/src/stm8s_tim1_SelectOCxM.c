
/**
  ********************************************************************************
  * @file    stm8s_tim1_SelectOCxM.c
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
  * @brief  Selects the TIM1 Output Compare Mode. This function disables the
  * selected channel before changing the Output Compare Mode. User has to
  * enable this channel using TIM1_CCxCmd and TIM1_CCxNCmd functions.
  * @param   TIM1_Channel specifies the TIM1 Channel.
  * This parameter can be one of the following values:
  *                       - TIM1_CHANNEL_1: TIM1 Channel1
  *                       - TIM1_CHANNEL_2: TIM1 Channel2
  *                       - TIM1_CHANNEL_3: TIM1 Channel3
  *                       - TIM1_CHANNEL_4: TIM1 Channel4
  * @param   TIM1_OCMode specifies the TIM1 Output Compare Mode.
  * This parameter can be one of the following values:
  *                       - TIM1_OCMODE_TIMING
  *                       - TIM1_OCMODE_ACTIVE
  *                       - TIM1_OCMODE_TOGGLE
  *                       - TIM1_OCMODE_PWM1
  *                       - TIM1_OCMODE_PWM2
  *                       - TIM1_FORCEDACTION_ACTIVE
  *                       - TIM1_FORCEDACTION_INACTIVE
  * @retval None
  */
void TIM1_SelectOCxM(TIM1_Channel_TypeDef TIM1_Channel, TIM1_OCMode_TypeDef TIM1_OCMode)
{
  /* Check the parameters */
  assert_param(IS_TIM1_CHANNEL_OK(TIM1_Channel));
  assert_param(IS_TIM1_OCM_OK(TIM1_OCMode));
  
  if (TIM1_Channel == TIM1_CHANNEL_1)
  {
    /* Disable the Channel 1: Reset the CCE Bit */
    TIM1->CCER1 &= (uint8_t)(~TIM1_CCER1_CC1E);
    
    /* Reset the Output Compare Bits & Set the Output Compare Mode */
    TIM1->CCMR1 = (uint8_t)((uint8_t)(TIM1->CCMR1 & (uint8_t)(~TIM1_CCMR_OCM)) 
                            | (uint8_t)TIM1_OCMode);
  }
  else if (TIM1_Channel == TIM1_CHANNEL_2)
  {
    /* Disable the Channel 2: Reset the CCE Bit */
    TIM1->CCER1 &= (uint8_t)(~TIM1_CCER1_CC2E);
    
    /* Reset the Output Compare Bits & Set the Output Compare Mode */
    TIM1->CCMR2 = (uint8_t)((uint8_t)(TIM1->CCMR2 & (uint8_t)(~TIM1_CCMR_OCM))
                            | (uint8_t)TIM1_OCMode);
  }
  else if (TIM1_Channel == TIM1_CHANNEL_3)
  {
    /* Disable the Channel 3: Reset the CCE Bit */
    TIM1->CCER2 &= (uint8_t)(~TIM1_CCER2_CC3E);
    
    /* Reset the Output Compare Bits & Set the Output Compare Mode */
    TIM1->CCMR3 = (uint8_t)((uint8_t)(TIM1->CCMR3 & (uint8_t)(~TIM1_CCMR_OCM)) 
                            | (uint8_t)TIM1_OCMode);
  }
  else
  {
    /* Disable the Channel 4: Reset the CCE Bit */
    TIM1->CCER2 &= (uint8_t)(~TIM1_CCER2_CC4E);
    
    /* Reset the Output Compare Bits & Set the Output Compare Mode */
    TIM1->CCMR4 = (uint8_t)((uint8_t)(TIM1->CCMR4 & (uint8_t)(~TIM1_CCMR_OCM)) 
                            | (uint8_t)TIM1_OCMode);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
