
/**
  ********************************************************************************
  * @file    stm8s_adc2_PrescalerConfig.c
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
  * @brief  Configure the ADC2 prescaler division factor.
  * @param   ADC2_Prescaler: the selected prescaler.
  * It can be one of the values of @ref ADC2_PresSel_TypeDef.
  * @retval None
  */
void ADC2_PrescalerConfig(ADC2_PresSel_TypeDef ADC2_Prescaler)
{
  /* Check the parameter */
  assert_param(IS_ADC2_PRESSEL_OK(ADC2_Prescaler));
  
  /* Clear the SPSEL bits */
  ADC2->CR1 &= (uint8_t)(~ADC2_CR1_SPSEL);
  /* Select the prescaler division factor according to ADC2_PrescalerSelection values */
  ADC2->CR1 |= (uint8_t)(ADC2_Prescaler);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
