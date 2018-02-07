
/**
  ********************************************************************************
  * @file    stm8s_tim5_SelectInputTrigger.c
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
  * @brief  Selects the TIM5 Input Trigger source.
  * @param   TIM5_InputTriggerSource : Specifies Input Trigger source.
  * This parameter can be one of the @ref TIM5_TS_TypeDef enumeration.
  * @retval None
  */
void TIM5_SelectInputTrigger(TIM5_TS_TypeDef TIM5_InputTriggerSource)
{
  uint8_t tmpsmcr = 0;
  
  /* Check the parameters */
  assert_param(IS_TIM5_TRIGGER_SELECTION_OK(TIM5_InputTriggerSource));
  
  tmpsmcr = TIM5->SMCR;
  
  /* Select the Trigger Source */
  tmpsmcr &= (uint8_t)(~TIM5_SMCR_TS);
  tmpsmcr |= (uint8_t)TIM5_InputTriggerSource;
  
  TIM5->SMCR = (uint8_t)tmpsmcr;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
