
/**
  ********************************************************************************
  * @file    stm8s_adc1_GetAWDChannelStatus.c
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
  * @brief  Checks the specified analog watchdog channel status.
  * @param   Channel: specify the channel of which to check the analog watchdog
  * can be one of the values of @ref ADC1_Channel_TypeDef.
  * @retval FlagStatus Status of the analog watchdog.
  */
FlagStatus ADC1_GetAWDChannelStatus(ADC1_Channel_TypeDef Channel)
{
  uint8_t status = 0;
  
  /* Check the parameters */
  assert_param(IS_ADC1_CHANNEL_OK(Channel));
  
  if (Channel < (uint8_t)8)
  {
    status = (uint8_t)(ADC1->AWSRL & (uint8_t)((uint8_t)1 << Channel));
  }
  else /* Channel = 8 | 9 */
  {
    status = (uint8_t)(ADC1->AWSRH & (uint8_t)((uint8_t)1 << (Channel - (uint8_t)8)));
  }
  
  return ((FlagStatus)status);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
