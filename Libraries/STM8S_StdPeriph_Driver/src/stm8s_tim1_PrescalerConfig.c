
/**
  ********************************************************************************
  * @file    stm8s_tim1_PrescalerConfig.c
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
  * @brief  Configures the TIM1 Prescaler.
  * @param   Prescaler specifies the Prescaler Register value
  * This parameter must be a value between 0x0000 and 0xFFFF
  * @param   TIM1_PSCReloadMode specifies the TIM1 Prescaler Reload mode.
  * This parameter can be one of the following values
  * - TIM1_PSCRELOADMODE_IMMEDIATE: The Prescaler is loaded immediately.
  * - TIM1_PSCRELOADMODE_UPDATE: The Prescaler is loaded at the update event.
  * @retval None
  */
void TIM1_PrescalerConfig(uint16_t Prescaler,
                          TIM1_PSCReloadMode_TypeDef TIM1_PSCReloadMode)
{
  /* Check the parameters */
  assert_param(IS_TIM1_PRESCALER_RELOAD_OK(TIM1_PSCReloadMode));
  
  /* Set the Prescaler value */
  TIM1->PSCRH = (uint8_t)(Prescaler >> 8);
  TIM1->PSCRL = (uint8_t)(Prescaler);
  
  /* Set or reset the UG Bit */
  TIM1->EGR = (uint8_t)TIM1_PSCReloadMode;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
