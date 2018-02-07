
/**
  ********************************************************************************
  * @file    stm8s_tim1_TIxExternalClockConfig.c
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
  * @brief  Configures the TIM1 Trigger as External Clock.
  * @param  TIM1_TIxExternalCLKSource specifies Trigger source.
  *         This parameter can be one of the following values:
  *                     - TIM1_TIXEXTERNALCLK1SOURCE_TI1: TI1 Edge Detector
  *                     - TIM1_TIXEXTERNALCLK1SOURCE_TI2: Filtered TIM1 Input 1
  *                     - TIM1_TIXEXTERNALCLK1SOURCE_TI1ED: Filtered TIM1 Input 2
  * @param  TIM1_ICPolarity specifies the TIx Polarity.
  *         This parameter can be:
  *                     - TIM1_ICPOLARITY_RISING
  *                     - TIM1_ICPOLARITY_FALLING
  * @param  ICFilter specifies the filter value.
  *         This parameter must be a value between 0x00 and 0x0F
  * @retval None
  */
void TIM1_TIxExternalClockConfig(TIM1_TIxExternalCLK1Source_TypeDef TIM1_TIxExternalCLKSource,
                                 TIM1_ICPolarity_TypeDef TIM1_ICPolarity,
                                 uint8_t ICFilter)
{
  /* Check the parameters */
  assert_param(IS_TIM1_TIXCLK_SOURCE_OK(TIM1_TIxExternalCLKSource));
  assert_param(IS_TIM1_IC_POLARITY_OK(TIM1_ICPolarity));
  assert_param(IS_TIM1_IC_FILTER_OK(ICFilter));
  
  /* Configure the TIM1 Input Clock Source */
  if (TIM1_TIxExternalCLKSource == TIM1_TIXEXTERNALCLK1SOURCE_TI2)
  {
    TIM1_TI2_Config((uint8_t)TIM1_ICPolarity, (uint8_t)TIM1_ICSELECTION_DIRECTTI, (uint8_t)ICFilter);
  }
  else
  {
    TIM1_TI1_Config((uint8_t)TIM1_ICPolarity, (uint8_t)TIM1_ICSELECTION_DIRECTTI, (uint8_t)ICFilter);
  }
  
  /* Select the Trigger source */
  TIM1_SelectInputTrigger((TIM1_TS_TypeDef)TIM1_TIxExternalCLKSource);
  
  /* Select the External clock mode1 */
  TIM1->SMCR |= (uint8_t)(TIM1_SLAVEMODE_EXTERNAL1);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
