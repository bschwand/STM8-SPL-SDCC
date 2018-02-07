
/**
  ********************************************************************************
  * @file    stm8s_adc1_DeInit.c
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
  * @brief  Deinitializes the ADC1 peripheral registers to their default reset values.
  * @param  None
  * @retval None
  */
void ADC1_DeInit(void)
{
  ADC1->CSR  = ADC1_CSR_RESET_VALUE;
  ADC1->CR1  = ADC1_CR1_RESET_VALUE;
  ADC1->CR2  = ADC1_CR2_RESET_VALUE;
  ADC1->CR3  = ADC1_CR3_RESET_VALUE;
  ADC1->TDRH = ADC1_TDRH_RESET_VALUE;
  ADC1->TDRL = ADC1_TDRL_RESET_VALUE;
  ADC1->HTRH = ADC1_HTRH_RESET_VALUE;
  ADC1->HTRL = ADC1_HTRL_RESET_VALUE;
  ADC1->LTRH = ADC1_LTRH_RESET_VALUE;
  ADC1->LTRL = ADC1_LTRL_RESET_VALUE;
  ADC1->AWCRH = ADC1_AWCRH_RESET_VALUE;
  ADC1->AWCRL = ADC1_AWCRL_RESET_VALUE;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
