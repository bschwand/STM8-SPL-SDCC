
/**
  ********************************************************************************
  * @file    stm8s_tim5_PrescalerConfig.c
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
  * @brief  Configures the TIM5 Prescaler.
  * @param   Prescaler specifies the Prescaler Register value
  * This parameter can be one of the following values
  *                       -  TIM5_PRESCALER_1
  *                       -  TIM5_PRESCALER_2
  *                       -  TIM5_PRESCALER_4
  *                       -  TIM5_PRESCALER_8
  *                       -  TIM5_PRESCALER_16
  *                       -  TIM5_PRESCALER_32
  *                       -  TIM5_PRESCALER_64
  *                       -  TIM5_PRESCALER_128
  *                       -  TIM5_PRESCALER_256
  *                       -  TIM5_PRESCALER_512
  *                       -  TIM5_PRESCALER_1024
  *                       -  TIM5_PRESCALER_2048
  *                       -  TIM5_PRESCALER_4096
  *                       -  TIM5_PRESCALER_8192
  *                       -  TIM5_PRESCALER_16384
  *                       -  TIM5_PRESCALER_32768
  * @param   TIM5_PSCReloadMode specifies the TIM5 Prescaler Reload mode.
  * This parameter can be one of the following values
  *                       - TIM5_PSCRELOADMODE_IMMEDIATE: The Prescaler is loaded
  *                         immediately.
  *                       - TIM5_PSCRELOADMODE_UPDATE: The Prescaler is loaded at
  *                         the update event.
  * @retval None
  */
void TIM5_PrescalerConfig(TIM5_Prescaler_TypeDef Prescaler,
                          TIM5_PSCReloadMode_TypeDef TIM5_PSCReloadMode)
{
  /* Check the parameters */
  assert_param(IS_TIM5_PRESCALER_RELOAD_OK(TIM5_PSCReloadMode));
  assert_param(IS_TIM5_PRESCALER_OK(Prescaler));
  
  /* Set the Prescaler value */
  TIM5->PSCR = (uint8_t)Prescaler;
  
  /* Set or reset the UG Bit */
  TIM5->EGR = (uint8_t)TIM5_PSCReloadMode ;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
