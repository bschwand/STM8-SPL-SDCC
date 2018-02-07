
/**
  ********************************************************************************
  * @file    stm8s_tim2_CCxCmd.c
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
  * @brief  Enables or disables the TIM2 Capture Compare Channel x.
  * @param   TIM2_Channel specifies the TIM2 Channel.
  * This parameter can be one of the following values:
  *                       - TIM2_CHANNEL_1: TIM2 Channel1
  *                       - TIM2_CHANNEL_2: TIM2 Channel2
  *                       - TIM2_CHANNEL_3: TIM2 Channel3
  * @param   NewState specifies the TIM2 Channel CCxE bit new state.
  * This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void TIM2_CCxCmd(TIM2_Channel_TypeDef TIM2_Channel, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_TIM2_CHANNEL_OK(TIM2_Channel));
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));
  
  if (TIM2_Channel == TIM2_CHANNEL_1)
  {
    /* Set or Reset the CC1E Bit */
    if (NewState != DISABLE)
    {
      TIM2->CCER1 |= (uint8_t)TIM2_CCER1_CC1E;
    }
    else
    {
      TIM2->CCER1 &= (uint8_t)(~TIM2_CCER1_CC1E);
    }
    
  }
  else if (TIM2_Channel == TIM2_CHANNEL_2)
  {
    /* Set or Reset the CC2E Bit */
    if (NewState != DISABLE)
    {
      TIM2->CCER1 |= (uint8_t)TIM2_CCER1_CC2E;
    }
    else
    {
      TIM2->CCER1 &= (uint8_t)(~TIM2_CCER1_CC2E);
    }
  }
  else
  {
    /* Set or Reset the CC3E Bit */
    if (NewState != DISABLE)
    {
      TIM2->CCER2 |= (uint8_t)TIM2_CCER2_CC3E;
    }
    else
    {
      TIM2->CCER2 &= (uint8_t)(~TIM2_CCER2_CC3E);
    }
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
