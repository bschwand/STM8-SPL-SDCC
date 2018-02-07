
/**
  ********************************************************************************
  * @file    stm8s_tim1_CCxCmd.c
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
  * @brief  Enables or disables the TIM1 Capture Compare Channel x (x=1,..,4).
  * @param   TIM1_Channel specifies the TIM1 Channel.
  * This parameter can be one of the following values:
  *                       - TIM1_CHANNEL_1: TIM1 Channel1
  *                       - TIM1_CHANNEL_2: TIM1 Channel2
  *                       - TIM1_CHANNEL_3: TIM1 Channel3
  *                       - TIM1_CHANNEL_4: TIM1 Channel4
  * @param   NewState specifies the TIM1 Channel CCxE bit new state.
  * This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void TIM1_CCxCmd(TIM1_Channel_TypeDef TIM1_Channel, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_TIM1_CHANNEL_OK(TIM1_Channel));
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));
  
  if (TIM1_Channel == TIM1_CHANNEL_1)
  {
    /* Set or Reset the CC1E Bit */
    if (NewState != DISABLE)
    {
      TIM1->CCER1 |= TIM1_CCER1_CC1E;
    }
    else
    {
      TIM1->CCER1 &= (uint8_t)(~TIM1_CCER1_CC1E);
    }
    
  }
  else if (TIM1_Channel == TIM1_CHANNEL_2)
  {
    /* Set or Reset the CC2E Bit */
    if (NewState != DISABLE)
    {
      TIM1->CCER1 |= TIM1_CCER1_CC2E;
    }
    else
    {
      TIM1->CCER1 &= (uint8_t)(~TIM1_CCER1_CC2E);
    }
  }
  else if (TIM1_Channel == TIM1_CHANNEL_3)
  {
    /* Set or Reset the CC3E Bit */
    if (NewState != DISABLE)
    {
      TIM1->CCER2 |= TIM1_CCER2_CC3E;
    }
    else
    {
      TIM1->CCER2 &= (uint8_t)(~TIM1_CCER2_CC3E);
    }
  }
  else
  {
    /* Set or Reset the CC4E Bit */
    if (NewState != DISABLE)
    {
      TIM1->CCER2 |= TIM1_CCER2_CC4E;
    }
    else
    {
      TIM1->CCER2 &= (uint8_t)(~TIM1_CCER2_CC4E);
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
