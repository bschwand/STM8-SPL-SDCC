
/**
  ********************************************************************************
  * @file    stm8s_adc2_ConversionConfig.c
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
  * @brief  Configure the ADC2 conversion on selected channel.
  * @param   ADC2_ConversionMode Specifies the conversion type.
  * It can be set of the values of @ref ADC2_ConvMode_TypeDef
  * @param   ADC2_Channel specifies the ADC2 Channel.
  * It can be set of the values of @ref ADC2_Channel_TypeDef
  * @param   ADC2_Align specifies the converted data alignment.
  * It can be set of the values of @ref ADC2_Align_TypeDef
  * @retval None
  */
void ADC2_ConversionConfig(ADC2_ConvMode_TypeDef ADC2_ConversionMode, ADC2_Channel_TypeDef ADC2_Channel, ADC2_Align_TypeDef ADC2_Align)
{
  /* Check the parameters */
  assert_param(IS_ADC2_CONVERSIONMODE_OK(ADC2_ConversionMode));
  assert_param(IS_ADC2_CHANNEL_OK(ADC2_Channel));
  assert_param(IS_ADC2_ALIGN_OK(ADC2_Align));
  
  /* Clear the align bit */
  ADC2->CR2 &= (uint8_t)(~ADC2_CR2_ALIGN);
  /* Configure the data alignment */
  ADC2->CR2 |= (uint8_t)(ADC2_Align);
  
  if (ADC2_ConversionMode == ADC2_CONVERSIONMODE_CONTINUOUS)
  {
    /* Set the continuous conversion mode */
    ADC2->CR1 |= ADC2_CR1_CONT;
  }
  else /* ADC2_ConversionMode == ADC2_CONVERSIONMODE_SINGLE */
  {
    /* Set the single conversion mode */
    ADC2->CR1 &= (uint8_t)(~ADC2_CR1_CONT);
  }
  
  /* Clear the ADC2 channels */
  ADC2->CSR &= (uint8_t)(~ADC2_CSR_CH);
  /* Select the ADC2 channel */
  ADC2->CSR |= (uint8_t)(ADC2_Channel);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
