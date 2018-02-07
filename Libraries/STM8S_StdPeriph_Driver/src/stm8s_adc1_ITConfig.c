
/**
  ********************************************************************************
  * @file    stm8s_adc1_ITConfig.c
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
  * @brief  Enables or disables the ADC1 interrupt.
  * @param   ADC1_IT specifies the name of the interrupt to enable or disable.
  * This parameter can be one of the following values:
  *    - ADC1_IT_AWDITEN : Analog WDG interrupt enable
  *    - ADC1_IT_EOCITEN  : EOC iterrupt enable
  * @param   NewState specifies the state of the interrupt to apply.
  * @retval None
  */
void ADC1_ITConfig(ADC1_IT_TypeDef ADC1_IT, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_ADC1_IT_OK(ADC1_IT));
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));
  
  if (NewState != DISABLE)
  {
    /* Enable the ADC1 interrupts */
    ADC1->CSR |= (uint8_t)ADC1_IT;
  }
  else  /* NewState == DISABLE */
  {
    /* Disable the ADC1 interrupts */
    ADC1->CSR &= (uint8_t)((uint16_t)~(uint16_t)ADC1_IT);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
