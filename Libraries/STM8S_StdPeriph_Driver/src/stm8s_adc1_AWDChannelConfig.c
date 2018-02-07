
/**
  ********************************************************************************
  * @file    stm8s_adc1_AWDChannelConfig.c
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
#include "stm8s_adc1.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup ADC1_Public_Functions
  * @{
  */

/**
  * @brief  Enables or disables the analog watchdog for the given channel.
  * @param   Channel specifies the desired Channel.
  * It can be set of the values of @ref ADC1_Channel_TypeDef.
  * @param   NewState specifies the analog watchdog new state.
  * can have one of the values of @ref FunctionalState.
  * @retval None
  */
void ADC1_AWDChannelConfig(ADC1_Channel_TypeDef Channel, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));
  assert_param(IS_ADC1_CHANNEL_OK(Channel));
  
  if (Channel < (uint8_t)8)
  {
    if (NewState != DISABLE)
    {
      ADC1->AWCRL |= (uint8_t)((uint8_t)1 << Channel);
    }
    else /* NewState == DISABLE */
    {
      ADC1->AWCRL &= (uint8_t)~(uint8_t)((uint8_t)1 << Channel);
    }
  }
  else
  {
    if (NewState != DISABLE)
    {
      ADC1->AWCRH |= (uint8_t)((uint8_t)1 << (Channel - (uint8_t)8));
    }
    else /* NewState == DISABLE */
    {
      ADC1->AWCRH &= (uint8_t)~(uint8_t)((uint8_t)1 << (uint8_t)(Channel - (uint8_t)8));
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
