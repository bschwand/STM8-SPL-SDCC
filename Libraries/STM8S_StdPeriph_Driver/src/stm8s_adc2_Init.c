
/**
  ********************************************************************************
  * @file    stm8s_adc2_Init.c
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
  * @brief  Initializes the ADC2 peripheral according to the specified parameters
  * @param   ADC2_ConversionMode: specifies the conversion mode
  * can be one of the values of @ref ADC2_ConvMode_TypeDef.
  * @param   ADC2_Channel: specifies the channel to convert
  * can be one of the values of @ref ADC2_Channel_TypeDef.
  * @param   ADC2_PrescalerSelection: specifies the ADC2 prescaler
  * can be one of the values of @ref ADC2_PresSel_TypeDef.
  * @param   ADC2_ExtTrigger: specifies the external trigger
  * can be one of the values of @ref ADC2_ExtTrig_TypeDef.
  * @param   ADC2_ExtTriggerState: specifies the external trigger new state
  * can be one of the values of @ref FunctionalState.
  * @param   ADC2_Align: specifies the converted data alignment
  * can be one of the values of @ref ADC2_Align_TypeDef.
  * @param   ADC2_SchmittTriggerChannel: specifies the schmitt trigger channel
  * can be one of the values of @ref ADC2_SchmittTrigg_TypeDef.
  * @param   ADC2_SchmittTriggerState: specifies the schmitt trigger state
  * can be one of the values of @ref FunctionalState.
  * @retval None
  */
void ADC2_Init(ADC2_ConvMode_TypeDef ADC2_ConversionMode, ADC2_Channel_TypeDef ADC2_Channel, ADC2_PresSel_TypeDef ADC2_PrescalerSelection, ADC2_ExtTrig_TypeDef ADC2_ExtTrigger, FunctionalState ADC2_ExtTriggerState, ADC2_Align_TypeDef ADC2_Align, ADC2_SchmittTrigg_TypeDef ADC2_SchmittTriggerChannel, FunctionalState ADC2_SchmittTriggerState)
{
  /* Check the parameters */
  assert_param(IS_ADC2_CONVERSIONMODE_OK(ADC2_ConversionMode));
  assert_param(IS_ADC2_CHANNEL_OK(ADC2_Channel));
  assert_param(IS_ADC2_PRESSEL_OK(ADC2_PrescalerSelection));
  assert_param(IS_ADC2_EXTTRIG_OK(ADC2_ExtTrigger));
  assert_param(IS_FUNCTIONALSTATE_OK(((ADC2_ExtTriggerState))));
  assert_param(IS_ADC2_ALIGN_OK(ADC2_Align));
  assert_param(IS_ADC2_SCHMITTTRIG_OK(ADC2_SchmittTriggerChannel));
  assert_param(IS_FUNCTIONALSTATE_OK(ADC2_SchmittTriggerState));
  
  /*-----------------CR1 & CSR configuration --------------------*/
  /* Configure the conversion mode and the channel to convert
  respectively according to ADC2_ConversionMode & ADC2_Channel values  &  ADC2_Align values */
  ADC2_ConversionConfig(ADC2_ConversionMode, ADC2_Channel, ADC2_Align);
  /* Select the prescaler division factor according to ADC2_PrescalerSelection values */
  ADC2_PrescalerConfig(ADC2_PrescalerSelection);
  
  /*-----------------CR2 configuration --------------------*/
  /* Configure the external trigger state and event respectively
  according to ADC2_ExtTrigStatus, ADC2_ExtTrigger */
  ADC2_ExternalTriggerConfig(ADC2_ExtTrigger, ADC2_ExtTriggerState);
  
  /*------------------TDR configuration ---------------------------*/
  /* Configure the schmitt trigger channel and state respectively
  according to ADC2_SchmittTriggerChannel & ADC2_SchmittTriggerNewState  values */
  ADC2_SchmittTriggerConfig(ADC2_SchmittTriggerChannel, ADC2_SchmittTriggerState);
  
  /* Enable the ADC2 peripheral */
  ADC2->CR1 |= ADC2_CR1_ADON;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
