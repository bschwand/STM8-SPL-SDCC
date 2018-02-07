
/**
  ********************************************************************************
  * @file    stm8s_tim1_ETRClockMode1Config.c
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
  * @brief  Configures the TIM1 External clock Mode1.
  * @param  TIM1_ExtTRGPrescaler specifies the external Trigger Prescaler.
  *         This parameter can be one of the following values:
  *                       - TIM1_EXTTRGPSC_OFF
  *                       - TIM1_EXTTRGPSC_DIV2
  *                       - TIM1_EXTTRGPSC_DIV4
  *                       - TIM1_EXTTRGPSC_DIV8.
  * @param  TIM1_ExtTRGPolarity specifies the external Trigger Polarity.
  *         This parameter can be one of the following values:
  *                       - TIM1_EXTTRGPOLARITY_INVERTED
  *                       - TIM1_EXTTRGPOLARITY_NONINVERTED
  * @param  ExtTRGFilter specifies the External Trigger Filter.
  *         This parameter must be a value between 0x00 and 0x0F
  * @retval None
  */
void TIM1_ETRClockMode1Config(TIM1_ExtTRGPSC_TypeDef TIM1_ExtTRGPrescaler,
                              TIM1_ExtTRGPolarity_TypeDef TIM1_ExtTRGPolarity,
                              uint8_t ExtTRGFilter)
{
  /* Check the parameters */
  assert_param(IS_TIM1_EXT_PRESCALER_OK(TIM1_ExtTRGPrescaler));
  assert_param(IS_TIM1_EXT_POLARITY_OK(TIM1_ExtTRGPolarity));
  
  /* Configure the ETR Clock source */
  TIM1_ETRConfig(TIM1_ExtTRGPrescaler, TIM1_ExtTRGPolarity, ExtTRGFilter);
  
  /* Select the External clock mode1 & Select the Trigger selection : ETRF */
  TIM1->SMCR = (uint8_t)((uint8_t)(TIM1->SMCR & (uint8_t)(~(uint8_t)(TIM1_SMCR_SMS | TIM1_SMCR_TS )))
                         | (uint8_t)((uint8_t)TIM1_SLAVEMODE_EXTERNAL1 | TIM1_TS_ETRF ));
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
