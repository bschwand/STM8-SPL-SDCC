
/**
  ********************************************************************************
  * @file    stm8s_adc2_SchmittTriggerConfig.c
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
#include "stm8s_adc2.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup ADC2_Public_Functions
  * @{
  */

/**
  * @brief  Enables or disables the ADC2 Schmitt Trigger on a selected channel.
  * @param   ADC2_SchmittTriggerChannel specifies the desired Channel.
  * It can be set of the values of @ref ADC2_SchmittTrigg_TypeDef.
  * @param   NewState specifies the Channel  ADC2 Schmitt Trigger new status.
  * can have one of the values of @ref FunctionalState.
  * @retval None
  */
void ADC2_SchmittTriggerConfig(ADC2_SchmittTrigg_TypeDef ADC2_SchmittTriggerChannel, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_ADC2_SCHMITTTRIG_OK(ADC2_SchmittTriggerChannel));
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));
  
  if (ADC2_SchmittTriggerChannel == ADC2_SCHMITTTRIG_ALL)
  {
    if (NewState != DISABLE)
    {
      ADC2->TDRL &= (uint8_t)0x0;
      ADC2->TDRH &= (uint8_t)0x0;
    }
    else /* NewState == DISABLE */
    {
      ADC2->TDRL |= (uint8_t)0xFF;
      ADC2->TDRH |= (uint8_t)0xFF;
    }
  }
  else if (ADC2_SchmittTriggerChannel < ADC2_SCHMITTTRIG_CHANNEL8)
  {
    if (NewState != DISABLE)
    {
      ADC2->TDRL &= (uint8_t)(~(uint8_t)((uint8_t)0x01 << (uint8_t)ADC2_SchmittTriggerChannel));
    }
    else /* NewState == DISABLE */
    {
      ADC2->TDRL |= (uint8_t)((uint8_t)0x01 << (uint8_t)ADC2_SchmittTriggerChannel);
    }
  }
  else /* ADC2_SchmittTriggerChannel >= ADC2_SCHMITTTRIG_CHANNEL8 */
  {
    if (NewState != DISABLE)
    {
      ADC2->TDRH &= (uint8_t)(~(uint8_t)((uint8_t)0x01 << ((uint8_t)ADC2_SchmittTriggerChannel - (uint8_t)8)));
    }
    else /* NewState == DISABLE */
    {
      ADC2->TDRH |= (uint8_t)((uint8_t)0x01 << ((uint8_t)ADC2_SchmittTriggerChannel - (uint8_t)8));
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
