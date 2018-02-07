
/**
  ********************************************************************************
  * @file    stm8s_tim1_SelectOutputTrigger.c
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
  * @brief  Selects the TIM1 Trigger Output Mode.
  * @param   TIM1_TRGOSource specifies the Trigger Output source.
  * This parameter can be one of the following values
  *                       - TIM1_TRGOSOURCE_RESET
  *                       - TIM1_TRGOSOURCE_ENABLE
  *                       - TIM1_TRGOSOURCE_UPDATE
  *                       - TIM1_TRGOSource_OC1
  *                       - TIM1_TRGOSOURCE_OC1REF
  *                       - TIM1_TRGOSOURCE_OC2REF
  *                       - TIM1_TRGOSOURCE_OC3REF
  * @retval None
  */
void TIM1_SelectOutputTrigger(TIM1_TRGOSource_TypeDef TIM1_TRGOSource)
{
  /* Check the parameters */
  assert_param(IS_TIM1_TRGO_SOURCE_OK(TIM1_TRGOSource));
  
  /* Reset the MMS Bits & Select the TRGO source */
  TIM1->CR2 = (uint8_t)((uint8_t)(TIM1->CR2 & (uint8_t)(~TIM1_CR2_MMS)) | 
                        (uint8_t) TIM1_TRGOSource);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
