
/**
  ********************************************************************************
  * @file    stm8s_adc1_ClearITPendingBit.c
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
  * @brief  Clear the ADC1 End of Conversion pending bit.
  * @param   ITPendingBit : the IT pending bit to clear.
  * This parameter can be one of the following values:
  *    - ADC1_IT_AWD   : Analog WDG IT status
  *    - ADC1_IT_AWS0 : Analog channel 0 IT status
  *    - ADC1_IT_AWS1 : Analog channel 1 IT status
  *    - ADC1_IT_AWS2 : Analog channel 2 IT status
  *    - ADC1_IT_AWS3 : Analog channel 3 IT status
  *    - ADC1_IT_AWS4 : Analog channel 4 IT status
  *    - ADC1_IT_AWS5 : Analog channel 5 IT status
  *    - ADC1_IT_AWS6 : Analog channel 6 IT status
  *    - ADC1_IT_AWS7 : Analog channel 7 IT status
  *    - ADC1_IT_AWS8 : Analog channel 8 IT status
  *    - ADC1_IT_AWS9 : Analog channel 9 IT status
  *    - ADC1_IT_EOC  : EOC pending bit
  * @retval None
  */
void ADC1_ClearITPendingBit(ADC1_IT_TypeDef ITPendingBit)
{
  uint8_t temp = 0;
  
  /* Check the parameters */
  assert_param(IS_ADC1_ITPENDINGBIT_OK(ITPendingBit));
  
  if (((uint16_t)ITPendingBit & 0xF0) == 0x10)
  {
    /* Clear analog watchdog channel status */
    temp = (uint8_t)((uint16_t)ITPendingBit & 0x0F);
    if (temp < 8)
    {
      ADC1->AWSRL &= (uint8_t)~(uint8_t)((uint8_t)1 << temp);
    }
    else
    {
      ADC1->AWSRH &= (uint8_t)~(uint8_t)((uint8_t)1 << (temp - 8));
    }
  }
  else  /* Clear EOC | AWD flag status */
  {
    ADC1->CSR &= (uint8_t)((uint16_t)~(uint16_t)ITPendingBit);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
